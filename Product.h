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

    // Getters  ← moved from private to public (they ARE getters, just misplaced)
    int    getProductID()   const;
    double getPrice()       const;
    string getProductName() const;
    string getCategory()    const;
    int    getStock()       const;

    // Functions
    void displayProduct() const;
    void updateStock(int quantity);
    void updatePrice(double newPrice);
    bool isInStock() const;
};

#endif
