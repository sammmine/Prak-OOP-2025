#include <iostream>
using namespace std;

template <class T>
void func(T x, T y){
    cout << "Masukkan Anda: " << x << " dan " << y << ", memiliki tipe yang sama" << endl;
}

template <class T1, class T2>
void func(T1 x, T2 y){
    cout << "Masukkan Anda: " << x << " dan " << y << ", mungkin memiliki tipe yang berbeda" << endl;
}

template <>
void func(char x, int y){
    for (int i=0; i<y; i++){
        cout << x << endl;
    }
}