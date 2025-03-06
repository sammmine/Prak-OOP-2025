#include "Item.hpp"
using namespace std;

int Item::totalRevenue=0;
int Item::totalItems=0;

Item::Item() : serialNum(totalItems+1) {
    this->stock=0;
    this->price=0;
    this->sold=0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems+1) {
    this->stock=stock;
    this->price=price;
    this->sold=0;
    totalItems++;
}

Item::Item(const Item& other) : serialNum(totalItems+1), stock(other.stock), price(other.price), sold(other.sold) {
    // this->stock=stock;
    // this->price=price;
    // this->sold=sold;
    totalItems++;
}

Item::~Item() {}

int Item::getSerialNum() const {
    return this->serialNum;
}

int Item::getSold() const {
    return this->sold;
}

int Item::getPrice() const {
    return this->price;
}

void Item::addStock(int addedStock) {
    if (addedStock > 0) {
        this->stock = this->stock + addedStock;
    }
}

void Item::sell(int soldStock) {
    int itemSold;
    if (soldStock > this->stock) {
        itemSold = this->stock;
    } else {
        itemSold = soldStock;
    }
    this->stock = this->stock - itemSold;
    this->sold = this->sold + itemSold;
    totalRevenue = totalRevenue + (this->price * itemSold);
}

void Item::setPrice(int newPrice) {
    this->price = newPrice;
}