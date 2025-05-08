#include <iostream>
#include <string>

#define MAX_TRANSACTIONS 100
#define MAX_ACCOUNTS 10

using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;
    double transactions[MAX_TRANSACTIONS];
    int transactionCount;
public:
    BankAccount(int accNo = 0, double bal = 0.0) {
        accountNumber = accNo;
        balance = bal;
        transactionCount = 0;
    }

    virtual ~BankAccount() {
        cout << "Account " << accountNumber << " closed.\n";
    }

    virtual void deposit(double amount) {
        if (amount > 0 && transactionCount < MAX_TRANSACTIONS) {
            balance += amount;
            transactions[transactionCount++] = amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Deposit failed.\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance && transactionCount < MAX_TRANSACTIONS) {
            balance -= amount;
            transactions[transactionCount++] = -amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Withdrawal failed.\n";
        }
    }

    virtual void undoLastTransaction() {
        if (transactionCount == 0) {
            cout << "No transaction to undo.\n";
            return;
        }
        double last = transactions[--transactionCount];
        balance -= last;
        cout << "Undid last transaction (" << last << "), New Balance: " << balance << endl;
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(int accNo = 0, double bal = 0.0, double rate = 0.05)
        : BankAccount(accNo, bal), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate;
        deposit(interest);
        cout << "Interest applied: " << interest << endl;
    }

    void display() const override {
        BankAccount::display();
        cout << "Account Type: Savings, Interest Rate: " << interestRate << endl;
    }
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(int accNo = 0, double bal = 0.0, double limit = 500.0)
        : BankAccount(accNo, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance + overdraftLimit) >= amount && transactionCount < MAX_TRANSACTIONS) {
            balance -= amount;
            transactions[transactionCount++] = -amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Withdrawal failed. Overdraft limit exceeded.\n";
        }
    }

    void display() const override {
        BankAccount::display();
        cout << "Account Type: Current, Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    BankAccount* accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    bool running = true;

    while (running) {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Current Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Undo Last Transaction\n";
        cout << "6. Display Account Info\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int accNo;
        double amount;

        switch (choice) {
            case 1:
                if (accountCount >= MAX_ACCOUNTS) {
                    cout << "Account limit reached.\n";
                    break;
                }
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Initial Balance: ";
                cin >> amount;
                accounts[accountCount++] = new SavingsAccount(accNo, amount);
                cout << "Savings account created.\n";
                break;

            case 2:
                if (accountCount >= MAX_ACCOUNTS) {
                    cout << "Account limit reached.\n";
                    break;
                }
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Initial Balance: ";
                cin >> amount;
                accounts[accountCount++] = new CurrentAccount(accNo, amount);
                cout << "Current account created.\n";
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                for (int i = 0; i < accountCount; ++i) {
                    if (accounts[i]->getAccountNumber() == accNo) {
                        accounts[i]->deposit(amount);
                        break;
                    }
                }
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                for (int i = 0; i < accountCount; ++i) {
                    if (accounts[i]->getAccountNumber() == accNo) {
                        accounts[i]->withdraw(amount);
                        break;
                    }
                }
                break;

            case 5:
                cout << "Enter Account Number: ";
                cin >> accNo;
                for (int i = 0; i < accountCount; ++i) {
                    if (accounts[i]->getAccountNumber() == accNo) {
                        accounts[i]->undoLastTransaction();
                        break;
                    }
                }
                break;

            case 6:
                cout << "Enter Account Number: ";
                cin >> accNo;
                for (int i = 0; i < accountCount; ++i) {
                    if (accounts[i]->getAccountNumber() == accNo) {
                        accounts[i]->display();
                        break;
                    }
                }
                break;

            case 7:
                running = false;
                for (int i = 0; i < accountCount; ++i) {
                    delete accounts[i];
                }
                cout << "Exiting system. All accounts closed.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
