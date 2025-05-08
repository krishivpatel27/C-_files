#include <iostream>
#include <string>

#define MAX_MANAGERS 100

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
};

class Employee : public Person {
protected:
    int empID;
public:
    Employee(string n = "", int a = 0, int id = 0) : Person(n, a), empID(id) {}
};

class Manager : public Employee {
private:
    string department;
public:
    Manager(string n = "", int a = 0, int id = 0, string dept = "") : Employee(n, a, id), department(dept) {}

    void display() const {
        cout << "Name: " << name << ", Age: " << age
             << ", Employee ID: " << empID
             << ", Department: " << department << endl;
    }

    int getID() const {
        return empID;
    }

    void setDetails(string n, int a, int id, string dept) {
        name = n;
        age = a;
        empID = id;
        department = dept;
    }
};

int main() {
    Manager managers[MAX_MANAGERS];
    int count = 0;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- Manager Management Menu ---\n";
        cout << "1. Add Manager\n";
        cout << "2. Display All Managers\n";
        cout << "3. Search Manager by Employee ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count >= MAX_MANAGERS) {
                    cout << "Manager limit reached.\n";
                    break;
                }
                {
                    string name, dept;
                    int age, id;
                    cout << "Enter Name: ";
                    cin.ignore(); // to clear the newline character
                    getline(cin, name);
                    cout << "Enter Age: ";
                    cin >> age;
                    cout << "Enter Employee ID: ";
                    cin >> id;
                    cout << "Enter Department: ";
                    cin.ignore();
                    getline(cin, dept);
                    managers[count].setDetails(name, age, id, dept);
                    count++;
                    cout << "Manager added successfully.\n";
                }
                break;

            case 2:
                if (count == 0) {
                    cout << "No managers to display.\n";
                    break;
                }
                for (int i = 0; i < count; ++i) {
                    managers[i].display();
                }
                break;

            case 3:
                if (count == 0) {
                    cout << "No managers in the system.\n";
                    break;
                }
                {
                    int searchID;
                    bool found = false;
                    cout << "Enter Employee ID to search: ";
                    cin >> searchID;
                    for (int i = 0; i < count; ++i) {
                        if (managers[i].getID() == searchID) {
                            cout << "Manager found:\n";
                            managers[i].display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Manager with ID " << searchID << " not found.\n";
                    }
                }
                break;

            case 4:
                running = false;
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
