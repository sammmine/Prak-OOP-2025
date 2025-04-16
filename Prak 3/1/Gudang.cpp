#include "Gudang.hpp"
#include "BarangElektronik.hpp"
#include "BarangMakanan.hpp"
#include "Barang.hpp"
#include <bits/stdc++.h>
#include "Exception.hpp"
#include <exception>

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
}

void Gudang::simpanBarang(Barang *barang) {
    if (barang->getJenis() == "Makanan") {
        BarangMakanan* cur = dynamic_cast<BarangMakanan*>(barang);
        try {
            if (cur->getHariKedaluwarsa() <= 0) {
                throw BarangKedaluwarsaException();
            }
            pakaiKapasitas(cur->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(cur);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << cur->getNama() << " berhasil disimpan" << endl;
        }
        catch (BarangKedaluwarsaException e) {
            cout << e.what() << ", buang dulu." << endl;
        }
        catch (KapasitasPenuhException e) {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (UangTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (TenagaKerjaTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
    else {
        BarangElektronik* cur = dynamic_cast<BarangElektronik*>(barang);
        try {
            pakaiKapasitas(cur->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(cur);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << cur->getNama() << " berhasil disimpan" << endl;
        }
        catch (KapasitasPenuhException e) {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (UangTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (TenagaKerjaTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
}

void Gudang::tambahKapasitas(int kg) {
    this->kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah) {
    this->tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah) {
    this->uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg) {
    if (kapasitasTerpakai + kg > kapasitasTotal) {
        throw KapasitasPenuhException();
    }

    this->kapasitasTerpakai += kg;
}

void Gudang::pakaiUang(int jumlah) {
    if (uang - jumlah < 0) {
        throw UangTidakCukupException();
    }
    uang -= jumlah;
}

void Gudang::pakaiTenagaKerja() {
    if (tenagaKerja <= 0) {
        throw TenagaKerjaTidakCukupException();
    }
    tenagaKerja--;
}

void Gudang::sebutBarang(int i) {
    try {
        Barang* barang = daftarBarang.at(i);
        cout << barang->getNama() << " - " 
             << barang->getJenis() << " - " 
             << barang->getBerat() << "kg" << endl;
    }
    catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
}

void Gudang::statusGudang() const {
    cout << "Status gudang:\n";
    cout << "  Kapasitas total: " << kapasitasTotal << " kg\n";
    cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg\n";
    cout << "  Uang: " << uang << "\n";
    cout << "  Tenaga kerja: " << tenagaKerja << "\n";
    cout << "  Barang:\n";

    for (int i = 0; i < daftarBarang.size(); i++) {
        cout << "    [" << i << "] " << daftarBarang[i]->getNama() << " - " << daftarBarang[i]->getJenis() << " - " << daftarBarang[i]->getBerat() << "kg" << endl;
    }
}