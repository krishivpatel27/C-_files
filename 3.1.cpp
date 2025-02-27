#include <iostream>
using namespace std;

class EmployeeDetail {
    char name[20];
    double salary;
    double bonus;

public:
    EmployeeDetail(char* name = "", double salary = 0.0, double bonus = 0.0) {
        int i = 0;
        for (i = 0; i < 19; i++) {
            if (name[i] == '\0') {
                break;
            }
            this->name[i] = name[i];
        }
        this->name[i] = '\0';
        this->salary = salary;
        this->bonus = (bonus != 0) ? bonus : 0.1 * salary;
    }

    inline double TotalSalary() {
        return salary + bonus;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: $" << salary << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Salary: $" << TotalSalary() << endl;
    }

    void inputDetails() {
        cout << "Enter employee's name: ";
        cin.ignore();
        cin.getline(name, 20);
        cout << "Enter basic salary: $";
        cin >> salary;
        cout << "Enter bonus amount: $";
        cin >> bonus;
    }
};

int main() {
    int choice, i = 0;
    EmployeeDetail E[10];
next:
    cout << "Menu:\n";
    cout << "1. Add Employee\n";
    cout << "2. Display Employee Details\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            E[i].inputDetails();
            i++;
            goto next;

        case 2:
            for (int j = 0; j < i; j++) {
                E[j].displayDetails();
            }
            goto next;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            goto next;
    }

    return 0;
}
