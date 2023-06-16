//
// Created by bieni on 16.06.2023.
//

#include "product.h"

product::product(string name, int price) {
this->name=name;
this->price= price;
}

string product::getProductName() {
    return name;
}

int product::getProductPrice() {
    return price;
}
