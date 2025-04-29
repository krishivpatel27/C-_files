#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Student {
    string name;
    double marks;
    string grade;
    double tuition;
};

ostream& currency(ostream& os) {
    os << "Rs";
    return os;
}

int readStudentData(const string& filename, Student* students, int maxSize) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Cannot open file " << filename << endl;
        return 0;
    }

    string firstName, lastName, grade;
    double marks, tuition;
    int count = 0;

    while (file >> firstName >> lastName >> marks >> grade >> tuition && count < maxSize) {
        students[count].name = firstName + " " + lastName;
        students[count].marks = marks;
        students[count].grade = grade;
        students[count].tuition = tuition;
        count++;
    }

    return count;
}

void displayReport(Student* students, int count) {
    cout << left << setw(20) << "Name"
         << right << setw(10) << "Marks"
         << setw(8) << "Grade"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(53) << "-" << setfill(' ') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(20) << students[i].name
             << right << fixed << setprecision(2)
             << setw(10) << students[i].marks
             << setw(8) << students[i].grade
             << setw(6) << currency << setw(9) << students[i].tuition
             << endl;
    }
}

int main() {
    const int MAX_STUDENTS = 100;
    Student* students = new Student[MAX_STUDENTS];

    int count = readStudentData("students.txt", students, MAX_STUDENTS);
    if (count > 0) {
        displayReport(students, count);
    }

    delete[] students;
    return 0;
}

