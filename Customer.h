#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <vector>
#include <string>
using namespace std;

// Cart item struct
struct CartItem {
    int    productID;
    string productName;
    double price;
    int    quantity;
};

// OrderRecord: renamed from 'Order' to avoid clash with class Order in Order.h
struct OrderRecord {
    int              orderID;
    vector<CartItem> items;
    double           totalAmount;
    string           status;
};

// Customer class (inherits User)
class Customer : public User {

private:
    string              address;
    vector<CartItem>    cart;
    vector<OrderRecord> orderHistory;

    static int nextOrderID;

    double calculateCartTotal() const;

public:
    // Constructors
    Customer();
    Customer(int id, const string& name, const string& email,
             const string& password, const string& phone,
             const string& address);

    Customer(const Customer& other);

    // Destructor
    ~Customer() override;

    // Getters / Setters
    string getAddress() const;
    void   setAddress(const string& newAddress);

    // Cart operations
    void browseProducts() const;
    void addToCart(int productID, const string& name,
                   double price, int quantity);
    void removeFromCart(int productID);
    void viewCart() const;

    // Order operations
    void checkout();
    bool makePayment(double amount);
    void viewOrderHistory() const;

    // Override (Polymorphism)
    void displayProfile() const override;
};

#endif
