#include "SpacingGuildShip.hpp"
using namespace std;

int SpacingGuildShip::producedShips=0;
float SpacingGuildShip::totalGuildTravel=0;

SpacingGuildShip::SpacingGuildShip() : guildNavigatorCount(3), maxPassengerCap(50), serialNum(producedShips+1) {
    this->passengerCount=0;
    this->spiceStock = 50;
    this->operatingGuildNavigator=3;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : guildNavigatorCount(guildNavigatorCount), maxPassengerCap(maxPassengerCap), serialNum(producedShips+1) {
    this->passengerCount=0;
    this->spiceStock = spiceStock;
    this->operatingGuildNavigator=guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& s) : guildNavigatorCount(s.guildNavigatorCount), maxPassengerCap(s.maxPassengerCap), serialNum(producedShips+1){
    this->passengerCount=s.passengerCount;
    this->spiceStock = s.spiceStock;
    this->operatingGuildNavigator=s.operatingGuildNavigator;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip() {}

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance) {
    if (this->operatingGuildNavigator > 0) {
        totalGuildTravel += distance / (E*E*operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers) {
    if (addedPassengers > this->maxPassengerCap) {
        this->passengerCount = this->maxPassengerCap;
    } else {
        this->passengerCount += addedPassengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers) {
    if (droppedPassengers > this->passengerCount) {
        this->passengerCount = 0;
    } else {
        this->passengerCount -= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n) {
    if(spiceStock - n*GUILD_NAVIGATOR_SPICE_DOSE >= 0){
        operatingGuildNavigator += n;
        spiceStock -= n*GUILD_NAVIGATOR_SPICE_DOSE;
    } else {
        operatingGuildNavigator += spiceStock/GUILD_NAVIGATOR_SPICE_DOSE;
        spiceStock = spiceStock % GUILD_NAVIGATOR_SPICE_DOSE;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    this->spiceStock += addedSpice;
}