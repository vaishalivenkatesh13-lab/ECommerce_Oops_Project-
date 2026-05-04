#ifndef ECOMMERCE_SYSTEM_H
#define ECOMMERCE_SYSTEM_H

#include <iostream>
#include <map>
#include "Authentication.h"
#include "Product.h"
#include "Customer.h"
#include "Admin.h"

using namespace std;

class ECommerceSystem {

private:
    Authentication    auth;
    map<int, Product> productCatalog;   // Centralized product store (STL map)

    void seedProducts();                // Populates default catalog at startup

public:
    // Core System
    void startSystem();

    // Role-based Menus
    void customerMenu(User* user);
    void adminMenu(User* user);

    // Product Management
    void addProductToCatalog(const Product& p);
    void displayAllProducts() const;
};

#endif
