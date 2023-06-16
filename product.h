//
// Created by bieni on 16.06.2023.
//

#ifndef UNTITLED_PRODUCT_H
#define UNTITLED_PRODUCT_H
#include <string>
using namespace std;

class product {
public:
    product(string name,int price);
    string getProductName();
    int getProductPrice();
private:
    string name;
    int price;

};


#endif //UNTITLED_PRODUCT_H
