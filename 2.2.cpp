#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll_number;
    string name;
    int marks1, marks2, marks3;

public:
    Student() {
        roll_number = -1;
        name = "Rahul";
        marks1 = marks2 = marks3 = 0;
    }

    Student(int r, string n, int m1, int m2, int m3) {
        roll_number = r;
        name = n;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }

    float calculateAverage() {
        return (marks1 + marks2 + marks3) / 3.0;
    }

    void displayDetails() {
        cout << "Roll Number: " << roll_number << endl;
        cout << "Name: " << name << endl;
        cout << "Marks in Subject 1: " << marks1 << endl;
        cout << "Marks in Subject 2: " << marks2 << endl;
        cout << "Marks in Subject 3: " << marks3 << endl;
        cout << "Average Marks: " << calculateAverage() << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    const int MAX = 10;
    Student students[MAX];
    int studentCount = 0;
    int choice;

menu:
    cout << "\n===== Student Record Menu =====\n";
    cout << "1. Add Default Students (Using Loop)\n";
    cout << "2. Add Student (With Input)\n";
    cout << "3. Display All Students\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int num;
            cout << "How many default students to add? ";
            cin >> num;

            if (num <= 0) {
                cout << "Please enter a valid positive number.\n";
            } else if (studentCount + num <= MAX) {
                for (int i = 0; i < num; i++) {
                    students[studentCount] = Student();
                    studentCount++;
                }
                cout << num << " default students added successfully.\n";
            } else {
                cout << "Not enough space to add " << num << " students.\n";
            }
            goto menu;
        }

        case 2: {
            if (studentCount < MAX) {
                int roll, m1, m2, m3;
                string name;
                cout << "Enter Roll Number: ";
                cin >> roll;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Marks in Subject 1: ";
                cin >> m1;
                cout << "Enter Marks in Subject 2: ";
                cin >> m2;
                cout << "Enter Marks in Subject 3: ";
                cin >> m3;
                students[studentCount] = Student(roll, name, m1, m2, m3);
                studentCount++;
                cout << "Student added successfully.\n";
            } else {
                cout << "Student limit reached.\n";
            }
            goto menu;
        }

        case 3: {
            if (studentCount == 0) {
                cout << "No student records to display.\n";
            } else {
                cout << "\n--- All Student Records ---\n";
                for (int i = 0; i < studentCount; i++) {
                    students[i].displayDetails();
                }
            }
            goto menu;
        }

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            goto menu;
    }

    return 0;
}

