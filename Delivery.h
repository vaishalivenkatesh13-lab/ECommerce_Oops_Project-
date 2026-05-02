#ifndef DELIVERY_H
#define DELIVERY_H

#include <iostream>
#include <string>
#include "Order.h"
using namespace std;

class Delivery {

private:
    int deliveryID;
    string deliveryAddress;
    string deliveryStatus;
    string expectedDate;

public:
    Delivery();

    void assignDelivery(int id, const string& address, const string& date, Order& order);
    void updateDeliveryStatus(const string& status);
    void trackDelivery() const;
};

#endif