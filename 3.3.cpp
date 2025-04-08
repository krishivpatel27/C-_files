#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

class Account {
    int accNumber;
    string accHolder;
    double balance;

public:
    static int totalAccounts;

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNumber;
        cin.ignore();
        cout << "Enter Account Holder's Name: ";
        getline(cin, accHolder);
        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0) {
            cout << "Initial balance cannot be negative.\n";
            return;
        }

        totalAccounts++;
        cout << "Account created successfully!\n";
    }

    void displayAccount() const {
        cout << "\nAccount Number: " << accNumber;
        cout << "\nAccount Holder: " << accHolder;
        cout << "\nBalance: " << balance << "\n";
    }

    int getAccountNumber() const {
        return accNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amt) {
        if (amt > 0)
            balance += amt;
    }

    bool withdraw(double amt) {
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            return true;
        }
        return false;
    }
};

int Account::totalAccounts = 0;
Account accounts[MAX_ACCOUNTS];

int findAccount(int accNum) {
    for (int i = 0; i < Account::totalAccounts; i++) {
        if (accounts[i].getAccountNumber() == accNum)
            return i;
    }
    return -1;
}

int main() {
    int choice;

menu:
    cout << "\n====== BANK MENU ======\n";
    cout << "1. Create New Account\n";
    cout << "2. Display All Accounts\n";
    cout << "3. Transfer Money\n";
    cout << "4. Show Total Accounts\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        if (Account::totalAccounts >= MAX_ACCOUNTS) {
            cout << "Account limit reached.\n";
        } else {
            accounts[Account::totalAccounts].createAccount();
        }
        goto menu;

    case 2:
        if (Account::totalAccounts == 0) {
            cout << "No accounts to display.\n";
        } else {
            for (int i = 0; i < Account::totalAccounts; i++) {
                accounts[i].displayAccount();
            }
        }
        goto menu;

    case 3: {
        int fromAcc, toAcc;
        double amount;

        cout << "Enter From Account Number: ";
        cin >> fromAcc;
        cout << "Enter To Account Number: ";
        cin >> toAcc;
        cout << "Enter Amount to Transfer: ";
        cin >> amount;

        int fromIndex = findAccount(fromAcc);
        int toIndex = findAccount(toAcc);

        if (fromIndex == -1 || toIndex == -1) {
            cout << "Invalid account number(s).\n";
        } else if (!accounts[fromIndex].withdraw(amount)) {
            cout << "Insufficient balance or invalid amount.\n";
        } else {
            accounts[toIndex].deposit(amount);
            cout << "Transfer successful.\n";
        }
        goto menu;
    }

    case 4:
        cout << "Total Accounts Created: " << Account::totalAccounts << "\n";
        goto menu;

    case 5:
        cout << "Exiting system. Thank you!\n";
        break;

    default:
        cout << "Invalid choice. Try again.\n";
        goto menu;
    }

    return 0;
}
