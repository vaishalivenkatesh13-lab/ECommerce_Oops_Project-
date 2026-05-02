#include "ECommerceSystem.h"
#include <limits>

// ---------------------- START SYSTEM ----------------------
void ECommerceSystem::startSystem() {

    int choice;

    cout << "\n===== E-COMMERCE SYSTEM =====\n";
    cout << "1. Register\n2. Login\nChoice: ";
    cin >> choice;

    if (choice == 1) {

        int id;
        string name, email, password, phone;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Password: ";
        getline(cin, password);

        cout << "Enter Phone: ";
        getline(cin, phone);

        User newUser(id, name, email, password, phone);
        auth.registerUser(newUser);

        cout << "\nNow login...\n";
        startSystem();  // recursive call for simplicity
    }

    else if (choice == 2) {

        string email, password;

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Password: ";
        cin >> password;

        User* loggedUser = auth.validateLogin(email, password);

        if (loggedUser != nullptr) {
            mainMenu();
        }
    }
}


// ---------------------- MAIN MENU ----------------------
void ECommerceSystem::mainMenu() {

    int choice;

    cout << "\n1. Customer\n2. Admin\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        customerMenu(nullptr);
    }
    else if (choice == 2) {
        adminMenu(nullptr);
    }
}


// ---------------------- CUSTOMER MENU ----------------------
void ECommerceSystem::customerMenu(User* user) {

    Customer c;
    int choice;

    cout << "\n--- CUSTOMER MENU ---\n";
    cout << "1. View Products\n2. Add to Cart\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        displayAllProducts();
    }
    else if (choice == 2) {
        c.addToCart();
    }
}


// ---------------------- ADMIN MENU ----------------------
void ECommerceSystem::adminMenu(User* user) {

    Admin a;
    int choice;

    cout << "\n--- ADMIN MENU ---\n";
    cout << "1. Add Product\n2. View Products\nChoice: ";
    cin >> choice;

    if (choice == 1) {

        int id;
        string name, category;
        float price;
        int stock;

        cout << "Enter Product ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Category: ";
        getline(cin, category);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Stock: ";
        cin >> stock;

        Product p(id, name, category, price, stock);

        addProductToCatalog(p);
        cout << "Product added to system!\n";
    }

    else if (choice == 2) {
        displayAllProducts();
    }
}


// ---------------------- ADD PRODUCT ----------------------
void ECommerceSystem::addProductToCatalog(const Product& p) {

    int id = p.getProductID();

    productCatalog[id] = p;
}


// ---------------------- DISPLAY PRODUCTS ----------------------
void ECommerceSystem::displayAllProducts() const {

    if (productCatalog.empty()) {
        cout << "No products available.\n";
        return;
    }

    cout << "\n--- PRODUCT LIST ---\n";

    for (const auto& pair : productCatalog) {
        pair.second.displayProduct();
        cout << endl;
    }
}