#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Authentication {

private:
    vector<User*> users;   // Stores all registered users

public:
    // Constructor / Destructor
    Authentication();
    ~Authentication();

    // Core Functionalities
    bool  registerUser(User* newUser);
    User* validateLogin(const string& email, const string& password);
    void  forgotPassword(const string& email);

    // Static Validation Utilities
    static bool isValidEmail(const string& email);
    static bool isValidPhone(const string& phone);

    // Utility
    void displayAllUsers() const;
};

#endif
