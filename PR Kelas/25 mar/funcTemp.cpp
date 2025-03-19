#include <iostream>
using namespace std;

// Nomor 1

class Jam {
    private:
        int hh;
        int mm;
        int ss;
    public:
        Jam(int h, int m, int s) : hh(h), mm(m), ss(s) {}
        bool operator>(const Jam& j) {
            if (hh != j.hh) {
                return hh > j.hh;
            }
            if (mm != j.mm) {
                return mm > j.mm;
            }
            return ss > j.ss;
        }
};

template <class T>
void MinArray(T arr[], int N) {
    if (N > 0) {
        T min = arr[0];
        for (int i=0; i<N; i++) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }
    }
    cout << "Elemen terkecil: " << min << endl;
}


// Nomor 2

class Point {
    private:
        double x;
        double y;
    public:
        Point(double xx, double yy) : x(xx), y(yy) {}
        friend ostream& operator<<(ostream& os, const Point& p) {
            os << "<" << p.x << "," << p.y << ">";
            return os;
        }
};

template <class T>
void PrintArray(T arr[], int N) {
    if (N == 0) {
        cout << "Array kosong." << endl;
    } else if (N > 0) {
        cout << "[";
        for (int i=0; i<N; i++) {
            cout << arr[i];
            if (i < N-1) {
                cout << ",";
            }
        }
        cout << "]";
    }
}