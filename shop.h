//
// Created by bieni on 12.06.2023.
//

#ifndef UNTITLED_SHOP_H
#define UNTITLED_SHOP_H
#include <vector>
#include <iostream>
#include <string>
#include "client.h"
#include <fstream>
#include <sstream>
#include <ostream>
using namespace std;
class shop {
public:
    void addUser(string firstName, string lastName, string address, string gender);
    void modifyUser(int index,string firstName, string lastName, string address, string gender);
    void saveToText(vector<client> user);
    void saveToBinText(vector<client>user);
    void menu();

private:
    vector<client> user;
};


#endif //UNTITLED_SHOP_H
