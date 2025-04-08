#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }

    double add(double a, int b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    int intResult = calc.add(5, 10);
    double doubleResult = calc.add(3.5, 4.5);
    double mixedResult1 = calc.add(7, 2.3);
    double mixedResult2 = calc.add(4.5, 3);

    cout << "Integer Addition Result: " << intResult << endl;
    cout << "Double Addition Result: " << doubleResult << endl;
    cout << "Mixed Addition Result (int + double): " << mixedResult1 << endl;
    cout << "Mixed Addition Result (double + int): " << mixedResult2 << endl;

    return 0;
}
