#include <iostream>
#include <math.h> // untuk fungsi mutlak/absolut
using namespace std;

template<class A, class B>
class KeyValue {
    private:
        A keys[10];
        B values[10];
        int nEff; // maksimum adalah 10
    public:
        KeyValue() : nEff(0) {}
        ~KeyValue() {}
        void set (A key, B value) {
            if (nEff==10) {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            } else {
                for (int i=0; i<nEff ; i++) { // Mencari kalau sudah ada key yang sama
                    if (keys[i] == key) {
                        values[i] = value;
                        return;
                    }
                }
                // Tambah key-value baru
                keys[nEff] = key;
                values[nEff] = value;
                nEff++;
            }
        }
        void display (A key) {
            for (int i=0; i<nEff; i++) {
                if (keys[i]==key) {
                    cout << values[i] << endl;
                    return;
                }
            }
            cout << "Key tidak ditemukan!" << endl;
        }
};

// Case keys bertipe double
template<class B>
class KeyValue <double, B> {
    private:
        double keys[10];
        B values[10];
        int nEff;
    public:
        KeyValue() : nEff(0) {}
        ~KeyValue() {}
        void set (double key, B value) {
            if (nEff==10) {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            } else {
                for (int i=0; i<nEff ; i++) { // Mencari kalau sudah ada key yang sama
                    if (abs(keys[i]-key) < 0.01) { // Selisih harus kurang dari 0.01
                        values[i] = value;
                        return;
                    }
                }
                // Tambah key-value baru
                keys[nEff] = key;
                values[nEff] = value;
                nEff++;
            }
        }
        void display (double key) {
            for (int i=0; i<nEff; i++) {
                if (abs(keys[i]-key) < 0.01) { // Selisih harus kurang dari 0.01
                    cout << values[i] << endl;
                    return;
                }
            }
            cout << "Key tidak ditemukan!" << endl;
        }
};

