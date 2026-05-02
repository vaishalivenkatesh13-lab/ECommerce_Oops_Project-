#include "Order.h"
#include <iostream>
using namespace std;

// Default Constructor
Order::Order() {
    orderID        = 0;
    customerID     = 0;
    totalBill      = 0;
    orderStatus    = "Pending";
    deliveryStatus = "Not Assigned";
}

// Parameterized Constructor
Order::Order(int orderID, int customerID, vector<Product> products) {
    this->orderID    = orderID;
    this->customerID = customerID;
    orderedProducts  = products;

    totalBill = 0;
    for (int i = 0; i < (int)orderedProducts.size(); i++) {
        totalBill += orderedProducts[i].getPrice();   // now public getter ✓
    }

    orderStatus    = "Pending";
    deliveryStatus = "Not Assigned";
}

// Place Order
void Order::placeOrder() {
    cout << "  [Order] Order placed successfully.\n";
    orderStatus = "Confirmed";
}

// View Order
void Order::viewOrder() const {
    cout << "\n  --- Order Details ----------------\n";
    cout << "  Order ID       : " << orderID        << endl;
    cout << "  Customer ID    : " << customerID     << endl;
    cout << "  Products:\n";
    for (int i = 0; i < (int)orderedProducts.size(); i++) {
        orderedProducts[i].displayProduct();
        cout << endl;
    }
    cout << "  Total Bill     : Rs." << totalBill    << endl;
    cout << "  Order Status   : " << orderStatus    << endl;
    cout << "  Delivery Status: " << deliveryStatus << endl;
    cout << "  ----------------------------------\n";
}

// Update Order Status
void Order::updateOrderStatus(const string& status) {
    orderStatus = status;
    cout << "  [Order] Status updated to: " << orderStatus << "\n";
}
