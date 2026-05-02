#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Product.h"
using namespace std;

class Order {

private:
    int orderID;
    int customerID;
    vector<Product> orderedProducts;
    double totalBill;
    string orderStatus;
    string deliveryStatus;

public:
    Order();

    Order(int orderID, int customerID, vector<Product> products);

    void placeOrder();
    void viewOrder() const;
    void updateOrderStatus(const string& status);
};

#endif