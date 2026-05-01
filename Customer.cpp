#include "Customer.h"

// static member initialisation
int Customer::nextOrderID = 1001;


// Default Constructor
Customer::Customer()
    : User(), address("")
{
}

// Parameterized Constructor
Customer::Customer(int id, const string& name, const string& email,
                   const string& password, const string& phone,
                   const string& address)
    : User(id, name, email, password, phone),
      address(address)
{
}

// Copy Constructor
Customer::Customer(const Customer& other)
    : User(other),
      address(other.address),
      cart(other.cart),
      orderHistory(other.orderHistory)
{
}

// Destructor
Customer::~Customer() {
}


// Get Address
string Customer::getAddress() const {
    return address;
}

// Set Address
void Customer::setAddress(const string& newAddress) {
    if (!newAddress.empty())
        address = newAddress;
}


// Calculate Cart Total
double Customer::calculateCartTotal() const {
    double total = 0;

    for (int i = 0; i < (int)cart.size(); i++) {
        total += cart[i].price * cart[i].quantity;
    }

    return total;
}


// Browse Products
void Customer::browseProducts() const {
    cout << "\nAvailable Products\n";
    cout << "101 Laptop 55000\n";
    cout << "102 Mouse  1200\n";
    cout << "103 Hub    2500\n";
}


// Add to Cart
void Customer::addToCart(int productID, const string& name,
                         double price, int quantity) {

    for (int i = 0; i < (int)cart.size(); i++) {
        if (cart[i].productID == productID) {
            cart[i].quantity += quantity;
            return;
        }
    }

    CartItem item;
    item.productID = productID;
    item.productName = name;
    item.price = price;
    item.quantity = quantity;

    cart.push_back(item);
}


// Remove from Cart
void Customer::removeFromCart(int productID) {

    for (int i = 0; i < (int)cart.size(); i++) {
        if (cart[i].productID == productID) {
            cart.erase(cart.begin() + i);
            return;
        }
    }
}


// View Cart
void Customer::viewCart() const {

    if (cart.empty()) {
        cout << "Cart is empty\n";
        return;
    }

    for (int i = 0; i < (int)cart.size(); i++) {
        cout << cart[i].productName << " x"
             << cart[i].quantity << " = "
             << cart[i].price * cart[i].quantity << endl;
    }

    cout << "Total: " << calculateCartTotal() << endl;
}


// Checkout
void Customer::checkout() {

    if (cart.empty()) return;

    double total = calculateCartTotal();

    if (makePayment(total)) {

        Order o;
        o.orderID = nextOrderID++;
        o.items = cart;
        o.totalAmount = total;
        o.status = "Placed";

        orderHistory.push_back(o);
        cart.clear();
    }
}


// Payment
bool Customer::makePayment(double amount) {

    int choice;
    cout << "1.UPI 2.Card 3.COD: ";
    cin >> choice;

    if (choice < 1 || choice > 3)
        return false;

    cout << "Payment Success: " << amount << endl;
    return true;
}


// Order History
void Customer::viewOrderHistory() const {

    for (int i = 0; i < (int)orderHistory.size(); i++) {
        cout << "Order ID: " << orderHistory[i].orderID
             << " Total: " << orderHistory[i].totalAmount
             << " Status: " << orderHistory[i].status << endl;
    }
}


// Display Profile (override)
void Customer::displayProfile() const {

    User::displayProfile();

    cout << "Address: " << address << endl;
    cout << "Cart items: " << cart.size() << endl;
    cout << "Orders: " << orderHistory.size() << endl;
}