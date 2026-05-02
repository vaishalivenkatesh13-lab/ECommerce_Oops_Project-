#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Authentication {

private:
    vector<User> users;   // Stores all registered users

public:
    // Constructor
    Authentication();

    // Core Functionalities
    void registerUser(const User& newUser);
    User* validateLogin(const string& email, const string& password);
    void forgotPassword(const string& email);

    // Utility
    void displayAllUsers() const;
};

#endif