#include "Cart.h"
#include <iostream>
using namespace std;

// Constructor
Cart::Cart() {
    totalAmount = 0;
}


// Add Item
void Cart::addItem(Product p) {
    items.push_back(p);
    totalAmount = calculateTotal();
}


// Remove Item
void Cart::removeItem(int productID) {

    for (int i = 0; i < (int)items.size(); i++) {
        // assuming Product has getProductID()
        if (items[i].getProductID() == productID) {
            items.erase(items.begin() + i);
            break;
        }
    }

    totalAmount = calculateTotal();
}


// Display Cart
void Cart::displayCart() const {

    if (items.empty()) {
        cout << "Cart is empty\n";
        return;
    }

    for (int i = 0; i < (int)items.size(); i++) {
        items[i].displayProduct();
        cout << endl;
    }

    cout << "Total: " << totalAmount << endl;
}


// Calculate Total
double Cart::calculateTotal() {

    double total = 0;

    for (int i = 0; i < (int)items.size(); i++) {
        // assuming Product has getPrice()
        total += items[i].getPrice();
    }

    return total;
}


// Clear Cart
void Cart::clearCart() {
    items.clear();
    totalAmount = 0;
}