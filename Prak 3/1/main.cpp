#include "Gudang.hpp"
#include "BarangMakanan.hpp"
#include "BarangElektronik.hpp"
#include "Exception.hpp"
#include <iostream>
using namespace std;

int main() {
    BarangMakanan satu("ayam", 10, 5);
    BarangElektronik dua("charger", 10, 100);

    Gudang gudang(40, 100, 5);

    gudang.simpanBarang(&satu);
    gudang.simpanBarang(&dua);

    gudang.statusGudang();
}