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
    int getProductID() const;
    double getPrice() const;

public:
    // Constructors
    Product();
    Product(int id, const string& name, const string& category,
            double price, int stock);

    Product(const Product& other);

    // Destructor
    ~Product();

    // Functions
    void displayProduct() const;
    void updateStock(int quantity);
    void updatePrice(double newPrice);
    bool isInStock() const;
};

#endif
