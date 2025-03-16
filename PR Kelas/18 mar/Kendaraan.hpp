#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <iostream>
#include <string>
using namespace std;

class Kendaraan {
    protected:
        int nomor;
        int tahun_keluaran;
        string merk;   
        string kategori;   
	public:
		Kendaraan();
        Kendaraan(int nomor, int tahun_keluaran, string merk, string kategori);
        Kendaraan(const Kendaraan &k);
        Kendaraan& operator=(const Kendaraan& k);
        ~Kendaraan();

        virtual void printInfo();
        void biayaSewa(int lamaSewa); 
};

#endif