
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Constructor with real value
    Complex(double r) : real(r), imag(0) {}

    // Constructor with real and imaginary values
    Complex(double r, double i) : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0) {
            throw runtime_error("Division by zero");
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Display
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    try {
        Complex z1(3, 4);
        Complex z2(2, 1);

        cout << "Z1: " << z1 << endl;
        cout << "Z2: " << z2 << endl;

        cout << "Addition: " << z1 + z2 << endl;
        cout << "Subtraction: " << z1 - z2 << endl;
        cout << "Multiplication: " << z1 * z2 << endl;
        cout << "Division: " << z1 / z2 << endl;

        cout << "Magnitude: " << z1.magnitude() << endl;

        // Series impedance
        Complex series = z1 + z2;
        cout << "Series impedance: " << series << endl;

        // Parallel impedance
        Complex parallel = (z1 * z2) / (z1 + z2);
        cout << "Parallel impedance: " << parallel << endl;

        // Division by zero test
        Complex zero(0, 0);
        cout << z1 / zero << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
