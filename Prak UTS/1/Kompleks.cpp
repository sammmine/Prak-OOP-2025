#include "Kompleks.hpp"
#include "math.h"

Kompleks::Kompleks() : real(0), imag(0) {}

Kompleks::Kompleks(double r, double i) : real(r), imag(i) {}

Kompleks::Kompleks(const Kompleks& other) {
    this->real = other.real;
    this->imag = other.imag;
}

double Kompleks::getReal() const { return this->real; }

double Kompleks::getImag() const { return this->imag; }

double Kompleks::setReal(double r) {
    this->real = r;
    return this->real;
}

double Kompleks::setImag(double i) {
    this->imag = i;
    return this->imag;
}

Kompleks Kompleks::operator+(const Kompleks& other) const {
    return Kompleks(this->real+other.real, this->imag+other.imag);
}

Kompleks Kompleks::operator-(const Kompleks& other) const {
    return Kompleks(this->real-other.real, this->imag-other.imag);
}

Kompleks Kompleks::operator*(const Kompleks& other) const {
    return Kompleks(((this->real*other.real)-(this->imag*other.imag)), ((this->imag*other.real)+(this->real*other.imag)));
}

bool Kompleks::operator==(const Kompleks& other) const {
    if (this->real == other.real && this->imag == other.imag) { return true; }
    return false;
}

Kompleks& Kompleks::operator=(const Kompleks& other) {
    if (this == &other) return *this;
    this->real = other.real;
    this->imag = other.imag;
    return *this;
}

ostream& operator<<(ostream& os, const Kompleks& c) {
    if (c.imag == 0) {
        os << c.real;
    } else {
        if (c.imag < 0) {
            os << c.real << " - " << abs(c.imag) << "i";
        } else {
            os << c.real << " + " << c.imag << "i";
        }
    }
    return os;
}

// int main() {
//     Kompleks a;
//     Kompleks b(3,2);
//     Kompleks c(b);

//     a.setReal(1);
//     a.setImag(1);

//     if (a == b) { cout << "sama" << endl; }
//     else { cout << "ga sama" << endl; }

//     cout << a+c << endl;
//     cout << a-c << endl;
//     cout << a*c << endl;
// }