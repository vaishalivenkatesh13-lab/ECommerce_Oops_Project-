#include "Payment.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Default Constructor
Payment::Payment() {
    paymentID     = 0;
    paymentMethod = "";
    paymentStatus = "Pending";
    amount        = 0;
}

// Parameterized Constructor
Payment::Payment(int id, const string& method, double amount) {
    paymentID     = id;
    paymentMethod = method;
    this->amount  = amount;
    paymentStatus = "Pending";
}

// ─── Process Payment (Exception Handling demo) ───────────────────────────────
void Payment::processPayment() {

    try {
        if (amount <= 0) {
            throw invalid_argument("Invalid payment amount.");
        }

        if (paymentMethod != "CreditCard" &&
            paymentMethod != "Cash"       &&
            paymentMethod != "UPI") {
            throw invalid_argument("Invalid payment method.");
        }

        // ── Credit Card ──
        if (paymentMethod == "CreditCard") {

            string cardNumber, cvv;

            cout << "  Enter Card Number (16 digits): ";
            cin >> cardNumber;

            cout << "  Enter CVV (3 digits)         : ";
            cin >> cvv;

            if (cardNumber.length() != 16) {
                throw invalid_argument("Card number must be exactly 16 digits.");
            }

            if (cvv.length() != 3) {
                throw invalid_argument("CVV must be exactly 3 digits.");
            }

            cout << "  [Payment] Processing Credit Card...\n";
        }

        // ── UPI ──
        else if (paymentMethod == "UPI") {

            string upiID;

            cout << "  Enter UPI ID: ";
            cin >> upiID;

            if (upiID.find('@') == string::npos) {
                throw invalid_argument("Invalid UPI ID. Must contain '@'.");
            }

            cout << "  [Payment] Processing UPI...\n";
        }

        // ── Cash on Delivery ──
        else if (paymentMethod == "Cash") {
            cout << "  [Payment] Cash on Delivery selected.\n";
            cout << "  [Payment] Pay when order arrives.\n";
        }

        paymentStatus = "Success";
        cout << "  [Payment] Payment of Rs." << amount << " Successful!\n";
    }
    catch (invalid_argument& e) {
        paymentStatus = "Failed";
        cout << "  [Payment Error] " << e.what() << endl;
    }
    catch (exception& e) {
        paymentStatus = "Failed";
        cout << "  [General Error] " << e.what() << endl;
    }
}

// ─── Generate Bill ───────────────────────────────────────────────────────────
void Payment::generateBill() const {
    cout << "\n  --- BILL ------------------------\n";
    cout << "  Payment ID : " << paymentID     << endl;
    cout << "  Method     : " << paymentMethod << endl;
    cout << "  Amount     : Rs." << amount     << endl;
    cout << "  Status     : " << paymentStatus << endl;
    cout << "  ---------------------------------\n";
}

string Payment::getPaymentStatus() const {
    return paymentStatus;
}

