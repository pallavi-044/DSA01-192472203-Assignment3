
#include <iostream>
#include <iomanip>
using namespace std;

class Money {
private:
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // Addition operator
    Money operator+(const Money& m) const {
        Money temp;
        temp.paise = paise + m.paise;
        return temp;
    }

    // Subtraction operator
    Money operator-(const Money& m) const {
        Money temp;
        temp.paise = paise - m.paise;
        return temp;
    }

    // Equality operator
    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    // Less than operator
    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    // Addition assignment
    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;

        if (amount < 0) {
            out << "-Rs ";
            amount = -amount;
        } else {
            out << "Rs ";
        }

        out << amount / 100 << "."
            << setw(2) << setfill('0') << amount % 100
            << setfill(' ');

        return out;
    }

    // Input operator
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;

        in >> rupees >> p;

        if (in) {
            m.paise = rupees * 100 + p;
        }

        return in;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << "Total: " << c << endl;

    cout << boolalpha;
    cout << "Equal: " << (c == Money(200)) << endl;

    Money d(0, 75);
    Money e(0, 50);

    Money f = d + e;

    cout << "Paise addition: " << f << endl;

    Money g(50);
    Money h(80);

    cout << "Subtraction: " << g - h << endl;

    return 0;
}
