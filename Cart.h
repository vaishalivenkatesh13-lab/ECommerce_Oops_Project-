#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"
using namespace std;

class Cart {

private:
    vector<Product> items;
    double          totalAmount;

public:
    Cart();

    void   addItem(Product p);
    void   removeItem(int productID);
    void   displayCart() const;
    double calculateTotal();
    void   clearCart();
};

#endif
