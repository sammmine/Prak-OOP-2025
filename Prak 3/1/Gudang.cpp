#include "Gudang.hpp"
#include "Exception.hpp"
#include <iostream>
using namespace std;

Gudang::Gudang() {
    this->kapasitasTotal = DEFAULT_KAPASITAS;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = DEFAULT_TENAGA_KERJA;
    this->uang = DEFAULT_UANG;
}

Gudang::Gudang(int kapasitas, int uang, int tenagaKerja) {
    this->kapasitasTotal = kapasitas;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = tenagaKerja;
    this->uang = uang;
}

Gudang::~Gudang() {
    delete[] &daftarBarang;
}

void simpanBarang(Barang *barang) {
    try {
        

    } catch (BarangKedaluwarsaException e) {
        cout << e.what() << ", buang dulu." << endl;
    } catch (KapasitasPenuhException e) {
        cout << e.what() << ", perluas gudang dulu." << endl;
    } catch (UangTidakCukupException e) {
        cout << e.what() << ", cari pemasukan dulu." << endl;
    } catch (TenagaKerjaTidakCukupException e) {
        cout << e.what() << ", rekrut dulu." << endl;
    }
}

void Gudang::tambahKapasitas(int kg) {
    kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah) {
    tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah) {
    uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg) {
    if (kapasitasTerpakai + kg > kapasitasTotal) {
        throw KapasitasPenuhException();
    }
    kapasitasTerpakai += kg;
}

void Gudang::pakaiUang(int jumlah) {
    if (uang - jumlah < 0) {
        throw UangTidakCukupException();
    }
    uang -= jumlah;
}

void Gudang::pakaiTenagaKerja() {
    if (tenagaKerja - 1 < 0) {
        throw TenagaKerjaTidakCukupException();
    }
    tenagaKerja--;
}

void Gudang::sebutBarang(int idx) {

}

void Gudang::statusGudang() const {

}

