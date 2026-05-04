#include "Admin.h"
#include <iostream>
using namespace std;

// ─── Constructors ────────────────────────────────────────────────────────────

Admin::Admin()
    : User(0, "", "", "", "", "Admin")
{
}

Admin::Admin(int id, const string& name, const string& email,
             const string& password, const string& phone)
    : User(id, name, email, password, phone, "Admin")
{
}

Admin::Admin(const Admin& other)
    : User(other)
{
}

// Destructor
Admin::~Admin() {
}

// ─── Admin Actions ────────────────────────────────────────────────────────────

void Admin::addProduct() {
    cout << "  [Admin] Product added to catalog.\n";
}

void Admin::removeProduct() {
    cout << "  [Admin] Product removed from catalog.\n";
}

void Admin::updateProduct() {
    cout << "  [Admin] Product updated.\n";
}

void Admin::viewOrders() {
    cout << "  [Admin] Viewing all orders.\n";
}

void Admin::manageDelivery() {
    cout << "  [Admin] Managing delivery assignments.\n";
}

void Admin::viewCustomerList() {
    cout << "  [Admin] Viewing registered customer list.\n";
}

// ─── Display Profile (Polymorphism override) ─────────────────────────────────

void Admin::displayProfile() const {
    User::displayProfile();
    cout << "  Role   : Admin\n";
}
