#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    Dragon d("Draco"); // A creature has been born! // A dragon has been born!
    d.speak(); // I am the mighty dragon Draco! Beware of my flames!
    d.wound();
    d.wound();
    d.print(); // Base Health: 100; Additional Health: 80
    d.speak(); // I am the mighty dragon Draco! Beware of my flames!

    Creature &dRef = d;
    dRef.wound();
    dRef.print(); // Base Health: 90
    d.print(); // Base Health: 90; Additional Health: 80

    Creature dRefRef = dRef;
    dRefRef.speak(); // I am a mystical creature named Draco!
    dRef.wound();
    dRef.print(); // Base Health: 80
    d.print(); // Base Health: 90; Additional Health: 80

    return 0;
}