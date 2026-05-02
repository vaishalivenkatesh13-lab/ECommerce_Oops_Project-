#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

class Payment {

private:
    int    paymentID;
    string paymentMethod;
    string paymentStatus;
    double amount;

public:
    Payment();
    Payment(int id, const string& method, double amount);

    void processPayment();
    void generateBill() const;
    string getPaymentStatus() const;
};

#endif
