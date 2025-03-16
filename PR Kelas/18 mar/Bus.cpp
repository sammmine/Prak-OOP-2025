#include "Bus.hpp"

Bus::Bus() : Kendaraan() {
    this->kategori="bus";
    this->kapasitas=0;
}

Bus::Bus(int nomor, int tahun_keluaran, string merk, string kategori="bus", int kapasitas) : Kendaraan(nomor, tahun_keluaran, merk, kategori) {
    this->kapasitas=kapasitas;    
}

Bus::Bus(const Bus &b) : Kendaraan(b) {
    this->kapasitas=b.kapasitas;
}

Bus& Bus::operator=(const Bus& b) {
    if (this != &b) {
        this->nomor=b.nomor;
        this->tahun_keluaran=b.tahun_keluaran;
        this->merk=b.merk;
        this->kategori=b.kategori;
        this->kapasitas=b.kapasitas;
    }
    return *this;
}

void Bus::printInfo() {
    Kendaraan::printInfo();
    cout << "Kapasitas: " << this->kapasitas << endl;
}

void Bus::biayaSewa(int lamaSewa) {
    int hargaSewa=1000000*lamaSewa;
    cout << "Biaya sewa kendaraan ini adalah: " << hargaSewa << endl;
}