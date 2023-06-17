//
// Created by bieni on 12.06.2023.
//

#include "shop.h"
#include <iostream>
#include <ctime>


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
    int zmienna, id;
    zmienna = 1000;
    productslist();
    string firstName, lastName, address, gender;
    while (zmienna != 0) {
        cout << "co zrobic?" << endl;
        cin >> zmienna;
        switch (zmienna) {
            case (1): {
                cout << "Podaj imie: ";
                cin >> firstName;
                cout << "Podaj nazwisko: ";
                cin >> lastName;
                cout << "Podaj adres: ";
                cin >> address;
                cout << "podaj plec: ";
                cin >> gender;
                addUser(firstName, lastName, address, gender);
                cout << "stworzono uzytownika o id " << id <<
                     endl;
                id++;
                break;
            }
            case (2): {
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
                break;
            }
            case (3): {
                saveToText(user);
                saveToBinText(user);
                break;
            }
            case (4): {
                string name, paymentMethod;
                int quantity, VAT, price;
                cout << "podaj nazwe: ";
                cin >> name;
                cout << "Podaj ilosc: ";
                cin >> quantity;
                cout << "podaj spobos platnosci: ";
                cin >> paymentMethod;
                for (auto product: products) {
                    if (product.name == name) {
                        price = product.price;
                        addOrder(name, quantity, price, paymentMethod);
                    }
                }
                if (price == 0) cout << "zla nazwa produktu" << endl;\
                break;
            }
            case (5): {
                string name, paymentMethod;
                int quantity, VAT, price;
                int index;
                cout << "Podaj indeks zamowienia ktore chcesz edytowac: " << endl;
                cin >> index;
                if(index<=order.size()+1) {
                    cout << "Podaj nazwe nowego produktu:" << endl;
                    cin >> name;
                    cout << "podaj ilosc: " << endl;
                    cin >> quantity;
                    cout << "podaj sposob platnosci:" << endl;
                    cin >> paymentMethod;
                    modifyOrder(index, name, quantity, paymentMethod);
                }
                else cout<<"zly numer indeksu"<<endl;
            }
            case (6): {
                for (auto product: products) {
                    cout << "Name: " << product.name << endl;
                    cout << "Price: " << product.price << endl;
                }
                break;
            }
            case(7):{
                showOrders(order);
            }
        }
    }

}

void shop::saveToText(vector<client> user) {
    ofstream plik;
    cout << "Otwieram plik." << endl;
    plik.open("C:/Users/bieni/Desktop/untitled/plik.txt", ios_base::out);
    if (plik.is_open()) {
        cout << "Zapisuje do pliku" << endl;
        for (auto client: user) {
            string zmienna = client.getClientData();
            plik << zmienna << endl;
        }
    }
    plik.close();
    cout << "Plik zamkniety" << endl;

}

void shop::saveToBinText(vector<client> user) {
    ofstream plik;
    int i = 0;
    cout << "Otwieram plik." << endl;
    plik.open("C:/Users/bieni/Desktop/untitled/plikbin.txt", ios_base::out | ios::binary);
    if (plik.is_open()) {
        cout << "Zapisuje do pliku" << endl;
        for (auto client: user) {
            i++;
            string a = client.getClientData();
            plik.write(reinterpret_cast<char *>(&a), sizeof(i));
        }
    }
    plik.close();
    cout << "Plik zamkniety" << endl;
}

void shop::addOrder(string name, int quantity, int price, string paymentMethod) {
    time_t now = time(0);
    string date_time = ctime(&now);
    Order newOrder(name, quantity, date_time, price, paymentMethod);
    order.push_back(newOrder);
    cout << "dodano nowe zamowienie" << endl;
}

void shop::productslist() {
    ifstream plik;
    plik.open("C:/Users/bieni/Desktop/untitled/products.txt");
    string line, name1, price, sredniki1, sredniki2;
    int price1;
    if (plik.is_open()) {
        while (!plik.eof()) {
            plik >> line;
            stringstream ss(line);
            getline(ss, name1, ';');
            getline(ss, price, ';');
            price1 = stoi(price);
            product newProduct(name1, price1);
            products.push_back(newProduct);
            if (plik.eof()) break;
        }
        for (auto product: products) {
            cout << "Name: " << product.name << endl;
            cout << "Price: " << product.price << endl;
        }
    }
    plik.close();

}

void shop::modifyOrder(int index, string name, int quantity, string paymentMethod) {
    if (index >= 0 && index <= order.size()) {
        Order &modorder = order[index - 1];
        time_t now = time(0);
        string date_time = ctime(&now);
        for (auto product: products) {
            if (name == product.name) {
                int price = product.price;
                modorder = Order(name, quantity, date_time, price, paymentMethod);
            }
        }
    }
}

void shop::showOrders(vector<Order> order) {
    for(int i=0;i<order.size();i++){
        cout<<"nr Zamowienia: "<<i+1<<endl;
        cout<<"Nazwa: "<<order[i].name<<"\t";
        cout<<"Ilosc: "<<order[i].quantity<<"\t";
        cout<<"Cena za 1szt: "<<order[i].price<<"\t";
        cout<<"Data zlozenia zamowienia: "<<order[i].orderDate<<"\t";
        cout<<"Cena zamowienia: "<<order[i].totalPrice<<"\t";
        cout<<"Metoda platnosci: "<<order[i].paymentMethod<<endl;
    }
}




