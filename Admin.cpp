#include "Admin.h"

// Default Constructor
Admin::Admin()
    : User()
{
}

// Parameterized Constructor
Admin::Admin(int id, const string& name, const string& email,
             const string& password, const string& phone)
    : User(id, name, email, password, phone)
{
}

// Copy Constructor
Admin::Admin(const Admin& other)
    : User(other)
{
}

// Destructor
Admin::~Admin() {
}

// Add Product
void Admin::addProduct() {
    cout << "Product added\n";
}

// Remove Product
void Admin::removeProduct() {
    cout << "Product removed\n";
}

// Update Product
void Admin::updateProduct() {
    cout << "Product updated\n";
}

// View Orders
void Admin::viewOrders() {
    cout << "Viewing all orders\n";
}

// Manage Delivery
void Admin::manageDelivery() {
    cout << "Managing delivery\n";
}

// View Customers
void Admin::viewCustomerList() {
    cout << "Viewing customers\n";
}

// Display Profile
void Admin::displayProfile() const {
    User::displayProfile();
    cout << "Role: Admin\n";
}