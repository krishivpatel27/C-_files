#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imaginary < 0)
            os << c.real << " - " << -c.imaginary << "i";
        else
            os << c.real << " + " << c.imaginary << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imaginary;
        return is;
    }
};

int main() {
    Complex c1, c2, result;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    result = c1 + c2;
    cout << "Sum: " << result << endl;

    result = c1 - c2;
    cout << "Difference: " << result << endl;

    return 0;
}
