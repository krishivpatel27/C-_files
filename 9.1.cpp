#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>

using namespace std;

class FinancialCalculator {
public:
    double calculateLoanToIncomeRatio(double loanAmount, double annualIncome) {
        if (annualIncome == 0) {
            throw runtime_error("Annual income cannot be zero for calculating the ratio.");
        }
        return loanAmount / annualIncome;
    }

    double getInput(const string& prompt) {
        double value;
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter a valid number.");
        }

        return value;
    }
};

int main() {
    FinancialCalculator calculator;
    double loanAmount, annualIncome;

    try {
        loanAmount = calculator.getInput("Enter the loan amount: ");
        annualIncome = calculator.getInput("Enter the annual income: ");

        double ratio = calculator.calculateLoanToIncomeRatio(loanAmount, annualIncome);

        cout << "The loan-to-income ratio is: " << ratio << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
