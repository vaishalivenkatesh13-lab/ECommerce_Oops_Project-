#include "Authentication.h"
#include <stdexcept>

// Constructor
Authentication::Authentication() {}


// ---------------------- REGISTER USER ----------------------
void Authentication::registerUser(const User& newUser) {

    try {
        string email = newUser.getEmail();

        // Validate email
        if (email.empty()) {
            throw invalid_argument("Email cannot be empty");
        }

        if (email.find('@') == string::npos) {
            throw invalid_argument("Invalid email format");
        }

        // Check duplicate email
        for (const auto& u : users) {
            if (u.getEmail() == email) {
                throw runtime_error("Email already registered");
            }
        }

        // Add user
        users.push_back(newUser);
        cout << "[Auth] Registration successful!\n";
    }

    catch (const invalid_argument& e) {
        cout << "[Auth Input Error] " << e.what() << endl;
    }

    catch (const exception& e) {
        cout << "[Auth Error] " << e.what() << endl;
    }
}


// ---------------------- LOGIN VALIDATION ----------------------
User* Authentication::validateLogin(const string& email, const string& password) {

    try {
        if (email.empty()) {
            throw invalid_argument("Email cannot be empty");
        }

        if (password.empty()) {
            throw invalid_argument("Password cannot be empty");
        }

        if (users.empty()) {
            throw runtime_error("No users registered yet");
        }

        // Search user
        for (auto& u : users) {
            if (u.getEmail() == email) {
                u.login(password);   // Uses User class logic
                return &u;
            }
        }

        throw runtime_error("User not found");
    }

    catch (const invalid_argument& e) {
        cout << "[Auth Input Error] " << e.what() << endl;
        return nullptr;
    }

    catch (const exception& e) {
        cout << "[Auth Error] " << e.what() << endl;
        return nullptr;
    }
}


// ---------------------- FORGOT PASSWORD ----------------------
void Authentication::forgotPassword(const string& email) {

    try {
        if (email.empty()) {
            throw invalid_argument("Email cannot be empty");
        }

        for (auto& u : users) {
            if (u.getEmail() == email) {
                cout << "[Auth] Use 'Update Profile' to reset password.\n";
                return;
            }
        }

        throw runtime_error("Email not found");
    }

    catch (const invalid_argument& e) {
        cout << "[Auth Input Error] " << e.what() << endl;
    }

    catch (const exception& e) {
        cout << "[Auth Error] " << e.what() << endl;
    }
}


// ---------------------- DISPLAY USERS ----------------------
void Authentication::displayAllUsers() const {

    if (users.empty()) {
        cout << "[Auth] No users registered.\n";
        return;
    }

    cout << "\n--- Registered Users ---\n";

    for (const auto& u : users) {
        cout << "ID: " << u.getUserID()
             << " | Name: " << u.getName()
             << " | Email: " << u.getEmail()
             << endl;
    }
}