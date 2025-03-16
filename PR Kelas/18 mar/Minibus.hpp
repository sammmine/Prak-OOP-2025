#include "Kendaraan.hpp"

class Minibus : public Kendaraan {
    public:
        Minibus();
        Minibus(int nomor, int tahun_keluaran, string merk, string kategori);
        Minibus(const Minibus &n);
        Minibus& operator=(const Minibus& n);

        void printInfo();
        int biayaSewa(int lamaSewa);
        void diskon(int lamaSewa);
};