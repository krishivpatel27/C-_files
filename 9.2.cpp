#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>  // for std::numeric_limits

using namespace std;

class BankAccount {
private:
    double balance;
    string transactionHistory[10];  // Fixed-size array to store transaction history
    int transactionCount;

public:
    BankAccount() : balance(0), transactionCount(0) {}

    void deposit(double amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Deposit amount must be positive.");
            }
            balance += amount;
            logTransaction("Deposited " + to_string(amount));
        } catch (const invalid_argument& e) {
            logTransaction("Error: " + string(e.what()));
            throw;
        }
    }

    void withdraw(double amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Withdrawal amount must be positive.");
            }
            if (amount > balance) {
                throw runtime_error("Insufficient funds.");
            }
            balance -= amount;
            logTransaction("Withdrew " + to_string(amount));
        } catch (const invalid_argument& e) {
            logTransaction("Error: " + string(e.what()));
            throw;
        } catch (const runtime_error& e) {
            logTransaction("Error: " + string(e.what()));
            throw;
        }
    }

    double getBalance() const {
        return balance;
    }

    void printTransactionHistory() const {
        cout << "Transaction History:\n";
        for (int i = 0; i < transactionCount; ++i) {
            cout << transactionHistory[i] << endl;
        }
    }

private:
    void logTransaction(const string& transaction) {
        if (transactionCount < 10) {
            transactionHistory[transactionCount++] = transaction;
        } else {
            for (int i = 1; i < 10; ++i) {
                transactionHistory[i - 1] = transactionHistory[i];
            }
            transactionHistory[9] = transaction;
        }
    }
};

int main() {
    BankAccount account;
    double amount;
    int option;

    while (true) {
        cout << "\n--- Bank Account Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Balance\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Please choose an option: ";
        cin >> option;

        try {
            switch (option) {
                case 1:
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    if (!cin) {
                        throw invalid_argument("Invalid input! Please enter a valid number.");
                    }
                    account.deposit(amount);
                    break;
                case 2:
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    if (!cin) {
                        throw invalid_argument("Invalid input! Please enter a valid number.");
                    }
                    account.withdraw(amount);
                    break;
                case 3:
                    cout << "Current balance: $" << account.getBalance() << endl;
                    break;
                case 4:
                    account.printTransactionHistory();
                    break;
                case 5:
                    cout << "Exiting the system.\n";
                    return 0;
                default:
                    cout << "Invalid option. Please choose again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            // Clear the error state and ignore the invalid input.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}

