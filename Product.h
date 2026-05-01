#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product {

private:
    int productID;
    string productName;
    string category;
    double price;
    int stockQuantity;

public:
    // Constructors
    Product();
    Product(int id, const string& name, const string& category,
            double price, int stock);

    Product(const Product& other);

    // Destructor
    ~Product();

    // Display
    void displayProduct() const;

    // Update functions
    void updateStock(int quantity);
    void updatePrice(double newPrice);

    // Check stock
    bool isInStock() const;
};

#endif