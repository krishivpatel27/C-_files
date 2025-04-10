#include <iostream>
using namespace std;

class Celsius;
class Fahrenheit {
    float fahren;
public:
    void InsertData() {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> fahren;
    }

    void DisplayData() {
        cout << "Temperature in Fahrenheit: " << fahren << endl;
    }

    float getdata() {
        return fahren;
    }

    void operator=(Celsius &c);
};

class Celsius {
    float degree;
public:
    void InsertData() {
        cout << "Enter temperature in Celsius: ";
        cin >> degree;
    }

    void DisplayData() {
        cout << "Temperature in Celsius: " << degree << endl;
    }

    float getdata() {
        return degree;
    }

    void operator=(Fahrenheit &f) {
        degree = (f.getdata() - 32) * 5 / 9;
    }
};
void Fahrenheit::operator=(Celsius &c) {
    fahren = (c.getdata() * 9 / 5) + 32;
}

int main() {
    Fahrenheit F;
    Celsius C;
    int ch;

    while (true) {
        cout << "\nEnter 1 to convert from Celsius to Fahrenheit"
             << "\nEnter 2 to convert from Fahrenheit to Celsius"
             << "\nEnter 3 to Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                C.InsertData();
                F = C;
                F.DisplayData();
                break;
            case 2:
                F.InsertData();
                C = F;
                C.DisplayData();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Enter a valid choice.\n";
        }
    }

    return 0;
}
