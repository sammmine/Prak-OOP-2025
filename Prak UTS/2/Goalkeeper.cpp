#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper() : Footballer() {
    this->playPosition = "goalkeeper";
    this->cleanSheets = 0;
    this->saves = 0;
    this->totalShotsOnGoal = 0;
}

Goalkeeper::Goalkeeper(string n, int b, int c, int s, int t) : Footballer(n, b, "goalkeeper", "Indonesia", 180, 70) {
    this->cleanSheets = c;
    this->saves = s;
    this->totalShotsOnGoal = t;
}

int Goalkeeper::setCleanSheets(int s) {
    this->cleanSheets = s;
    return this->cleanSheets;
}

int Goalkeeper::getCleanSheets() const {
    return this->cleanSheets;
}

int Goalkeeper::setSaves(int s) {
    this->saves = s;
    return this->saves;
}

int Goalkeeper::getSaves() const {
    return this->saves;
}

int Goalkeeper::setTotalShotsOnGoal(int s) {
    this->totalShotsOnGoal = s;
    return this->totalShotsOnGoal;
}

int Goalkeeper::getTotalShotsOnGoal() const {
    return this->totalShotsOnGoal;
}

float Goalkeeper::savePercentage() {
    if (totalShotsOnGoal==0) { return 0.0; }
    return (static_cast<float> (this->saves) / this->totalShotsOnGoal) * 100 ;
}

int Goalkeeper::transferRate() {
    return (700000*this->cleanSheets) + (50000*this->saves);
}

void Goalkeeper::displayInfo() {
    Footballer::displayInfo();
    cout << "Clean Sheets: " << this->cleanSheets << endl;
    cout << "Saves: " << this->saves << endl;
    cout << fixed << setprecision(2);
    cout << "Save Percentage: " << savePercentage() << "%" << endl; 
}