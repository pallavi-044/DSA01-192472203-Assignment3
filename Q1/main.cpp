#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

    static int validateCopies(int count) {
        if (count < 0) {
            throw invalid_argument("Number of copies cannot be negative");
        }
        return count;
    }

public:
    // Default constructor
    Book() : Book("Untitled", "Unknown", 0) {}

    // Constructor for donated books
    explicit Book(const string& t)
        : Book(t, "Donated", 1) {}

    // Constructor with title and copies
    Book(const string& t, int c)
        : Book(t, "Unknown", c) {}

    // Full parameterised constructor
    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(validateCopies(c)) {}

    void display() const {
        cout << "Title: " << title
             << " | Author: " << author
             << " | Copies: " << copies << '\n';
    }
};

int main() {
    try {
        Book b1;
        Book b2("C++ Programming");
        Book b3("Data Structures", 5);
        Book b4("Artificial Intelligence", "Stuart Russell", 8);

        cout << "LIBRARY BOOK RECORDS\n\n";

        b1.display();
        b2.display();
        b3.display();
        b4.display();

        cout << "\nTesting negative copies:\n";

        Book b5("Invalid Book", "Unknown", -5);
        b5.display();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}