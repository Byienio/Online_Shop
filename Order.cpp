//
// Created by bieni on 15.06.2023.
//

#include "Order.h"

Order::Order(int userId, string name, int quantity, string orderDate, int price, string paymentMethod) {
    this->name = name;
    this->quantity = quantity;
    this->orderDate = orderDate;
    this->price = price;
    this->paymentMethod = paymentMethod;
    this->userId = userId;
    totalPrice = price * quantity * (1.23);
}


