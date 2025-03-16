#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <string>
using namespace std;

class Kendaraan {
    private:
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

        void printInfo();
        void biayaSewa(int lamaSewa); 
};

#endif