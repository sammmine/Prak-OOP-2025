#include "funcTemp.cpp"

int main() {
    // Nomor 1
    // Buatlah program utama untuk mengetes fungsi MinArray
    // dengan masukan elemen array integer, real.
    int arrInt[5] = {3,6,1,-2,4};
    double arrReal[5] = {7,4.5,9,11,2.1};
    MinArray(arrInt, 5);
    MinArray(arrReal, 5);

    // Nomor 1
    // Didefinisikan kelas Jam HH:MM:SS. Apakah mungkin MinArray
    // digunakan untuk data bertype Jam?
    Jam arrJam[3] = {Jam(12,3,13), Jam(4,0,0), Jam(9,50,50)};
    MinArray(arrJam, 3);

    // Nomor 2
    // Buatlah program utama untuk mengetes fungsi PrintArray
    // dengan masukan elemen array of integer, real, dan char.
    PrintArray(arrInt, 5);
    PrintArray(arrReal, 5);
    char arrChar[5] = {'a','z','x','c','^'};
    PrintArray(arrChar, 5);

    // Nomor 2
    // Bagaimana kalau yang ingin dicetak adalah Point?
    Point arrPoint[2] = {Point(3,5), Point(8.8,11)};
    PrintArray(arrPoint, 2);

    return 0;
}