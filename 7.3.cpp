#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Product {
    string name;
    int quantity;
    double price;

    void input() {
        cout << "Enter product name: ";
        cin.ignore(); // To ignore leftover newline from previous input
        getline(cin, name);
        cout << "Enter product quantity: ";
        cin >> quantity;
        cout << "Enter product price: ";
        cin >> price;
    }

    void display() const {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }

    string to_string() const {
        stringstream ss;
        ss << name << "," << quantity << "," << price;
        return ss.str();
    }

    static Product from_string(const string& str) {
        stringstream ss(str);
        Product product;
        getline(ss, product.name, ',');
        ss >> product.quantity;
        ss.ignore(1); // Ignore the comma after quantity
        ss >> product.price;
        return product;
    }
};

class InventoryManager {
private:
    const string filename = "inventory.txt";

public:
    void addProduct() {
        Product product;
        product.input();
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << product.to_string() << endl;
            cout << "Product added successfully!" << endl;
        } else {
            cout << "Failed to open the file!" << endl;
        }
    }

    void viewInventory() {
        ifstream file(filename);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                Product product = Product::from_string(line);
                product.display();
            }
        } else {
            cout << "Failed to open the file!" << endl;
        }
    }

    void searchProduct() {
        string searchName;
        cout << "Enter product name to search: ";
        cin.ignore(); // To ignore leftover newline from previous input
        getline(cin, searchName);

        ifstream file(filename);
        string line;
        bool found = false;

        if (file.is_open()) {
            while (getline(file, line)) {
                Product product = Product::from_string(line);
                if (product.name == searchName) {
                    product.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Product not found!" << endl;
            }
        } else {
            cout << "Failed to open the file!" << endl;
        }
    }
};

int main() {
    InventoryManager manager;
    int choice;

    while (true) {
        cout << "\nInventory Management System\n";
        cout << "1. Add a product\n";
        cout << "2. View inventory\n";
        cout << "3. Search for a product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addProduct();
                break;
            case 2:
                manager.viewInventory();
                break;
            case 3:
                manager.searchProduct();
                break;
            case 4:
                cout << "Exiting the system.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

