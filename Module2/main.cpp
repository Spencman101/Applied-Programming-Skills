#include "grocery.h"

int main()
{
    Grocery grocery;
    Cart cart;
    int userchoice;

    while (true)
    {
        // Display menu
        cout << "\nWelcome to the Supermarket Program!\n";
        cout << "Menu:\n";
        cout << "1 - Add Item To Cart\n";
        cout << "2 - View Cart\n";
        cout << "3 - View Total\n";
        cout << "4 - View Balance\n";
        cout << "5 - Add to Balance\n";
        cout << "6 - Process Transaction\n";
        cout << "7 - Exit\n";
        cout << "Select an option: ";
        cin >> userchoice;

        // switch is used to constantly iterate through user choices seamlessly and keeping code sussinct
        switch (userchoice)
        {
        case 1:
            cart.addItem();
            break;
        case 2:
            cart.viewCart();
            break;
        case 3:
            cart.viewTotal();
            break;
        case 4:
            grocery.displayBalance();
            break;
        case 5:
            grocery.updateBalance();
            break;
        case 6:
        {
            double total = cart.getTotal();
            if (total == 0)
            {
                cout << "Your cart is empty. Add items before processing a transaction.\n";
            }
            else
            {
                grocery.deductBalance(total);
                cart.clearCart();
            }
            break;
        }
        case 7:
            cout << "Thank you for shopping! Goodbye.\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
