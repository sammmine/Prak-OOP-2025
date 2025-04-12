#include "BarangMakanan.hpp"

BarangMakanan::BarangMakanan(string nama, int berat, int hariKedaluwarsa) : Barang(nama,berat) {
    this->hariKedaluwarsa = hariKedaluwarsa;
}

int BarangMakanan::getHariKedaluwarsa() const {
    return this->hariKedaluwarsa;
}

string BarangMakanan::getJenis() const {
    return "Makanan";
}