#include "Authentication.h"
#include <stdexcept>
using namespace std;

// Constructor
Authentication::Authentication() {}

Authentication::~Authentication() {
    for (auto u : users) {
        delete u;
    }
    users.clear();
}


// ─── Register User ───────────────────────────────────────────────────────────
void Authentication::registerUser(User* newUser) {

    try {
        if (!newUser) throw invalid_argument("Null user provided.");
        string email = newUser->getEmail();
        string phone = newUser->getPhone();

        if (email.empty()) {
            throw invalid_argument("Email cannot be empty.");
        }
        if (email.find('@') == string::npos) {
            throw invalid_argument("Invalid email format.");
        }

        // Phone validation
        if (phone.length() != 10) {
            throw invalid_argument("Invalid Phone format: Must be exactly 10 digits.");
        }
        for (char c : phone) {
            if (!isdigit(c)) {
                throw invalid_argument("Invalid Phone format: Must contain only numbers.");
            }
        }

        // Check for duplicate email
        for (const auto* u : users) {
            if (u->getEmail() == email) {
                delete newUser; // Prevent memory leak since it won't be stored
                throw runtime_error("Email already registered.");
            }
        }

        users.push_back(newUser);
        cout << "  [Auth] Registration successful!\n";
    }
    catch (const invalid_argument& e) {
        cout << "  [Auth Input Error] " << e.what() << endl;
        if (newUser) {
            bool exists = false;
            for (auto* u : users) {
                if (u == newUser) exists = true;
            }
            if (!exists) delete newUser;
        }
    }
    catch (const exception& e) {
        cout << "  [Auth Error] " << e.what() << endl;
        // newUser already deleted if it's a runtime_error for duplicate email, but catch-all safety:
    }
}


// ─── Validate Login ──────────────────────────────────────────────────────────
User* Authentication::validateLogin(const string& email, const string& password) {

    try {
        if (email.empty()) {
            throw invalid_argument("Email cannot be empty.");
        }
        if (password.empty()) {
            throw invalid_argument("Password cannot be empty.");
        }
        if (users.empty()) {
            throw runtime_error("No users registered yet. Please register first.");
        }

        for (auto* u : users) {
            if (u->getEmail() == email) {
                u->login(password);   // Uses User::login() logic
                return u;
            }
        }

        throw runtime_error("User not found. Please register first.");
    }
    catch (const invalid_argument& e) {
        cout << "  [Auth Input Error] " << e.what() << endl;
        return nullptr;
    }
    catch (const exception& e) {
        cout << "  [Auth Error] " << e.what() << endl;
        return nullptr;
    }
}


// ─── Forgot Password ─────────────────────────────────────────────────────────
void Authentication::forgotPassword(const string& email) {

    try {
        if (email.empty()) {
            throw invalid_argument("Email cannot be empty.");
        }
        for (auto* u : users) {
            if (u->getEmail() == email) {
                cout << "  [Auth] Account found. Use 'Update Profile' to reset password.\n";
                return;
            }
        }
        throw runtime_error("Email not found.");
    }
    catch (const invalid_argument& e) {
        cout << "  [Auth Input Error] " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "  [Auth Error] " << e.what() << endl;
    }
}


// ─── Display All Users ───────────────────────────────────────────────────────
void Authentication::displayAllUsers() const {

    if (users.empty()) {
        cout << "  [Auth] No users registered yet.\n";
        return;
    }

    cout << "\n  --- Registered Users -------------\n";
    for (const auto* u : users) {
        cout << "  ID: "    << u->getUserID()
             << " | Name: " << u->getName()
             << " | Email: "<< u->getEmail()
             << " | Role: " << u->getRole()
             << endl;
    }
}
