#include "Kendaraan.hpp"
#include <iostream>
using namespace std;

Kendaraan::Kendaraan(){
    this->nomor=0;
    this->tahun_keluaran=0;
    this->merk="XXX";
    this->kategori="kendaraan";
}

Kendaraan::Kendaraan(int nomor, int tahun_keluaran, string merk, string kategori){
    this->nomor=nomor;
    this->tahun_keluaran=tahun_keluaran;
    this->merk=merk;
    this->kategori=kategori;
}

Kendaraan::Kendaraan(const Kendaraan &k){
    this->nomor=k.nomor;
    this->tahun_keluaran=k.tahun_keluaran;
    this->merk=k.merk;
    this->kategori=k.kategori;
}

Kendaraan& Kendaraan::operator=(const Kendaraan& k){
    if (this != &k) {
        this->nomor=k.nomor;
        this->tahun_keluaran=k.tahun_keluaran;
        this->merk=k.merk;
        this->kategori=k.kategori;
    }
    return *this;
}

Kendaraan::~Kendaraan(){}

void Kendaraan::printInfo(){
    cout << "Nomor Kendaraan: " << this->nomor << endl;
    cout << "Tahun Keluaran: " << this->tahun_keluaran << endl;
    cout << "Merk Kendaraan: " << this->merk << endl;
    cout << "Kategori Kendaraan: " << this->kategori << endl;
}

void Kendaraan::biayaSewa(int lamaSewa){
    int hargaSewa=0;
    if (this->kategori=="bus") {
        hargaSewa=1000000*lamaSewa;
    } else if (this->kategori=="minibus") {
        if (lamaSewa <= 5) {
            hargaSewa=5000000;
        } else {
            hargaSewa=5000000+500000*(lamaSewa-5);
        }
    } else if (this->kategori=="mobil") {
        hargaSewa=500000*lamaSewa;
    }
    cout << "Biaya sewa kendaraan ini adalah: " << hargaSewa << endl;
}