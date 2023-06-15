//
// Created by bieni on 12.06.2023.
//

#include "shop.h"
#include <iostream>


void shop::addUser(string firstName, string lastName, string address, string gender) {
    client newUser(firstName, lastName, address, gender);
    user.push_back(newUser);
    cout << "Dodano nowego uzytkownika" << endl;
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
    saveToText(user);
    saveToBinText(user);
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

void shop::saveToText(vector<client> user) {
    ofstream plik;
    cout << "Otwieram plik." << endl;
    plik.open("C:/Users/bieni/Desktop/untitled/plik.txt", ios_base::out);
    if(plik.is_open()) {
        cout << "Zapisuje do pliku" << endl;
        for (auto client: user) {
            plik << client.getFirstName()<<";"<<client.getLastName()<<";"<<client.getAddress()<<";"<<client.getGender()<<"\n";
        }
    }
    plik.close();
    cout << "Plik zamkniety" << endl;

}

void shop::saveToBinText(vector<client> user) {
    ofstream plik;
    int i=0;
    cout << "Otwieram plik." << endl;
    plik.open("C:/Users/bieni/Desktop/untitled/plikbin.txt", ios_base::out| ios::binary);
    if(plik.is_open()) {
        cout << "Zapisuje do pliku" << endl;
        for (auto &client:user) {
            i++;
            string a = client.getFirstName();
            string b = client.getLastName();
            string c = client.getAddress();
            string d = client.getGender();
            plik.write(reinterpret_cast<char*>(&a),sizeof(i));
            plik.write(reinterpret_cast<char*>(&b),sizeof(i));
            plik.write(reinterpret_cast<char*>(&c),sizeof(i));
            plik.write(reinterpret_cast<char*>(&d),sizeof(i));
        }
    }
    plik.close();
    cout << "Plik zamkniety" << endl;
}


