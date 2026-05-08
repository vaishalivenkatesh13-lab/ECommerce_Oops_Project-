#include "ECommerceSystem.h"
#include <limits>
#include <iostream>
using namespace std;


// ─── SEED DEFAULT PRODUCTS ──────────────────────────────────────────────────
void ECommerceSystem::seedProducts() {
    productCatalog[101] = Product(101, "Laptop",   "Electronics", 55000, 10);
    productCatalog[102] = Product(102, "Mouse",    "Electronics",  1200, 50);
    productCatalog[103] = Product(103, "USB Hub",  "Accessories",  2500, 30);
    productCatalog[104] = Product(104, "Keyboard", "Electronics",  1800, 25);
    productCatalog[105] = Product(105, "Monitor",  "Electronics", 12000, 15);
}


// ─── START SYSTEM (loop instead of recursion) ───────────────────────────────
void ECommerceSystem::startSystem() {

    seedProducts();   // Populate catalog at startup

    bool running = true;
    while (running) {

        cout << "\n================================\n";
        cout <<   "|     E-COMMERCE SYSTEM        |\n";
        cout <<   "================================\n";
        cout << "  1. Register\n  2. Login\n  3. Exit\n";
        cout << "  Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Try again.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {

            int    id;
            string name, email, password, phone;
            char roleChoice;

            cout << "\n  -- Registration --------------\n";
            cout << "  Are you registering as Admin or Customer (A/C)? ";
            cin >> roleChoice; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Enter ID      : "; cin >> id; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Enter Name    : "; getline(cin, name);
            
            while (true) {
                cout << "  Enter Email   : "; getline(cin, email);
                if (Authentication::isValidEmail(email)) break;
                cout << "  [Error] Invalid email format. Please include '@' and a domain.\n";
            }

            cout << "  Enter Password: "; getline(cin, password);

            while (true) {
                cout << "  Enter Phone   : "; getline(cin, phone);
                if (Authentication::isValidPhone(phone)) break;
                cout << "  [Error] Invalid phone. Must be exactly 10 digits.\n";
            }

            User* newUser = nullptr;
            if (toupper(roleChoice) == 'A') {
                newUser = new Admin(id, name, email, password, phone);
            } else {
                newUser = new Customer(id, name, email, password, phone, "Not Provided");
            }

            if (auth.registerUser(newUser)) {
                // Directly log in and go to dashboard only if registration was successful
                newUser->login(password);
                if (newUser->getRole() == "Admin") {
                    adminMenu(newUser);
                } else {
                    customerMenu(newUser);
                }
            }

        } else if (choice == 2) {

            string email, password;
            cout << "\n  -- Login ---------------------\n";
            cout << "  Email   : "; cin >> email;
            cout << "  Password: "; cin >> password;

            User* loggedUser = auth.validateLogin(email, password);
            if (loggedUser != nullptr) {
                if (loggedUser->getRole() == "Admin") {
                    adminMenu(loggedUser);
                } else {
                    customerMenu(loggedUser);
                }
            }

        } else if (choice == 3) {
            cout << "\n  Thank you for using E-Commerce System. Goodbye!\n";
            running = false;
        } else {
            cout << "  Invalid choice. Try again.\n";
        }
    }
}


// ─── MAIN MENU REMOVED (Replaced by direct role-based routing) ───────────────


// ─── CUSTOMER MENU ──────────────────────────────────────────────────────────
void ECommerceSystem::customerMenu(User* user) {

    if (user == nullptr) return;

    Customer* c = dynamic_cast<Customer*>(user);
    if (!c) {
        cout << "  [Error] Invalid user role for Customer Menu.\n";
        return;
    }

    bool active = true;
    while (active) {
        cout << "\n  -- Customer Menu -------------\n";
        cout << "  1. Browse Products\n";
        cout << "  2. Add Item to Cart\n";
        cout << "  3. View Cart\n";
        cout << "  4. Remove from Cart\n";
        cout << "  5. Checkout\n";
        cout << "  6. View Order History\n";
        cout << "  7. View My Profile\n";
        cout << "  8. Back\n";
        cout << "  Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            displayAllProducts();

        } else if (choice == 2) {
            int pid, qty;
            cout << "  Enter Product ID : "; cin >> pid;
            cout << "  Enter Quantity   : "; cin >> qty;

            // Look up product in central catalog
            if (productCatalog.find(pid) != productCatalog.end()) {
                Product& p = productCatalog[pid];
                c->addToCart(p.getProductID(), p.getProductName(),
                            p.getPrice(), qty);
            } else {
                cout << "  [Error] Product ID not found.\n";
            }

        } else if (choice == 3) {
            c->viewCart();

        } else if (choice == 4) {
            int pid;
            cout << "  Enter Product ID to remove: "; cin >> pid;
            c->removeFromCart(pid);

        } else if (choice == 5) {
            c->checkout();

        } else if (choice == 6) {
            c->viewOrderHistory();

        } else if (choice == 7) {
            c->displayProfile();

        } else {
            active = false;
        }
    }
}


// ─── ADMIN MENU ──────────────────────────────────────────────────────────────
void ECommerceSystem::adminMenu(User* user) {

    if (user == nullptr) return;

    Admin* a = dynamic_cast<Admin*>(user);
    if (!a) {
        cout << "  [Error] Invalid user role for Admin Menu.\n";
        return;
    }

    bool active = true;
    while (active) {
        cout << "\n  -- Admin Menu ----------------\n";
        cout << "  1. View All Products\n";
        cout << "  2. Add Product to Catalog\n";
        cout << "  3. Update Product Price\n";
        cout << "  4. Update Product Stock\n";
        cout << "  5. View Registered Users\n";
        cout << "  6. View Admin Profile\n";
        cout << "  7. Back\n";
        cout << "  Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Try again.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            displayAllProducts();

        } else if (choice == 2) {
            int    id, stock;
            string name, category;
            double price;

            cout << "  Product ID  : "; 
            if (!(cin >> id)) { cout << "  [Error] Invalid ID.\n"; cin.clear(); cin.ignore(10000,'\n'); continue; }
            cin.ignore();
            cout << "  Name        : "; getline(cin, name);
            cout << "  Category    : "; getline(cin, category);
            cout << "  Price       : "; 
            if (!(cin >> price)) { cout << "  [Error] Invalid Price.\n"; cin.clear(); cin.ignore(10000,'\n'); continue; }
            cout << "  Stock       : "; 
            if (!(cin >> stock)) { cout << "  [Error] Invalid Stock.\n"; cin.clear(); cin.ignore(10000,'\n'); continue; }

            Product p(id, name, category, price, stock);
            addProductToCatalog(p);
            cout << "  [Admin] Product added to catalog.\n";

        } else if (choice == 3) {
            int pid; double newPrice;
            cout << "  Product ID : "; cin >> pid;
            cout << "  New Price  : "; cin >> newPrice;
            if (productCatalog.find(pid) != productCatalog.end()) {
                productCatalog[pid].updatePrice(newPrice);
                cout << "  [Admin] Price updated.\n";
            } else {
                cout << "  [Error] Product not found.\n";
            }

        } else if (choice == 4) {
            int pid, qty;
            cout << "  Product ID       : "; cin >> pid;
            cout << "  Stock to add     : "; cin >> qty;
            if (productCatalog.find(pid) != productCatalog.end()) {
                productCatalog[pid].updateStock(qty);
                cout << "  [Admin] Stock updated.\n";
            } else {
                cout << "  [Error] Product not found.\n";
            }

        } else if (choice == 5) {
            auth.displayAllUsers();

        } else if (choice == 6) {
            a->displayProfile();

        } else {
            active = false;
        }
    }
}


// ─── ADD PRODUCT TO CATALOG ──────────────────────────────────────────────────
void ECommerceSystem::addProductToCatalog(const Product& p) {
    productCatalog[p.getProductID()] = p;   // uses public getter ✓
}


// ─── DISPLAY ALL PRODUCTS ────────────────────────────────────────────────────
void ECommerceSystem::displayAllProducts() const {
    if (productCatalog.empty()) {
        cout << "  No products available.\n";
        return;
    }
    cout << "\n  --- Product Catalog ------------------\n";
    for (const auto& entry : productCatalog) {
        entry.second.displayProduct();
        cout << "  -------------------------------------\n";
    }
}
