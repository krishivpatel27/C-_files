#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class DirectoryManagementSystem {
private:
    map<string, vector<string>> directory;

public:
    void addFolder() {
        string folderName;
        cout << "Enter folder name: ";
        cin >> folderName;

        if (directory.find(folderName) != directory.end()) {
            cout << "Folder already exists!" << endl;
        } else {
            directory[folderName] = {};  // Create an empty list of files for the new folder
            cout << "Folder created successfully!" << endl;
        }
    }

    void addFileToFolder() {
        string folderName, fileName;
        cout << "Enter folder name: ";
        cin >> folderName;

        if (directory.find(folderName) == directory.end()) {
            cout << "Folder does not exist!" << endl;
            return;
        }

        cout << "Enter file name: ";
        cin >> fileName;

        directory[folderName].push_back(fileName);
        cout << "File added successfully to folder " << folderName << "!" << endl;
    }

    void displayDirectoryStructure() {
        if (directory.empty()) {
            cout << "No folders available!" << endl;
            return;
        }

        cout << "\nDirectory Structure:" << endl;
        for (const auto& folder : directory) {
            cout << "Folder: " << folder.first << endl;
            cout << "Files: ";
            for (const auto& file : folder.second) {
                cout << file << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DirectoryManagementSystem system;
    int choice;

    while (true) {
        cout << "\nDirectory Management System\n";
        cout << "1. Add a folder\n";
        cout << "2. Add a file to a folder\n";
        cout << "3. Display directory structure\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addFolder();
                break;
            case 2:
                system.addFileToFolder();
                break;
            case 3:
                system.displayDirectoryStructure();
                break;
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

