#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class Item {
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    Item() {
        id = 0;
        name = "Unnamed";
        price = 0.0;
        quantity = 0;
    }

    void setDetails(int i, const string& n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void addStock(int q) {
        quantity += q;
    }

    void sellItem(int q) {
        if (q > quantity) {
            cout << "Error: Not enough stock available!" << endl;
        } else {
            quantity -= q;
            cout << "Sold " << q << " unit(s) of " << name << endl;
        }
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Price: $" << price << ", Stock: " << quantity << endl;
    }

    int getID() const {
        return id;
    }
};

int main() {
    Item inventory[MAX_ITEMS];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n===== Inventory Management Menu =====" << endl;
        cout << "1. Add New Item" << endl;
        cout << "2. Add Stock to Item" << endl;
        cout << "3. Sell Item" << endl;
        cout << "4. Display Inventory" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (count >= MAX_ITEMS) {
                cout << "Inventory limit reached." << endl;
                break;
            }

            int id, qty;
            float price;
            string name;

            cout << "Enter item ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> qty;

            inventory[count].setDetails(id, name, price, qty);
            count++;
            cout << "Item added successfully!" << endl;
            break;
        }

        case 2: {
            int id, qty;
            cout << "Enter item ID to add stock: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (inventory[i].getID() == id) {
                    cout << "Enter quantity to add: ";
                    cin >> qty;
                    inventory[i].addStock(qty);
                    cout << "Stock updated!" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found!" << endl;
            }
            break;
        }

        case 3: {
            int id, qty;
            cout << "Enter item ID to sell: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (inventory[i].getID() == id) {
                    cout << "Enter quantity to sell: ";
                    cin >> qty;
                    inventory[i].sellItem(qty);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found!" << endl;
            }
            break;
        }

        case 4:
            if (count == 0) {
                cout << "Inventory is empty." << endl;
            } else {
                cout << "\n--- Inventory Details ---" << endl;
                for (int i = 0; i < count; i++) {
                    inventory[i].display();
                }
            }
            break;

        case 5:
            cout << "Exiting program. Thank you!" << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}

