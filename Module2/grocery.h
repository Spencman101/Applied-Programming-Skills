#ifndef GROCERY_H
#define GROCERY_H

#include <fstream>   // for FILE inputing
#include <string>    // for STORING text
#include <iostream>  // for COUT
#include <vector>    // for VECTOR uses
#include <iomanip>   // for SETPRECISION()

#define FILENAME "data.txt"

using namespace std;

// Item structure for cart items
struct Item
{
    string name;
    double price;
};

// Grocery class (handles balance)
class Grocery
{
private:
    double balance;

public:
    Grocery() { balance = readBalance(); } // Load balance from file automatically

    void displayBalance() const;
    double getBalance() const { return balance; }
    double readBalance();
    void writeBalance();
    void updateBalance();
    void deductBalance(double amount);
};

// Cart class (handles shopping cart)
class Cart
{
private:
    vector<Item> items;

public:
    void addItem();
    void viewCart() const;
    double getTotal() const;
    void viewTotal() const;
    void clearCart();
};

#endif
