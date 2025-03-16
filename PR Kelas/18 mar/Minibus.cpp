#include "Minibus.hpp"

Minibus::Minibus() : Kendaraan() {
    this->kategori="minibus";
}

Minibus::Minibus(int nomor, int tahun_keluaran, string merk, string kategori="minibus") : Kendaraan(nomor, tahun_keluaran, merk, kategori) {}

Minibus::Minibus(const Minibus &n) {
    this->nomor=n.nomor;
    this->tahun_keluaran=n.tahun_keluaran;
    this->merk=n.merk;
    this->kategori=n.kategori;
}

Minibus& Minibus::operator=(const Minibus& n) {
    if (this != &n) {
        this->nomor=n.nomor;
        this->tahun_keluaran=n.tahun_keluaran;
        this->merk=n.merk;
        this->kategori=n.kategori;
    }
    return *this;
}

void Minibus::printInfo() {
    Kendaraan::printInfo();
}

int Minibus::biayaSewa(int lamaSewa){
    int hargaSewa=0;
    if (lamaSewa <= 5) {
        hargaSewa=5000000;
    } else {
        hargaSewa=5000000+500000*(lamaSewa-5);
    }
    return hargaSewa;
}

void Minibus::diskon(int lamaSewa) {
    int hargaSewa = biayaSewa(lamaSewa);
    if (lamaSewa > 10) {
        hargaSewa = 0.9*hargaSewa;
    }
    cout << "Setelah diskon, biaya sewa kendaraan ini adalah: " << hargaSewa << endl;
}