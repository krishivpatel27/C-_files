#include <iostream>
#include <set>

using namespace std;

class TransactionManager {
private:
    set<int> uniqueTransactions;

public:
    void addTransaction() {
        int transactionID;
        cout << "Enter transaction ID: ";
        cin >> transactionID;
        uniqueTransactions.insert(transactionID);
        cout << "Transaction ID added successfully!" << endl;
    }

    void viewTransactions() {
        if (uniqueTransactions.empty()) {
            cout << "No transactions found!" << endl;
            return;
        }

        cout << "\nUnique Transaction IDs in sorted order:" << endl;
        for (auto it = uniqueTransactions.begin(); it != uniqueTransactions.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    TransactionManager manager;
    int choice;

    while (true) {
        cout << "\nTransaction Management System\n";
        cout << "1. Add a transaction\n";
        cout << "2. View unique transactions\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addTransaction();
                break;
            case 2:
                manager.viewTransactions();
                break;
            case 3:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

