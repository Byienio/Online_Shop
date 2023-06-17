//
// Created by bieni on 12.06.2023.
//

#include "client.h"

client::client(string firstName, string lastName, string address, string gender) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;
    this->gender = gender;
}

string client::getClientData() {
    string client = firstName + ';' + lastName + ';' + address + ';' + gender;
    return client;
}
