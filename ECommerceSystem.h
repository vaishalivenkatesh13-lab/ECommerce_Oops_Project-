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
    Authentication auth;

    // CENTRAL PRODUCT STORAGE
    map<int, Product> productCatalog;

public:
    // Core System
    void startSystem();
    void mainMenu();

    // Menus
    void customerMenu(User* user);
    void adminMenu(User* user);

    // Product Management
    void addProductToCatalog(const Product& p);
    void displayAllProducts() const;
};

#endif