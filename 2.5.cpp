#include<iostream>
#include <cmath>
using namespace std;

class LoanAccount {
    double loanId;
    char applicantName[20];
    float totalAmount;
    short int interest;
    short int loanPeriod;

public:
    void AddAccount() {
        cout << "Enter Loan ID: ";
        cin >> loanId;
        cin.ignore();

        cout << "Enter Applicant Name: ";
        cin.getline(applicantName, 20);

        cout << "Enter Total Loan Amount: ";
        cin >> totalAmount;

        cout << "Enter Annual Interest Rate (%): ";
        cin >> interest;

        cout << "Enter Loan Period (in months): ";
        cin >> loanPeriod;
    }

    void DisplayAccount() {
        cout << "Loan ID: " << loanId << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Total Loan Amount: " << totalAmount << endl;
        cout << "Annual Interest Rate: " << interest << "%" << endl;
        cout << "Loan Period: " << loanPeriod << " months" << endl;
        CalculateEMI();
    }

private:
    void CalculateEMI() {
        double R = (interest / 100.0) / 12;
        double T = loanPeriod;
        double emi = (totalAmount * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
        cout << "EMI Calculation Completed!" << endl;
        cout << "EMI: " << emi << endl;
    }
};

int main()
 {
    int choice,i=0;
    LoanAccount L[5];

    next:
        cout<<"Enter 1 to add data"<<endl<<"Enter 2 to display data"<<endl<<"enter 3 to exit"<<endl;
        cin>>choice;
    switch(choice)
    {
        case 1:
            L[i].AddAccount();
            i++;
            goto next;

        case 2:
            for(int j=0;j<i;j++)
            {
                L[j].DisplayAccount();
            }
            goto next;
        case 3:
            cout<<"exit"<<endl;
            break;

        default:
            cout<<"choose from the given choice"<<endl;
            goto next;
    }

    return 0;
}
