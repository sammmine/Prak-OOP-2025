#include "KoleksiKendaraan.hpp"
#include <iostream>
using namespace std;

KoleksiKendaraan::KoleksiKendaraan(){
    this->size=100;
    this->neff=0;
    this->arr = new Kendaraan[this->size];
}

KoleksiKendaraan::KoleksiKendaraan(int size){
    this->size=size;
    this->neff=0;
    this->arr = new Kendaraan[this->size];
}

KoleksiKendaraan::KoleksiKendaraan(const KoleksiKendaraan &k){
    this->size=k.size;
    this->neff=k.neff;
    this->arr = new Kendaraan[this->size];
    for (int i=0; i<k.neff; i++) {
        this->arr[i]=k.arr[i];
    }
}

KoleksiKendaraan& KoleksiKendaraan::operator=(const KoleksiKendaraan& k){
    if (this != &k) {
        delete[] this->arr;
        this->size=k.size;
        this->neff=k.neff;
        this->arr = new Kendaraan[this->size];
        for (int i=0; i<k.neff; i++) {
            this->arr[i]=k.arr[i];
        }
    }
    return *this;
}

KoleksiKendaraan::~KoleksiKendaraan() {
    delete[] this->arr;
}

void KoleksiKendaraan::printAll() {
    for (int i=0; i<this->neff; i++) {
        this->arr[i].printInfo();
    }
}

KoleksiKendaraan& KoleksiKendaraan::operator<<(const Kendaraan &k) {
    this->arr[this->neff]=k;
    this->neff++;
    return *this;
}

KoleksiKendaraan& KoleksiKendaraan::operator<<(const KoleksiKendaraan &k) {
    for (int i=0; i<k.neff; i++) {
        if (this->neff < this->size) {
            this->arr[this->neff]=k.arr[i];
            this->neff++;
        }
    }
    return *this;
}