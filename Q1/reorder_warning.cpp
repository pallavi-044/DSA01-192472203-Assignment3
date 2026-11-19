#include <iostream>
#include <string>
using namespace std;

class Book {
    int copies;
    string title;

public:
    Book() : title("C++ Programming"), copies(5) {}

    void display() {
        cout << title << " " << copies << '\n';
    }
};

int main() {
    Book b;
    b.display();
    return 0;
}