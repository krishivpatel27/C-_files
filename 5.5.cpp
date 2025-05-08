#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return M_PI * radius * radius;
    }
};

class ShapeManager {
private:
    Shape* shapes[10];
    int currentSize;

public:
    ShapeManager() : currentSize(0) {}

    void addShape(Shape* shape) {
        if (currentSize < 10) {
            shapes[currentSize++] = shape;
        } else {
            cout << "Shape collection is full!" << endl;
        }
    }

    void displayAreas() const {
        for (int i = 0; i < currentSize; ++i) {
            cout << "Area of shape " << (i + 1) << ": " << shapes[i]->Area() << endl;
        }
    }

    ~ShapeManager() {
        for (int i = 0; i < currentSize; ++i) {
            delete shapes[i];
        }
    }
};

int main() {
    ShapeManager manager;
    int choice;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add a Rectangle\n";
        cout << "2. Add a Circle\n";
        cout << "3. Display Areas of All Shapes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        double length, width, radius;
        switch (choice) {
            case 1:
                cout << "Enter length of rectangle: ";
                cin >> length;
                cout << "Enter width of rectangle: ";
                cin >> width;
                manager.addShape(new Rectangle(length, width));
                cout << "Rectangle added successfully!" << endl;
                break;

            case 2:
                cout << "Enter radius of circle: ";
                cin >> radius;
                manager.addShape(new Circle(radius));
                cout << "Circle added successfully!" << endl;
                break;

            case 3:
                manager.displayAreas();
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
