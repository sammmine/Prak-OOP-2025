#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    Dragon d("Draco"); 
    d.speak(); 
    d.wound();
    d.wound();
    d.print(); 

    Creature *dRef = &d; // Polymorphism (banyak bentuk) -> untuk merujuk ke objek dari kelas turunan,
                         // tetapi pemanggilan fungsi virtual akan mengeksekusi metode yg sesuai dengan tipe aktual objek,
                         // bukan tipe referensinya.
    dRef->speak(); // harus virtual, gak bisa d.speak();
    dRef->wound();
    dRef->print(); 
    d.print(); 

    Creature dPure = d; // Slicing -> masalah yang terjadi ketika objek kelas turunan ditugaskan ke kelas dasar
                        // akibatnya adalah bagian spesifik dari kelas turunan terpotong
                        // dan hanya bisa mengakses bagian kelas dasar.
                        // Di sini, dPure menjadi instance murni, sehingga ia hanya memiliki properti dan metode Creature.
    dPure.speak(); 
    dPure.wound(); // gak bisa dRef->wound()
    dPure.print(); // gak bisa dRef->print()
    d.print(); 

    return 0;
}

// Output:
    // A creature has been born!
    // A dragon has been born!
    // I am the mighty dragon Draco! Beware of my flames!
    // Base Health: 100; Additional Health: 80
    // I am the mighty dragon Draco! Beware of my flames!
    // Base Health: 90
    // Base Health: 90; Additional Health: 80
    // I am a mystical creature named Draco!
    // Base Health: 80
    // Base Health: 90; Additional Health: 80