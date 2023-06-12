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

void client::showusers() {
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Delivery Address: " << address << endl;
    cout << "Gender: " << gender << endl;
}
