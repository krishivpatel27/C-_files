#include <iostream>
#include <string>

#define MAX_CARS 100

using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(string ft = "") : fuelType(ft) {}
};

class Brand {
protected:
    string brandName;
public:
    Brand(string bn = "") : brandName(bn) {}
};

class Car : public Fuel, public Brand {
public:
    Car(string ft = "", string bn = "") : Fuel(ft), Brand(bn) {}

    void setDetails(string ft, string bn) {
        fuelType = ft;
        brandName = bn;
    }

    void display() const {
        cout << "Brand: " << brandName << ", Fuel Type: " << fuelType << endl;
    }
};

int main() {
    Car cars[MAX_CARS];
    int count = 0;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- Car Management Menu ---\n";
        cout << "1. Add Car to Queue\n";
        cout << "2. Display All Cars in Queue\n";
        cout << "3. Process Next Car (FIFO)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count >= MAX_CARS) {
                    cout << "Car queue is full.\n";
                    break;
                }
                {
                    string brand, fuel;
                    cin.ignore();  // Clear newline from previous input
                    cout << "Enter Brand Name: ";
                    getline(cin, brand);
                    cout << "Enter Fuel Type (Petrol/Diesel/Electric): ";
                    getline(cin, fuel);
                    cars[count].setDetails(fuel, brand);
                    count++;
                    cout << "Car added to queue.\n";
                }
                break;

            case 2:
                if (count == 0) {
                    cout << "No cars in the queue.\n";
                } else {
                    cout << "\n--- Cars in Queue ---\n";
                    for (int i = 0; i < count; ++i) {
                        cout << "Car " << (i + 1) << ": ";
                        cars[i].display();
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    cout << "No cars to process.\n";
                } else {
                    cout << "Processing car:\n";
                    cars[0].display();
                    for (int i = 1; i < count; ++i) {
                        cars[i - 1] = cars[i];
                    }
                    count--;
                    cout << "Car processed.\n";
                }
                break;

            case 4:
                running = false;
                cout << "Exiting system.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
