#include "grocery.h"

// Display the current balance
void Grocery::displayBalance() const
{
    cout << fixed << setprecision(2);
    cout << "Current balance: $" << balance << endl;
}

// Read balance from file
double Grocery::readBalance()
{
    ifstream fin(FILENAME);
    if (fin.fail())
    {
        cout << "Could not open " << FILENAME << ". Starting with $0.00 balance.\n";
        return 0.0;
    }

    double storedBalance;
    fin >> storedBalance;
    fin.close();
    return storedBalance;
}

// Write balance to file
void Grocery::writeBalance()
{
    ofstream fout(FILENAME);
    if (fout.fail())
    {
        cout << "Error: Unable to save balance to file.\n";
        return;
    }

    fout << balance << endl;
    fout.close();
}

// Update balance (add funds)
void Grocery::updateBalance()
{
    double amount;
    cout << "Enter amount to add: $";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount. Try again.\n";
        return;
    }

    balance += amount;
    writeBalance();
    cout << "Balance updated. New balance: $" << fixed << setprecision(2) << balance << endl;
}

// Deduct balance for transactions
void Grocery::deductBalance(double amount)
{
    if (amount > balance)
    {
        cout << "Insufficient funds. Transaction failed.\n";
        return;
    }

    balance -= amount;
    writeBalance();
    cout << "Transaction successful. Remaining balance: $" << fixed << setprecision(2) << balance << endl;
}
