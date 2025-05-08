#include <iostream>
#include <cmath>

#define MAX_CIRCLES 100

using namespace std;

class Shape {
protected:
    double radius;
public:
    Shape(double r = 0.0) : radius(r) {}
};

class Circle : public Shape {
private:
    double area;
public:
    Circle(double r = 0.0) : Shape(r), area(0.0) {}

    void calculateArea() {
        area = M_PI * radius * radius;
    }

    void displayArea() const {
        cout << "Area of Circle with radius " << radius << " is: " << area << endl;
    }

    void setRadius(double r) {
        radius = r;
    }
};

int main() {
    Circle circles[MAX_CIRCLES];
    int n = 0;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- Circle Area Menu ---\n";
        cout << "1. Enter number of circles and their radii\n";
        cout << "2. Calculate and display areas\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of circles (max " << MAX_CIRCLES << "): ";
                cin >> n;
                if (n < 1 || n > MAX_CIRCLES) {
                    cout << "Invalid number of circles.\n";
                    n = 0;
                    break;
                }
                for (int i = 0; i < n; ++i) {
                    double r;
                    cout << "Enter radius for Circle " << (i + 1) << ": ";
                    cin >> r;
                    circles[i].setRadius(r);
                }
                break;

            case 2:
                if (n == 0) {
                    cout << "No circles defined yet. Please enter data first.\n";
                    break;
                }
                for (int i = 0; i < n; ++i) {
                    circles[i].calculateArea();
                    circles[i].displayArea();
                }
                break;

            case 3:
                running = false;
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

