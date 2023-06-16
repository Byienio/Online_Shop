//
// Created by bieni on 12.06.2023.
//

#ifndef UNTITLED_SHOP_H
#define UNTITLED_SHOP_H
#include <vector>
#include <iostream>
#include <string>
#include "client.h"
#include "Order.h"
#include <fstream>
#include <sstream>
#include <ostream>
#include "product.h"
using namespace std;
class shop {
public:
    void addUser(string firstName, string lastName, string address, string gender);
    void modifyUser(int index,string firstName, string lastName, string address, string gender);
    void saveToText(vector<client> user);
    void saveToBinText(vector<client>user);
    void addOrder(string name,int quantity,int price,string paymentMethod);
    void productslist();
    void menu();

private:
    vector<client> user;
    vector<Order> order;
    vector<product> products;
};


#endif //UNTITLED_SHOP_H
