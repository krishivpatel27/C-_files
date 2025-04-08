#include <iostream>
using namespace std;

template <typename T>
class Collection {
private:
    T* arr;
    int size;

public:
    Collection() {
        arr = nullptr;
        size = 0;
    }

    void create() {
        cout << "Enter size of collection: ";
        cin >> size;
        while (size <= 0) {
            cout << "Invalid size. Enter a positive number: ";
            cin >> size;
        }

        arr = new T[size];
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        if (size == 0 || arr == nullptr) {
            cout << "Collection is empty.\n";
            return;
        }
        cout << "Collection elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    T findMax() {
        if (size == 0 || arr == nullptr) {
            cout << "Collection is empty. Cannot find max.\n";
            return T();
        }
        T maxVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
        return maxVal;
    }

    void reverse() {
        if (size == 0 || arr == nullptr) {
            cout << "Collection is empty. Cannot reverse.\n";
            return;
        }
        for (int i = 0; i < size / 2; i++) {
            T temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
        cout << "Collection reversed.\n";
    }

    ~Collection() {
        if (arr != nullptr) {
            delete[] arr;
        }
    }
};

int main() {
    int choice;

menu:
    cout << "\n======= COLLECTION MENU =======\n";
    cout << "1. Integer Collection\n";
    cout << "2. Float Collection\n";
    cout << "3. Character Collection\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        Collection<int> col;
        col.create();
    intMenu:
        cout << "\n-- Integer Operations --\n";
        cout << "1. Display\n2. Find Max\n3. Reverse\n4. Back\n";
        cout << "Enter operation: ";
        cin >> choice;
        switch (choice) {
        case 1: col.display(); goto intMenu;
        case 2: cout << "Max value: " << col.findMax() << "\n"; goto intMenu;
        case 3: col.reverse(); goto intMenu;
        case 4: goto menu;
        default: cout << "Invalid choice.\n"; goto intMenu;
        }
    }

    case 2: {
        Collection<float> col;
        col.create();
    floatMenu:
        cout << "\n-- Float Operations --\n";
        cout << "1. Display\n2. Find Max\n3. Reverse\n4. Back\n";
        cout << "Enter operation: ";
        cin >> choice;
        switch (choice) {
        case 1: col.display(); goto floatMenu;
        case 2: cout << "Max value: " << col.findMax() << "\n"; goto floatMenu;
        case 3: col.reverse(); goto floatMenu;
        case 4: goto menu;
        default: cout << "Invalid choice.\n"; goto floatMenu;
        }
    }

    case 3: {
        Collection<char> col;
        col.create();
    charMenu:
        cout << "\n-- Character Operations --\n";
        cout << "1. Display\n2. Find Max (lexicographically)\n3. Reverse\n4. Back\n";
        cout << "Enter operation: ";
        cin >> choice;
        switch (choice) {
        case 1: col.display(); goto charMenu;
        case 2: cout << "Max value: " << col.findMax() << "\n"; goto charMenu;
        case 3: col.reverse(); goto charMenu;
        case 4: goto menu;
        default: cout << "Invalid choice.\n"; goto charMenu;
        }
    }

    case 4:
        cout << "Exiting program.\n";
        break;

    default:
        cout << "Invalid choice. Try again.\n";
        goto menu;
    }

    return 0;
}

