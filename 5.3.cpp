#include <iostream>

using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

int main() {
    Point p1, p2, result;
    int x1, y1, x2, y2;
    int choice;

    cout << "Enter coordinates for first point:" << endl;
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter y1: ";
    cin >> y1;
    p1 = Point(x1, y1);

    cout << "Enter coordinates for second point:" << endl;
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter y2: ";
    cin >> y2;
    p2 = Point(x2, y2);

    cout << "\nFirst point: ";
    p1.display();
    cout << endl;

    cout << "Second point: ";
    p2.display();
    cout << endl;

    cout << "\nChoose an operation:\n";
    cout << "1. Add points\n";
    cout << "2. Negate first point\n";
    cout << "3. Check if points are equal\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            result = p1 + p2;
            cout << "Sum of points: ";
            result.display();
            cout << endl;
            break;
        case 2:
            result = -p1;
            cout << "Negation of first point: ";
            result.display();
            cout << endl;
            break;
        case 3:
            if (p1 == p2) {
                cout << "The points are equal." << endl;
            } else {
                cout << "The points are not equal." << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
