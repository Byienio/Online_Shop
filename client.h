//
// Created by bieni on 12.06.2023.
//

#ifndef UNTITLED_CLIENT_H
#define UNTITLED_CLIENT_H

#include <string>
#include <iostream>

using namespace std;

class client {
private:
    string gender;
public:
    string firstName;
    string lastName;
    string address;
    client(string firstName, string lastName, string address, string gender);
    string getClientData();


};


#endif //UNTITLED_CLIENT_H
