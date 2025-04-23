#include "Midfielder.hpp"

Midfielder::Midfielder() : Footballer() {
    this->playPosition = "midfielder";
    this->assist = 0;
    this->keyPasses = 0;
}

Midfielder::Midfielder(string n, int b, int a, int k) : Footballer(n, b, "midfielder", "Indonesia", 180, 70) {
    this->assist = a;
    this->keyPasses = k;
}

int Midfielder::setAssist(int a) {
    this->assist = a;
    return this->assist;
}

int Midfielder::getAssist() {
    return this->assist;
}

int Midfielder::setKeyPasses(int k) {
    this->keyPasses = k;
    return this->keyPasses;
}

int Midfielder::getKeyPasses() {
    return this->keyPasses;
}

int Midfielder::playmakerRating() {
    return (assist*3) + keyPasses ;
}

int Midfielder::transferRate() {
    return (800000*assist) + (30000*keyPasses) ;
}

void Midfielder::displayInfo() {
    Footballer::displayInfo();
    cout << "Assists: " << this->assist << endl;
    cout << "Key Passes: " << this->keyPasses << endl;
    cout << "Playmaker Rating: " << playmakerRating() << endl;
}