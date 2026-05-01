#include "Product.h"

// Default Constructor
Product::Product()
    : productID(0), productName(""), category(""),
      price(0.0), stockQuantity(0)
{
}

// Parameterized Constructor
Product::Product(int id, const string& name, const string& category,
                 double price, int stock)
    : productID(id), productName(name), category(category),
      price(price), stockQuantity(stock)
{
}

// Copy Constructor
Product::Product(const Product& other)
    : productID(other.productID),
      productName(other.productName),
      category(other.category),
      price(other.price),
      stockQuantity(other.stockQuantity)
{
}

// Destructor
Product::~Product() {
}


// Display Product
void Product::displayProduct() const {
    cout << "ID: " << productID << endl;
    cout << "Name: " << productName << endl;
    cout << "Category: " << category << endl;
    cout << "Price: " << price << endl;
    cout << "Stock: " << stockQuantity << endl;
}


// Update Stock
void Product::updateStock(int quantity) {
    stockQuantity += quantity;
}


// Update Price
void Product::updatePrice(double newPrice) {
    if (newPrice > 0)
        price = newPrice;
}


// Check Stock
bool Product::isInStock() const {
    return stockQuantity > 0;
}