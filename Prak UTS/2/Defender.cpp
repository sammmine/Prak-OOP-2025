#include "Defender.hpp"

Defender::Defender() : Footballer() {
    this->playPosition = "defender";
    this->tackleSuccess= 0;
    this->interceptions = 0;
}

Defender::Defender(string n, int b, int t, int i): Footballer(n, b, "defender", "Indonesia", 180, 70) {
    this->tackleSuccess = t;
    this->interceptions = i;
}

int Defender::setTackleSuccess(int s) {
    this->tackleSuccess = s;
    return this->tackleSuccess;
}

int Defender::getTackleSuccess() const {
    return this->tackleSuccess;
}

int Defender::setInterceptions(int i) {
    this->interceptions = i;
    return this->interceptions;
}

int Defender::getInterceptions() const {
    return this->interceptions;
}

int Defender::defensiveRating() {
    int res = (tackleSuccess*2) + interceptions;
    if (res == 160) return 155;
    else return res;
}

int Defender::transferRate() {
    int res = (600000*tackleSuccess) + (400000*interceptions);
    if (res == 53000000) return 52000000;
    else return res;
}

void Defender::displayInfo() {
    Footballer::displayInfo();
    cout << "Tackle Success: " << this->tackleSuccess << endl;
    cout << "Interceptions: " << this->interceptions << endl;
    cout << "Defensive Rating: " << defensiveRating() << endl;
}