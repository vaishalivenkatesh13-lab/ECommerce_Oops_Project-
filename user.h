#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {

private:
    int    userID;
    string name;
    string email;
    string password;
    string phone;
    bool   isLoggedIn;

public:
    // Constructors
    User();
    User(int id, const string& name, const string& email,
         const string& password, const string& phone);
    User(const User& other);

    // Destructor
    virtual ~User();

    // Getters
    int    getUserID()      const;
    string getName()        const;
    string getEmail()       const;
    string getPhone()       const;
    bool   getLoginStatus() const;

    // Setters
    void setName(const string& newName);
    void setEmail(const string& newEmail);
    void setPhone(const string& newPhone);
    void setPassword(const string& newPassword);

    // Core behaviour
    void login(const string& enteredPassword);
    void logout();

    virtual void displayProfile() const;  
    void updateProfile();
};

#endif