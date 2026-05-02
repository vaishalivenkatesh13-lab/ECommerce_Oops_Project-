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
        if (items[i].getProductID() == productID) {   // now public getter ✓
            items.erase(items.begin() + i);
            break;
        }
    }
    totalAmount = calculateTotal();
}

// Display Cart
void Cart::displayCart() const {
    if (items.empty()) {
        cout << "  [Cart] Cart is empty.\n";
        return;
    }
    for (int i = 0; i < (int)items.size(); i++) {
        items[i].displayProduct();
        cout << endl;
    }
    cout << "  Total: Rs." << totalAmount << endl;
}

// Calculate Total
double Cart::calculateTotal() {
    double total = 0;
    for (int i = 0; i < (int)items.size(); i++) {
        total += items[i].getPrice();   // now public getter ✓
    }
    return total;
}

// Clear Cart
void Cart::clearCart() {
    items.clear();
    totalAmount = 0;
}
