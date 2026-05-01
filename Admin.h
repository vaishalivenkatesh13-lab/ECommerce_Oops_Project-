#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
#include <string>
using namespace std;

class Admin : public User {

public:
    // Constructors
    Admin();
    Admin(int id, const string& name, const string& email,
          const string& password, const string& phone);

    Admin(const Admin& other);

    // Destructor
    ~Admin() override;

    // Admin actions
    void addProduct();
    void removeProduct();
    void updateProduct();
    void viewOrders();
    void manageDelivery();
    void viewCustomerList();

    // Override
    void displayProfile() const override;
};

#endif