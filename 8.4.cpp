#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StudentRankingSystem
{
private:
    vector<pair<string, int>> studentRecords;

public:
    void addStudent()
    {
        string name;
        int score;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student score: ";
        cin >> score;
        studentRecords.push_back(make_pair(name, score));
    }

    void viewRankedStudents()
    {
        if (studentRecords.empty())
        {
            cout << "No student records found!" << endl;
            return;
        }

        sort(studentRecords.begin(), studentRecords.end(), [](const pair<string, int>& a, const pair<string, int>& b)
        {
            return a.second > b.second;  // Sort by score in descending order
        });

        cout << "\nRanked Students based on Scores:" << endl;
        int rank = 1;
        for (auto& student : studentRecords)
        {
            cout << "Rank " << rank << ": " << student.first << " - " << student.second << endl;
            rank++;
        }
    }
};

int main()
{
    StudentRankingSystem system;
    int choice;

    while (true)
    {
        cout << "\nStudent Ranking System\n";
        cout << "1. Add a student\n";
        cout << "2. View ranked students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addStudent();
            break;
        case 2:
            system.viewRankedStudents();
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
