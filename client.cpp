//
// Created by bieni on 12.06.2023.
//

#include "client.h"

client::client(string firstName, string lastName, string address, string gender) {
this->firstName= firstName;
this->lastName=lastName;
this->address=address;
this->gender=gender;
}
string client::getFirstName() {
    return firstName;
}

string client::getLastName() {
    return lastName;
}

string client::getGender() {
    return gender;
}

string client::getAddress() {
    return address;
}
