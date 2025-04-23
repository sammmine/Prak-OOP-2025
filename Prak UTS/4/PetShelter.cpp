#include "PetShelter.hpp"
using namespace std;

template class PetShelter<Pet>;

template <typename T>
PetShelter<T>::PetShelter(string shelterName) {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        pets[i] = nullptr;
    }
    this->shelterName = shelterName;
    dogCapacity = 8;
    catCapacity = 12;
    petCount = 0;
    currentDogs = 0;
    currentCats = 0;
}

template <typename T>
PetShelter<T>::PetShelter(string shelterName, int dogCapacity, int catCapacity) {
    if (dogCapacity + catCapacity > MAX_SHELTER_CAPACITY) {
        cout << "The total capacity you construct is " << dogCapacity + catCapacity << ", meanwhile the shelter capacity is 20" << endl;
    }

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        pets[i] = nullptr; 
    }
    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity; 
    petCount = 0; 
    currentDogs = 0;
    currentCats = 0; 
}

template <typename T>
PetShelter<T>::~PetShelter() {}

template <typename T>
string PetShelter<T>::getShelterName() const {
    return this->shelterName;
}

template <typename T>
void PetShelter<T>::addPet(const string &petName, int age, bool isDog, const string &extraInfo) {
    int dc = dogCapacity;
    int cc = catCapacity;
    int curC = currentCats;
    int curD = currentDogs;
    int cur = petCount;

    if (isDog) {
        Dog* newPets = new Dog(petName, age, extraInfo);
        if (cur >= MAX_SHELTER_CAPACITY) cout << "Error: Shelter is at full capacity!" << endl;
        else if (curD >= dc) cout << "Error: No space for more dogs!" << endl;
        else {
            currentDogs++;
            petCount++;
            newPets->setId("D" + to_string(curD + 1));
            for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
                if (pets[i] == nullptr) {
                    pets[i] = newPets;
                    break;
                }
            }
            cout << "Success: " << petName << " has been added as a Dog! Pet ID: " << newPets->getId() << endl; 
        }
    }
    else {
        Cat* newPets = new Cat(petName, age, extraInfo);
        if (cur >= MAX_SHELTER_CAPACITY) cout << "Error: Shelter is at full capacity!" << endl;
        else if (curC >= cc) cout << "Error: No space for more cats!" << endl;
        else {
            currentCats++;
            petCount++;
            newPets->setId("C" + to_string(curC + 1));
            for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
                if (pets[i] == nullptr) {
                    pets[i] = newPets;
                    break;
                }
            }
            cout << "Success: " << petName << " has been added as a Cat! Pet ID: " << newPets->getId() << endl; 
        }
    }
}

template <typename T>
T* PetShelter<T>::findPet(const string &petID) const {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue;
        if (pets[i]->getId() == petID) {
            pets[i]->displayInfo();
            return dynamic_cast<T*>(pets[i]);
        }
    }
    cout << "Pet ID is invalid!" << endl;
    return nullptr;
}

template <typename T>
void PetShelter<T>::listAllPets() const {
    if (petCount == 0) {
        cout << "No pets in the shelter yet!" << endl;
        return;
    }
    int counter = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue;
        cout << ++counter << ". " ;
        pets[i]->displayInfo();
    }
}

template <typename T>
int PetShelter<T>::calculateCost() const {
    int cost = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue;
        if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
        else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
    }
    return cost;
}

template <typename T>
void PetShelter<T>::removePet(const string &petID) {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue;
        if (pets[i]->getId() == petID) {
            cout << pets[i]->getName() << " has been removed from the shelter." << endl;
            if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
            else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
            petCount--;
            pets[i] = nullptr;
            return;
        }
    }
    cout << "Pet ID is invalid!" << endl;
}