#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    explicit Book(const string& title) {
        cout << "Book created: " << title << '\n';
    }
};

int main() {
    Book b = string("Computer Networks");
    return 0;
}