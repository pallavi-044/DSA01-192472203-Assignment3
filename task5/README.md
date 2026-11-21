
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
private:
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    // Prefix increment
    Time& operator++() {
        ++seconds;
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        seconds++;
        return old;
    }

    // Equality operator
    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    // Less than operator
    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        cout << seconds / 3600 << ":"
             << (seconds / 60) % 60 << ":"
             << seconds % 60 << endl;
    }

    int value() const {
        return seconds;
    }
};

class Playlist {
private:
    string tracks[3];

public:
    Playlist() {
        tracks[0] = "Song One";
        tracks[1] = "Song Two";
        tracks[2] = "Song Three";
    }

    // Non-const subscript
    string& operator[](int i) {
        if (i < 0 || i >= 3)
            throw out_of_range("Invalid index");

        return tracks[i];
    }

    // Const subscript
    const string& operator[](int i) const {
        if (i < 0 || i >= 3)
            throw out_of_range("Invalid index");

        return tracks[i];
    }
};

int main() {
    Time t(5);

    Time a = t++;
    Time b = ++t;

    cout << "Postfix value: " << a.value() << endl;
    cout << "Prefix value: " << b.value() << endl;
    cout << "Current time: ";
    t.display();

    Playlist p;

    cout << "Track 1: " << p[0] << endl;
    cout << "Track 2: " << p[1] << endl;

    return 0;
}
