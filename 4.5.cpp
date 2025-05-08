#include <iostream>
#include <string>

#define MAX_STUDENTS 10

using namespace std;

class GradingSystem {
protected:
    string studentName;
    double marks;
public:
    GradingSystem(string name, double m) : studentName(name), marks(m) {}
    virtual void computeGrade() = 0;
    void display() const {
        cout << "Student: " << studentName << ", Marks: " << marks << " - Grade: ";
        computeGrade();
    }
};

class Undergraduate : public GradingSystem {
public:
    Undergraduate(string name, double m) : GradingSystem(name, m) {}
    void computeGrade() override {
        if (marks >= 90) {
            cout << "A+" << endl;
        } else if (marks >= 80) {
            cout << "A" << endl;
        } else if (marks >= 70) {
            cout << "B+" << endl;
        } else if (marks >= 60) {
            cout << "B" << endl;
        } else if (marks >= 50) {
            cout << "C+" << endl;
        } else if (marks >= 40) {
            cout << "C" << endl;
        } else {
            cout << "F" << endl;
        }
    }
};

class Postgraduate : public GradingSystem {
public:
    Postgraduate(string name, double m) : GradingSystem(name, m) {}
    void computeGrade() override {
        if (marks >= 85) {
            cout << "A+" << endl;
        } else if (marks >= 75) {
            cout << "A" << endl;
        } else if (marks >= 65) {
            cout << "B+" << endl;
        } else if (marks >= 55) {
            cout << "B" << endl;
        } else if (marks >= 45) {
            cout << "C+" << endl;
        } else {
            cout << "F" << endl;
        }
    }
};

int main() {
    GradingSystem* students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    string name;
    double marks;
    bool running = true;

    while (running) {
        cout << "\n--- Grading System Menu ---\n";
        cout << "1. Add Undergraduate Student\n";
        cout << "2. Add Postgraduate Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Account limit reached.\n";
                    break;
                }
                cout << "Enter Undergraduate Student Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Marks (0-100): ";
                cin >> marks;
                students[studentCount++] = new Undergraduate(name, marks);
                cout << "Undergraduate student added.\n";
                break;

            case 2:
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Account limit reached.\n";
                    break;
                }
                cout << "Enter Postgraduate Student Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Marks (0-100): ";
                cin >> marks;
                students[studentCount++] = new Postgraduate(name, marks);
                cout << "Postgraduate student added.\n";
                break;

            case 3:
                if (studentCount == 0) {
                    cout << "No student records available.\n";
                } else {
                    cout << "\n--- Student Records ---\n";
                    for (int i = 0; i < studentCount; ++i) {
                        students[i]->display();
                    }
                }
                break;

            case 4:
                running = false;
                for (int i = 0; i < studentCount; ++i) {
                    delete students[i];
                }
                cout << "Exiting system. All records deleted.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
