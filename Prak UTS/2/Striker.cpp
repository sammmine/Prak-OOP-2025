#include "Striker.hpp"

Striker::Striker() : Footballer() {
    this->playPosition = "striker";
    this->goalScore = 0;
    this->shotsOnTarget = 0;
}

Striker::Striker(string n, int b, int g, int s) : Footballer(n, b, "striker", "Indonesia", 180, 70) {
    this->goalScore = g;
    this->shotsOnTarget = s;
}

int Striker::setGoalScore(int g) {
    this->goalScore = g;
    return this->goalScore;
}

int Striker::getGoalScore() { return this->goalScore; }

int Striker::setShotsOnTarget(int s) {
    this->shotsOnTarget = s;
    return this->shotsOnTarget;
}

int Striker::getShotsOnTarget() { return this->shotsOnTarget; }

float Striker::conversionRate() {
    if (shotsOnTarget == 0) return 0.0f; // hindari division by zero
    return (static_cast<float>(goalScore) / shotsOnTarget) * 100.0f;
}

int Striker::transferRate() {
    return static_cast<int>(1000000 * this->goalScore + 10000 * conversionRate());
}

void Striker::displayInfo() {
    Footballer::displayInfo();
    cout << "Goals: " << getGoalScore() << endl;
    cout << "Conversion Rate: " << fixed << setprecision(2) << conversionRate() << "%" << endl;
}