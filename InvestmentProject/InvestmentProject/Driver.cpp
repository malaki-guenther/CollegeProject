#include "Investment.h"
#include <iostream>

using namespace std;

// Main function as driver
int main() {
    Investment investmentObj;  // Create Investment object
    double initialInvestment, monthlyDeposit, annualInterest;
    int numberOfYears;
    char continueChoice;

    do {
        // Display input screen and get user values
        cout << "Initial Investment Amount: ";
        cin >> initialInvestment;
        cout << "Monthly Deposit: ";
        cin >> monthlyDeposit;
        cout << "Annual Interest: ";
        cin >> annualInterest;
        cout << "Number of Years: ";
        cin >> numberOfYears;
        cout << "Press any key to continue..." << endl;
        cin.ignore();  // Clear buffer
        cin.get();     // Wait for key press

        // Store values in object
        investmentObj.setInitialInvestment(initialInvestment);
        investmentObj.setMonthlyDeposit(monthlyDeposit);
        investmentObj.setAnnualInterest(annualInterest);
        investmentObj.setNumberOfYears(numberOfYears);

        // Display reports
        cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        investmentObj.calculateWithoutDeposits();
        cout << "Balance and Interest With Additional Monthly Deposits\n";
        investmentObj.calculateWithDeposits();

        // Ask to continue
        cout << "Would you like to try different values? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;  // Successful program completion
}