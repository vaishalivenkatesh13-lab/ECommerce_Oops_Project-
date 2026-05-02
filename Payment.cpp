#include "Payment.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Constructor
Payment::Payment() {
    paymentID = 0;
    paymentMethod = "";
    paymentStatus = "Pending";
    amount = 0;
}

// Parameterized Constructor
Payment::Payment(int id, const string& method, double amount) {
    paymentID = id;
    paymentMethod = method;
    this->amount = amount;
    paymentStatus = "Pending";
}


// Process Payment
void Payment::processPayment() {

    try {

        if (amount <= 0) {
            throw invalid_argument("Invalid amount");
        }

        if (paymentMethod != "CreditCard" &&
            paymentMethod != "Cash" &&
            paymentMethod != "UPI") {
            throw invalid_argument("Invalid payment method");
        }

        // Simulated processing
        if (paymentMethod == "CreditCard") {
            cout << "Processing Credit Card...\n";
        }
        else if (paymentMethod == "UPI") {
            cout << "Processing UPI...\n";
        }
        else if (paymentMethod == "Cash") {
            cout << "Processing Cash...\n";
        }

        paymentStatus = "Success";
        cout << "Payment Successful\n";
    }

    catch (invalid_argument& e) {
        paymentStatus = "Failed";
        cout << "Payment Error: " << e.what() << endl;
    }

    catch (exception& e) {
        paymentStatus = "Failed";
        cout << "General Error: " << e.what() << endl;
    }
}


// Generate Bill
void Payment::generateBill() const {

    cout << "\n--- BILL ---\n";
    cout << "Payment ID: " << paymentID << endl;
    cout << "Method: " << paymentMethod << endl;
    cout << "Amount: " << amount << endl;
    cout << "Status: " << paymentStatus << endl;
}