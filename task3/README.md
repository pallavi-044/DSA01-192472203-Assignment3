

#include <iostream>
using namespace std;

class Auditorium {
private:
    int rows, seats;
    char** seatMap;
    int booked;

public:
    // Dynamic constructor
    Auditorium(int r, int s)
        : rows(r), seats(s), seatMap(nullptr), booked(0) {

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++) {
                    seatMap[i][j] = 'O';
                }
            }
        }

        cout << "Auditorium created" << endl;
    }

    // Book a seat
    void book(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'O') {

            seatMap[r][s] = 'B';
            booked++;

            cout << "Seat booked" << endl;
        }
        else {
            cout << "Booking failed" << endl;
        }
    }

    // Cancel a seat
    void cancel(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'B') {

            seatMap[r][s] = 'O';
            booked--;

            cout << "Booking cancelled" << endl;
        }
        else {
            cout << "Cancellation failed" << endl;
        }
    }

    void display() {
        cout << "Booked seats: " << booked << endl;
    }

    // Destructor
    ~Auditorium() {
        if (seatMap != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] seatMap[i];
            }

            delete[] seatMap;
        }

        cout << "Auditorium closed" << endl;
        cout << "Total booked seats: " << booked << endl;
    }
};

int main() {
    cout << "Stack object:" << endl;

    Auditorium a(2, 3);

    a.book(0, 0);
    a.book(1, 1);
    a.display();

    cout << "\nHeap object:" << endl;

    Auditorium* b = new Auditorium(2, 2);

    b->book(0, 1);
    b->display();

    delete b;

    cout << "\nBlock object:" << endl;

    {
        Auditorium c(1, 2);
        c.book(0, 0);
    }

    cout << "Program ended" << endl;

    return 0;
}
