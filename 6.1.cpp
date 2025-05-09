#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newData=new int[newCapacity];
        for (int i=0; i < size; ++i) {
            newData[i]=data[i];
        }
        delete[] data;
        data=newData;
        capacity=newCapacity;
    }

public:
    DynamicArray() {
        capacity=2;
        size=0;
        data=new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++]=value;
    }

    void removeAt(int index) {
        if (index<0 || index>=size) {
            cout<<"Error: Invalid index.\n";
            return;
        }
        for (int i=index; i<size - 1; ++i) {
            data[i]=data[i + 1];
        }
        size--;
        if (size>0 && size<=capacity/4 && capacity>2)
            resize(capacity / 2);
        }
    }

    int get(int index) const {
        if (index<0 || index>=size) {
            cout<<"Error: Index out of bounds.\n";
            return -1;
        }
        return data[index];
    }

    void display() const {
        if (size == 0) {
            cout<<"Array is empty.\n";
            return;
        }
        cout<<"Array contents: ";
        for (int i=0; i<size;++i) {
            cout<<data[i]<<" ";
        }
        cout<<"\n";
    }

    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, index;
    do {
        cout<<"\n--- Dynamic Array Menu ---\n";
        cout<<"1. Insert Element\n";
        cout<<"2. Remove Element at Index\n";
        cout<<"3. Get Element at Index\n";
        cout<<"4. Display Array\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>value;
                arr.insert(value);
                break;
            case 2:
                cout<<"Enter index to remove: ";
                cin>>index;
                arr.removeAt(index);
                break;
            case 3:
                cout<<"Enter index to get element: ";
                cin>>index;
                value=arr.get(index);
                if (index >= 0 && index < arr.getSize())
                    cout<<"Element at index " << index << " is: " << value << "\n";
                break;
            case 4:
                arr.display();
                break;
            case 5:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}
