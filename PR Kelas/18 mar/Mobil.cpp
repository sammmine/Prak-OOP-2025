#include "Mobil.hpp"

Mobil::Mobil() : Kendaraan() {
    this->kategori="mobil";
    this->supir = "XXXX";
}

Mobil::Mobil(int nomor, int tahun_keluaran, string merk, string kategori="mobil", string supir) : Kendaraan(nomor, tahun_keluaran, merk, kategori) {
    this->supir=supir;
}

Mobil::Mobil(const Mobil &m) : Kendaraan(m) {
    this->supir=m.supir;
}

Mobil& Mobil::operator=(const Mobil& m) {
    if (this != &m) {
        this->nomor=m.nomor;
        this->tahun_keluaran=m.tahun_keluaran;
        this->merk=m.merk;
        this->kategori=m.kategori;
        this->supir=m.supir;
    }
    return *this;
} 

void Mobil::printInfo() {
    Kendaraan::printInfo();
    cout << "Supir: " << this->supir << endl;
}

void Mobil::biayaSewa(int lamaSewa){
    int hargaSewa=500000*lamaSewa;
    cout << "Biaya sewa kendaraan ini adalah: " << hargaSewa << endl;
}