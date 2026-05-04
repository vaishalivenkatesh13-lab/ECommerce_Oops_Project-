#include "User.h"
#include <limits>

// --- Constructors ------------------------------------------------------------

User::User()
    : role("User"), userID(0), name(""), email(""), password(""), phone(""),
      isLoggedIn(false)
{
}

User::User(int id, const string& name, const string& email,
           const string& password, const string& phone, const string& role)
    : role(role), userID(id), name(name), email(email),
      password(password), phone(phone), isLoggedIn(false)
{
}

User::User(const User& other)
    : role(other.role), userID(other.userID), name(other.name), email(other.email),
      password(other.password), phone(other.phone),
      isLoggedIn(other.isLoggedIn)
{
}

// Destructor
User::~User() {
}

// --- Getters -----------------------------------------------------------------

int User::getUserID() const {
    return userID;
}

string User::getName() const {
    return name;
}

string User::getEmail() const {
    return email;
}

string User::getPhone() const {
    return phone;
}

bool User::getLoginStatus() const {
    return isLoggedIn;
}

string User::getRole() const {
    return role;
}

// --- Setters -----------------------------------------------------------------

void User::setName(const string& newName) {
    if (!newName.empty()) {
        name = newName;
    } else {
        cout << "[User] Error: Name cannot be empty." << endl;
    }
}

void User::setEmail(const string& newEmail) {
    if (newEmail.find('@') != string::npos) {
        email = newEmail;
    } else {
        cout << "[User] Error: Invalid email format." << endl;
    }
}

void User::setPhone(const string& newPhone) {
    if (newPhone.length() != 10) {
        cout << "  [User] Error: Phone must be exactly 10 digits." << endl;
        return;
    }
    for (char c : newPhone) {
        if (!isdigit(c)) {
            cout << "  [User] Error: Phone must contain only numbers." << endl;
            return;
        }
    }
    phone = newPhone;
    cout << "  [User] Phone updated successfully." << endl;
}

void User::setPassword(const string& newPassword) {
    if (newPassword.length() >= 6) {
        password = newPassword;
        cout << "[User] Password updated successfully." << endl;
    } else {
        cout << "[User] Error: Password must be at least 6 characters." << endl;
    }
}

// --- Login / Logout ----------------------------------------------------------

void User::login(const string& enteredPassword) {
    if (isLoggedIn) {
        cout << "[User] " << name << " is already logged in." << endl;
        return;
    }
    if (enteredPassword == password) {
        isLoggedIn = true;
        cout << "[User] Login successful. Welcome, " << name << "!" << endl;
    } else {
        cout << "[User] Login failed. Incorrect password." << endl;
    }
}

void User::logout() {
    if (isLoggedIn) {
        isLoggedIn = false;
        cout << "[User] " << name << " has logged out." << endl;
    } else {
        cout << "[User] " << name << " is not currently logged in." << endl;
    }
}

// --- Display Profile (virtual - overridden in Customer & Admin) --------------

void User::displayProfile() const {
    cout << "\n  -----------------------------" << endl;
    cout << "    User Profile"                  << endl;
    cout << "  -----------------------------" << endl;
    cout << "  ID     : " << userID             << endl;
    cout << "  Name   : " << name               << endl;
    cout << "  Email  : " << email              << endl;
    cout << "  Phone  : " << phone              << endl;
    cout << "  Status : " << (isLoggedIn ? "Logged In" : "Logged Out") << endl;
    cout << "  -----------------------------" << endl;
}

// --- Update Profile ----------------------------------------------------------

void User::updateProfile() {
    int choice;
    cout << "\n  [Update Profile]" << endl;
    cout << "  1. Update Name"    << endl;
    cout << "  2. Update Email"   << endl;
    cout << "  3. Update Phone"   << endl;
    cout << "  4. Update Password"<< endl;
    cout << "  Enter choice: ";

    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string input;
    switch (choice) {
        case 1:
            cout << "  Enter new name: ";
            getline(cin, input);
            setName(input);
            break;
        case 2:
            cout << "  Enter new email: ";
            getline(cin, input);
            setEmail(input);
            break;
        case 3:
            cout << "  Enter new phone (10 digits): ";
            getline(cin, input);
            setPhone(input);
            break;
        case 4:
            cout << "  Enter new password (min 6 chars): ";
            getline(cin, input);
            setPassword(input);
            break;
        default:
            cout << "  [User] Invalid choice." << endl;
    }
}
