//
// Created by bieni on 12.06.2023.
//

#ifndef UNTITLED_SHOP_H
#define UNTITLED_SHOP_H
#include <vector>
#include <iostream>
#include <string>
#include "client.h"
using namespace std;
class shop {
public:
    void addUser(string firstName, string lastName, string address, string gender);
    void modifyUser(int index,string firstName, string lastName, string address, string gender);
    void menu();

private:
    vector<client> user;
};


#endif //UNTITLED_SHOP_H
