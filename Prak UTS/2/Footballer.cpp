#include "Footballer.hpp"

Footballer::Footballer() : name("noname"), birthYear(2000), playPosition("none"), nationality("Indonesia"), height(180), weight(70) {} 

Footballer::Footballer(string n, int b, string p, string nat, int h, int w) : name(n), birthYear(b), playPosition(p), nationality(nat), height(h), weight(w) {}

Footballer::Footballer(const Footballer& f) {
    this->name = f.name;
    this->birthYear = f.birthYear;
    this->playPosition = f.playPosition;
    this->nationality = f.nationality;
    this->height = f.height;
    this->weight = f.weight;
}

Footballer::~Footballer() {}

Footballer& Footballer::operator=(const Footballer& f) {
    if (this == &f) { return *this; }
    this->name = f.name;
    this->birthYear = f.birthYear;
    this->playPosition = f.playPosition;
    this->nationality = f.nationality;
    this->height = f.height;
    this->weight = f.weight;
    return *this;
}

string Footballer::setName(string n) {
    this->name = n;
    return this->name;
}
string Footballer::getName() const {
    return this->name;
}

string Footballer::setPlayPosition(string p) {
    this->playPosition = p;
    return this->playPosition;
}
string Footballer::getPlayPosition() const {
    return this->playPosition;
}

string Footballer::setNationality(string nat) {
    this->nationality = nat;
    return this->nationality;
}
string Footballer::getNationality() const {
    return this->nationality;
}

int Footballer::setHeight(int h) {
    this->height = h;
    return this->height;
}
int Footballer::getHeight() const {
    return this->height;
}
int Footballer::setWeight(int w) {
    this->weight = w;
    return this->weight;
}
int Footballer::getWeight() const {
    return this->weight;
}

int Footballer::getAge() const {
    return CURRENT_YEAR-this->birthYear;
}

double Footballer::getBMI() const {
    double w = this->weight;
    double h = this->height;
    return w / (h*h*0.0001) ;
}

string Footballer::getCategory() const {
    double bmi = getBMI();
    if (bmi < 18.5) return "Underweight";
    if (bmi >= 18.5 && bmi < 25.0) return "Normal";
    if (bmi >= 25.0 && bmi < 30.0) return "Overweight";
    return "Obese";
}

void Footballer::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << playPosition << endl;
    cout << "Nationality: " << nationality << endl;
    cout << fixed << setprecision(2);
    cout << "BMI: " << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl;
}

int Footballer::transferRate() const {
    return 200;
}

// int main() {
//     Footballer f;

//     f.setName("WAYOLO");
//     f.setNationality("dubidubidam");
//     f.setPlayPosition("^__^");
//     // f.setHeight(3);
//     // f.setWeight(1);

//     f.displayInfo();
// }