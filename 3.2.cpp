
#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int* arr;
    int size;

public:
    ArrayOperations() {
        arr = nullptr;
        size = 0;
    }

    void setSize(int s) {
        if (s <= 0) {
            cout << "Invalid size. Must be greater than 0.\n";
            return;
        }
        if (arr != nullptr) {
            delete[] arr;
        }
        size = s;
        arr = new int[size];
    }

    void inputElements(int index = 0) {
        if (arr == nullptr || size == 0) {
            cout << "Array not initialized. Please input size first.\n";
            return;
        }
        if (index == size) return;

        cout << "Enter element " << index + 1 << ": ";
        cin >> arr[index];
        inputElements(index + 1);
    }

    void displayElements(int index = 0) {
        if (arr == nullptr || size == 0) {
            cout << "Array not initialized. Please input size first.\n";
            return;
        }
        if (index == size) {
            cout << endl;
            return;
        }
        cout << arr[index] << " ";
        displayElements(index + 1);
    }

    int computeSum(int index = 0) {
        if (arr == nullptr || size == 0) {
            cout << "Array not initialized. Please input size first.\n";
            return 0;
        }
        if (index == size) return 0;
        return arr[index] + computeSum(index + 1);
    }

    ~ArrayOperations() {
        delete[] arr;
    }
};

int main() {
    ArrayOperations obj;
    int choice;
    int size;

menu:
    cout << "\n===== MENU =====" << endl;
    cout << "1. Input Array" << endl;
    cout << "2. Display Array" << endl;
    cout << "3. Compute Sum (Recursive)" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number.\n";
        goto menu;
    }

    switch (choice) {
    case 1:
        cout << "Enter the size of the array: ";
        cin >> size;

        if (cin.fail() || size <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid size.\n";
            goto menu;
        }

        obj.setSize(size);
        obj.inputElements();
        goto menu;

    case 2:
        cout << "Array elements: ";
        obj.displayElements();
        goto menu;

    case 3: {
        int sum = obj.computeSum();
        cout << "Sum of array elements: " << sum << endl;
        goto menu;
    }

    case 4:
        cout << "Exiting program. Thank you!" << endl;
        break;

    default:
        cout << "Invalid choice. Try again.\n";
        goto menu;
    }

    return 0;
}
