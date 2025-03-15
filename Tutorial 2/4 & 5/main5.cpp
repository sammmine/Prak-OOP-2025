#include "WaterPokemon.hpp"
#include "FirePokemon.hpp"
#include "GrassPokemon.hpp"
#include "Pokemon.hpp"
#include <iostream>
using namespace std;

int main() {
    FirePokemon *f1 = new FirePokemon("Charmander");
    FirePokemon *f2 = new FirePokemon(*f1);
    WaterPokemon *w1 = new WaterPokemon("Squirtle",100,20,10);

    w1->heal(10);

    WaterPokemon w2("Magikarp");

    w2 = *w1;
    w1->attack(*f1);
    w1->attack(*f1);

    delete f1;
    
    return 0;

    // Penjelasan destructor:
    
    // Pointer disimpan di heap, sementara object disimpan di stack
    // Yang di heap: f1, f2, w1
    // Yang di stack: w2

    // Sebelum main selesai, f1 didelete secara manual, sehingga destructor Charmander dipanggil
    // (Makanya ada output destruct pertama adalah "Charmander has run away")
    
    // Setelah main selesai, stack akan membersihkan dirinya sendiri
    // w2 akan dihapus secara otomatis, sehingga destructor Magikarp dipanggil

    // f2 dan w1 tidak didestruct, masih ada di heap
}

// Charmander is born
// Charmander is born with type: fire | HP: 100 | ATT: 20 | attack count: 0

// Charmander is copied
// Charmander (copy) is born with type: fire | HP: 100 | ATT: 20 | attack count: 0

// Squirtle is born
// Squirtle is born with type: water | HP: 100 | ATT: 20 | attack boost: 10
// Squirtle heals 10 points | HP: 110

// Magikarp is born
// Magikarp is born with type: water | HP: 100 | ATT: 20 | attack boost: 0

// Squirtle is assigned with type: water | HP: 110 | ATT: 20 | attack boost: 10

// Squirtle used Water Gun on Charmander for 40 damage and it's super effective!
// Charmander took 40 damage and now has 60 HP
// Squirtle's Flow State increases! Current damage: 30

// Squirtle used Water Gun on Charmander for 60 damage and it's super effective!
// Charmander took 60 damage and now has 0 HP
// Charmander has fainted
// Squirtle's Flow State increases! Current damage: 40

// Charmander has run away
// Squirtle has run away