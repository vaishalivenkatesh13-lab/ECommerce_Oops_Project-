// ============================================================
//  E-Commerce Management System
//  File    : main.cpp
//  Purpose : Entry point — launches the ECommerceSystem
//
//  OOP Concepts Demonstrated:
//    - Encapsulation  : All class data is private
//    - Inheritance    : Customer / Admin extend User
//    - Polymorphism   : displayProfile() is virtual
//    - Abstraction    : ECommerceSystem hides all module details
//    - Exception Handling : Authentication.cpp, Payment.cpp, Delivery.cpp
//    - STL            : vector<User>, map<int,Product>
// ============================================================

#include "ECommerceSystem.h"
#include <iostream>
using namespace std;

int main() {

    // ECommerceSystem aggregates all modules:
    //   Authentication, Product, Customer, Admin,
    //   Cart, Order, Payment, Delivery
    ECommerceSystem system;

    // Launch interactive terminal-based system
    system.startSystem();

    return 0;
}
