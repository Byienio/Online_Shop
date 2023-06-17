//
// Created by bieni on 12.06.2023.
//

#include "shop.h"
#include <iostream>
#include <ctime>
#include <cstring>

void shop::menu() {
    int zmienna, id, orderId;
    id = 1, orderId = 1;
    productslist();
    string firstName, lastName, address, gender;
    cout << "1-dodanie uzytkownika" << endl;
    cout << "2-modyfikacja uzytkownika" << endl;
    cout << "3-zapis uzytkownikow do pliku" << endl;
    cout << "4-dodanie zamowienia" << endl;
    cout << "5-modyfikacja zamowienia" << endl;
    cout << "6-wyswietlenie listy produktow" << endl;
    cout << "7-wyswietlenie zamowien" << endl;
    cout << "8-zapis zamowien do plku" << endl;
    cout << "9-wyjscie" << endl;
    while (zmienna != 9) {
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
                if (index <= user.size() + 1 && index > 0) {
                    cout << "Podaj imie: ";
                    cin >> firstName;
                    cout << "Podaj nazwisko: ";
                    cin >> lastName;
                    cout << "Podaj adres: ";
                    cin >> address;
                    cout << "podaj plec: ";
                    cin >> gender;
                    modifyUser(index, firstName, lastName, address, gender);
                } else cout << "Nie ma takiego uzytkownika" << endl;
                break;
            }
            case (3): {
                saveToText(user);
                saveToBinText(user);
                break;
            }
            case (4): {
                string name, paymentMethod;
                int quantity, price, userId;
                cout << "Podaj id klienta: ";
                cin >> userId;
                if (userId <= user.size() + 1 && userId > 0) {
                    cout << "podaj nazwe: ";
                    cin >> name;
                    cout << "Podaj ilosc: ";
                    cin >> quantity;
                    cout << "podaj spobos platnosci: ";
                    cin >> paymentMethod;
                    for (auto product: products) {
                        if (product.name == name) {
                            price = product.price;
                            addOrder(userId, name, quantity, price, paymentMethod);
                        }
                    }
                    if (price == 0) cout << "zla nazwa produktu" << endl;\
                cout << "dodano zamowienie o id " << orderId <<
                     endl;
                    orderId++;
                } else cout << "Nie ma uzytkownika o takim id" << endl;
                break;
            }
            case (5): {
                string name, paymentMethod;
                int quantity, index;
                cout << "Podaj indeks zamowienia ktore chcesz edytowac: " << endl;
                cin >> index;
                if (index <= order.size() + 1 && index > 0) {
                    cout << "Podaj nazwe nowego produktu:" << endl;
                    cin >> name;
                    cout << "podaj ilosc: " << endl;
                    cin >> quantity;
                    cout << "podaj sposob platnosci:" << endl;
                    cin >> paymentMethod;
                    modifyOrder(index, name, quantity, paymentMethod);
                } else cout << "zly numer indeksu" << endl;
                break;
            }
            case (6): {
                for (auto product: products) {
                    cout << "Name: " << product.name << endl;
                    cout << "Price: " << product.price << endl;
                }
                break;
            }
            case (7): {
                showOrders(order, user);
                break;
            }
            case (8): {
                saveOrdersToFile(order, user);
                saveOrdersToBinFile(order,user);
                break;
            }
        }
    }

}

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

void shop::saveToText(vector<client> user) {
    ofstream plik;
    cout << "Otwieram plik." << endl;
    plik.open("users.txt", ios_base::out);
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
    plik.open("usersbin.txt", ios_base::out | ios::binary);
    if (plik.is_open()) {
        cout << "Zapisuje do pliku" << endl;
        for (auto client: user) {
            string a = client.getClientData();
            plik.write(reinterpret_cast<char *>(&a), sizeof(i));
            i++;
        }
    }
    plik.close();
    cout << "Plik zamkniety" << endl;
}

void shop::addOrder(int userId, string name, int quantity, int price, string paymentMethod) {
    time_t now = time(0);
    string date_time = ctime(&now);
    date_time = date_time.substr(0, date_time.length() - 1);
    Order newOrder(userId - 1, name, quantity, date_time, price, paymentMethod);
    order.push_back(newOrder);
}

void shop::productslist() {
    ifstream plik;
    plik.open("products.txt");
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
                modorder = Order(order[index - 1].userId, name, quantity, date_time, price, paymentMethod);
            }
        }
    }
}

void shop::showOrders(vector<Order> order, vector<client> user) {
    for (int i = 0; i < order.size(); i++) {
        cout << "nr Zamowienia: " << i + 1 << endl;
        cout << "Imie: " << user[order[i].userId].firstName << "\t";
        cout << "Nazwisko: " << user[order[i].userId].lastName << "\t";
        cout << "Adres dostawy: " << user[order[i].userId].address << "\t";
        cout << "Nazwa: " << order[i].name << "\t";
        cout << "Ilosc: " << order[i].quantity << "\t";
        cout << "Cena za 1szt: " << order[i].price << "\t";
        cout << "Data zlozenia zamowienia: " << order[i].orderDate << "\t";
        cout << "Cena zamowienia: " << order[i].totalPrice << "\t";
        cout << "Metoda platnosci: " << order[i].paymentMethod << endl;
    }
}

void shop::saveOrdersToFile(vector<Order> order, vector<client> user) {
    ofstream plik;
    cout << "Otwieram plik." << endl;
    plik.open("orders.txt", ios_base::out);
    if (plik.is_open()) {
        plik << "imie;nazwisko;adres_dostawy;nazwa_produktu;ilosc;cena1szt;data;cena_zamowienia;metoda_platnosci\n";
        cout << "Zapisuje do pliku" << endl;
        for (auto order: order) {
            plik << user[order.userId].firstName << ";" << user[order.userId].lastName << ";"
                 << user[order.userId].address << ";" << order.name << ";" << order.quantity << ";" << order.price
                 << ";" << order.orderDate << ";"
                 << order.totalPrice << ";" << order.paymentMethod << ";" << "\n";
        }
    }
    plik.close();
    cout << "Plik zamkniety" << endl;
}

void shop::saveOrdersToBinFile(vector<Order> order, vector<client> user) {
    int i=0;
    ofstream plik;
    cout << "Otwieram plik binarny ." << endl;
    plik.open("ordersbin.txt", ios_base::out | ios::binary);
    if (plik.is_open()) {
        cout << "Zapisuje do pliku binarnego " << endl;
        for (auto order: order) {
            string a = user[order.userId].firstName + ";"
                    + user[order.userId].lastName + ";" + user[order.userId].address + ";" + order.name
                    + ";" + to_string(order.quantity) + ";" + to_string(order.price) + ";" + order.orderDate + ";"
                    + to_string(order.totalPrice) + ";" + order.paymentMethod + ";" + "\n";
            plik.write(reinterpret_cast<char *>(&a), sizeof(i));
            i++;
        }
    }
    plik.close();
    cout << "Plik binarny zamkniety" << endl;
}




