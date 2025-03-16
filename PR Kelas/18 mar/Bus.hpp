#include "Kendaraan.hpp"

class Bus : public Kendaraan {
    private:
        int kapasitas;
    public:
        Bus();
        Bus(int nomor, int tahun_keluaran, string merk, string kategori, int kapasitas);
        Bus(const Bus &b);
        Bus& operator=(const Bus& b);

        void printInfo();
        int biayaSewa(int lamaSewa);
};