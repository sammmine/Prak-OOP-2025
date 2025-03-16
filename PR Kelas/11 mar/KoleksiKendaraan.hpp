#ifndef KOLEKSIKENDARAAN_H
#define KOLEKSIKENDARAAN_H
#include "Kendaraan.hpp"

class KoleksiKendaraan {
    private:
        int size;
        int neff;
        Kendaraan *arr; // pointer to dynamic array of Kendaraan
    public:
        KoleksiKendaraan();
        KoleksiKendaraan(int size);
        KoleksiKendaraan(const KoleksiKendaraan &k);
        KoleksiKendaraan& operator=(const KoleksiKendaraan& k);
        ~KoleksiKendaraan();

        void printAll();
        KoleksiKendaraan& operator<<(const Kendaraan &k);
        KoleksiKendaraan& operator<<(const KoleksiKendaraan &k);
};


#endif