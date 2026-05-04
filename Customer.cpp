#include "Customer.h"
#include "Payment.h"
#include <iostream>
using namespace std;

// Static member initialisation
int Customer::nextOrderID = 1001;


// ─── Constructors ───────────────────────────────────────────────────────────

Customer::Customer()
    : User(0, "", "", "", "", "Customer"), address("")
{
}

Customer::Customer(int id, const string& name, const string& email,
                   const string& password, const string& phone,
                   const string& address)
    : User(id, name, email, password, phone, "Customer"),
      address(address)
{
}

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


// ─── Getters / Setters ──────────────────────────────────────────────────────

string Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const string& newAddress) {
    if (!newAddress.empty())
        address = newAddress;
}


// ─── Cart Helpers ────────────────────────────────────────────────────────────

double Customer::calculateCartTotal() const {
    double total = 0;
    for (int i = 0; i < (int)cart.size(); i++) {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}


// ─── Browse Products ─────────────────────────────────────────────────────────

void Customer::browseProducts() const {
    cout << "\n  Available Products (use Admin menu to add more):\n";
    cout << "  101  Laptop     Rs.55000\n";
    cout << "  102  Mouse      Rs.1200\n";
    cout << "  103  USB Hub    Rs.2500\n";
}


// ─── Add to Cart ─────────────────────────────────────────────────────────────

void Customer::addToCart(int productID, const string& name,
                         double price, int quantity) {
    // If item already in cart, increase quantity
    for (int i = 0; i < (int)cart.size(); i++) {
        if (cart[i].productID == productID) {
            cart[i].quantity += quantity;
            cout << "  [Cart] Quantity updated for " << name << ".\n";
            return;
        }
    }

    CartItem item;
    item.productID   = productID;
    item.productName = name;
    item.price       = price;
    item.quantity    = quantity;

    cart.push_back(item);
    cout << "  [Cart] " << name << " added to cart.\n";
}


// ─── Remove from Cart ────────────────────────────────────────────────────────

void Customer::removeFromCart(int productID) {
    for (int i = 0; i < (int)cart.size(); i++) {
        if (cart[i].productID == productID) {
            cout << "  [Cart] " << cart[i].productName << " removed.\n";
            cart.erase(cart.begin() + i);
            return;
        }
    }
    cout << "  [Cart] Product not found in cart.\n";
}


// ─── View Cart ───────────────────────────────────────────────────────────────

void Customer::viewCart() const {
    if (cart.empty()) {
        cout << "  [Cart] Cart is empty.\n";
        return;
    }
    cout << "\n  --- Your Cart -----------------------\n";
    for (int i = 0; i < (int)cart.size(); i++) {
        cout << "  " << cart[i].productName
             << " x" << cart[i].quantity
             << "  =  Rs." << cart[i].price * cart[i].quantity << "\n";
    }
    cout << "  -------------------------------------\n";
    cout << "  Total: Rs." << calculateCartTotal() << "\n";
}


// ─── Checkout ────────────────────────────────────────────────────────────────

void Customer::checkout() {
    if (cart.empty()) {
        cout << "  [Order] Cart is empty. Nothing to checkout.\n";
        return;
    }

    double total = calculateCartTotal();
    cout << "\n  Order Total: Rs." << total << "\n";

    if (makePayment(total)) {
        // Use OrderRecord (renamed from Order to avoid clash with Order class)
        OrderRecord o;
        o.orderID     = nextOrderID++;
        o.items       = cart;
        o.totalAmount = total;
        o.status      = "Placed";

        orderHistory.push_back(o);
        cart.clear();
        cout << "  [Order] Order #" << o.orderID << " placed successfully!\n";
    }
}


// ─── Payment ─────────────────────────────────────────────────────────────────

bool Customer::makePayment(double amount) {
    int choice;
    cout << "\n  Select Payment Method:\n";
    cout << "  1. UPI\n  2. Credit Card\n  3. Cash on Delivery\n";
    cout << "  Choice: ";
    
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "  [Payment] Invalid choice. Payment failed.\n";
        return false;
    }

    if (choice < 1 || choice > 3) {
        cout << "  [Payment] Invalid choice. Payment failed.\n";
        return false;
    }

    string method = "";
    if (choice == 1) method = "UPI";
    else if (choice == 2) method = "CreditCard";
    else if (choice == 3) method = "Cash";

    Payment p(999, method, amount);
    p.processPayment();

    return p.getPaymentStatus() == "Success";
}


// ─── Order History ───────────────────────────────────────────────────────────

void Customer::viewOrderHistory() const {
    if (orderHistory.empty()) {
        cout << "  [Orders] No orders placed yet.\n";
        return;
    }
    cout << "\n  --- Order History -------------------\n";
    for (int i = 0; i < (int)orderHistory.size(); i++) {
        cout << "  Order ID : " << orderHistory[i].orderID
             << "  |  Total: Rs." << orderHistory[i].totalAmount
             << "  |  Status: " << orderHistory[i].status << "\n";
    }
}


// ─── Display Profile (Polymorphism override) ─────────────────────────────────

void Customer::displayProfile() const {
    User::displayProfile();
    cout << "  Address    : " << address         << endl;
    cout << "  Cart Items : " << cart.size()     << endl;
    cout << "  Orders     : " << orderHistory.size() << endl;
}
