//
// Created by bieni on 12.06.2023.
//

#include "shop.h"
#include <iostream>


void shop::addUser(string firstName, string lastName, string address, string gender) {
    client newUser(firstName, lastName, address, gender);
    user.push_back(newUser);
    cout << "Dodano nowego uzytkownika" << endl;
    cout << user.size();
}

void shop::modifyUser(int index, string firstName, string lastName, string address, string gender) {
    if (index >= 0 && index <= user.size()) {
        client &moduser = user[index - 1];
        moduser = client(firstName, lastName, address, gender);
    }
}

void shop::menu() {
    shop user1;
    string firstName, lastName, address, gender;
    cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    cout << "Podaj adres: ";
    cin >> address;
    cout << "podaj plec: ";
    cin >> gender;
    addUser(firstName, lastName, address, gender);

    int index;
    cout << "podaj indeks uzytkownika ktorego chcesz edytowac" << endl;
    cin >> index;
    cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    cout << "Podaj adres: ";
    cin >> address;
    cout << "podaj plec: ";
    cin >> gender;
    modifyUser(index, firstName, lastName, address, gender);
}


