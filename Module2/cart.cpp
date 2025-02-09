#include "grocery.h"
#include <iostream>  // for COUT
#include <vector>    // for VECTOR uses
#include <iomanip>   // for SETPRECISION()

using namespace std;

// Add item to cart
void Cart::addItem()
{
    string itemName;
    double itemPrice;

    cout << "Enter item name: ";
    getline(cin, itemName);

    cout << "Enter item price: $";
    cin >> itemPrice;

    if (itemPrice <= 0)
    {
        cout << "Invalid price. Try again.\n";
        return;
    }

    // push_back is used to insert the new item to the end of the items vector
    items.push_back({ itemName, itemPrice });
    cout << itemName << " added to cart.\n";
}

// View cart contents
void Cart::viewCart() const
{
    if (items.empty())
    {
        cout << "Your cart is empty.\n";
        return;
    }

    cout << "\nYour Cart:\n";
    // Loop works through items for display, using fixed & setprcision to control exact decimal places
    for (size_t i = 0; i < items.size(); i++)
    {
        cout << i + 1 << ". " << items[i].name << " - $" << fixed << setprecision(2) << items[i].price << endl;
    }
}

// Get total cost of cart
double Cart::getTotal() const
{
    double total = 0.0;
    for (const auto& item : items)
    {
        total += item.price;
    }
    return total;
}

// View total cost
void Cart::viewTotal() const
{
    cout << "Total: $" << fixed << setprecision(2) << getTotal() << endl;
}

// Clear cart after transaction
void Cart::clearCart()
{
    items.clear();
}

