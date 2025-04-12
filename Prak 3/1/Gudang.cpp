#include "Gudang.hpp"
#include "BarangMakanan.hpp"
#include "BarangElektronik.hpp"
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

void Gudang::simpanBarang(Barang *barang) {
    try {
        if (dynamic_cast<BarangMakanan *>(barang) != nullptr) {
            BarangMakanan *makanan = dynamic_cast<BarangMakanan *>(barang);
            if (makanan->getHariKedaluwarsa() <= 0) {
                throw BarangKedaluwarsaException();
            }
        }

        pakaiKapasitas(barang->getBerat());
        pakaiUang(100);
        pakaiTenagaKerja();

        daftarBarang.push_back(barang);
        cout << "Barang [" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;

    } catch (BarangKedaluwarsaException e) {
        cout << e.what() << ", buang dulu." << endl;
    } catch (KapasitasPenuhException e) {
        cout << e.what() << ", perluas gudang dulu." << endl;
    } catch (UangTidakCukupException e) {
        cout << e.what() << ", cari pemasukan dulu." << endl;
        tambahKapasitas(barang->getBerat());
    } catch (TenagaKerjaTidakCukupException e) {
        cout << e.what() << ", rekrut dulu." << endl;
        tambahKapasitas(barang->getBerat());
        tambahUang(100);
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
    try {
        cout << daftarBarang[idx]->getNama() << " - " << daftarBarang[idx]->getJenis() << " - " << daftarBarang[idx]->getBerat() << "kg" << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void Gudang::statusGudang() const {
    cout << "Status gudang:" << endl;
    cout << "Kapasitas total: " << this->kapasitasTotal << " kg" << endl;
    cout << "Kapasitas terpakai: " << this->kapasitasTerpakai << " kg" << endl;
    cout << "Uang: " << this->uang << endl;
    cout << "Tenaga kerja: " << this->tenagaKerja << endl;
    cout << "Barang:" << endl;
    for (int i=0; i<daftarBarang.size(); i++) {
        cout << "[" << i << "] " << daftarBarang[i]->getNama() << " - " << daftarBarang[i]->getJenis() << " - " << daftarBarang[i]->getBerat() << "kg" << endl;
    }
}

