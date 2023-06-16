//
// Created by bieni on 15.06.2023.
//

#include "Order.h"

Order::Order(string name, int quantity, string orderDate, int price, string paymentMethod) {
    this->name = name;
    this->quantity = quantity;
    this->orderDate = orderDate;
    this->price = price;
    this->paymentMethod = paymentMethod;
    totalPrice = price * quantity * (1.23);
}

string Order::getName() {
    return name;
}

int Order::getQuantity() {
    return quantity;
}

string Order::getOrderDate() {
    return orderDate;
}

int Order::getPrice() {
    return price;
}

string Order::getPaymentMethod() {
    return paymentMethod;
}

int Order::getTotalPrice() {
    return totalPrice;
}

