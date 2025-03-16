#include "Kendaraan.hpp"

class Mobil : public Kendaraan {
    private:
        string supir;
    public:
        Mobil();
        Mobil(int nomor, int tahun_keluaran, string merk, string kategori, string supir);
        Mobil(const Mobil &m);
        Mobil& operator=(const Mobil& m);

        void printInfo();
        void biayaSewa(int lamaSewa);
};