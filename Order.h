//
// Created by bieni on 15.06.2023.
//

#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H
#include <string>
#include <iostream>
using namespace std;

class Order {
private:
    string name;
    int quantity;
    string orderDate;
    int price;
    int totalPrice;
    string paymentMethod;
public:
    Order(string name,int quantity,  string orderDate, int price, string paymentMethod);
    string getOrderData();
};


#endif //UNTITLED_ORDER_H
