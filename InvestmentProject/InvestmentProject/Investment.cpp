#include "Investment.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor initializes all member variables to zero
Investment::Investment() : m_initialInvestment(0.0), m_monthlyDeposit(0.0),
m_annualInterest(0.0), m_numberOfYears(0) {}

// Setter methods store the input values in private member variables
void Investment::setInitialInvestment(double t_initialInvestment) {
    m_initialInvestment = t_initialInvestment;
}

void Investment::setMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

void Investment::setAnnualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest;
}

void Investment::setNumberOfYears(int t_numberOfYears) {
    m_numberOfYears = t_numberOfYears;
}

// Getter methods return the private member values
double Investment::getInitialInvestment() const {
    return m_initialInvestment;
}

double Investment::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double Investment::getAnnualInterest() const {
    return m_annualInterest;
}

int Investment::getNumberOfYears() const {
    return m_numberOfYears;
}

// Calculate and display results without monthly deposits
void Investment::calculateWithoutDeposits() const {
    double balance = m_initialInvestment;  // Starting balance
    double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;  // Convert to decimal and monthly

    // Display header with fixed width formatting
    cout << fixed << setprecision(2);
    cout << "Year | Year End Balance | Year End Earned Interest" << endl;
    cout << "-----------------------------------------------" << endl;

    // Loop through each year
    for (int year = 1; year <= m_numberOfYears; year++) {
        double yearlyInterest = 0.0;
        // Calculate monthly compound interest for 12 months
        for (int month = 1; month <= 12; month++) {
            double interest = balance * monthlyInterestRate;
            balance += interest;
            yearlyInterest += interest;
        }
        // Display results for the year
        cout << setw(4) << year << " | "
            << setw(16) << balance << " | "
            << setw(23) << yearlyInterest << endl;
    }
    cout << endl;  // Extra line for readability
}

// Calculate and display results with monthly deposits
void Investment::calculateWithDeposits() const {
    double balance = m_initialInvestment;  // Starting balance
    double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;  // Convert to decimal and monthly

    // Display header with fixed width formatting
    cout << fixed << setprecision(2);
    cout << "Year | Year End Balance | Year End Earned Interest" << endl;
    cout << "-----------------------------------------------" << endl;

    // Loop through each year
    for (int year = 1; year <= m_numberOfYears; year++) {
        double yearlyInterest = 0.0;
        // Calculate monthly compound interest with deposits for 12 months
        for (int month = 1; month <= 12; month++) {
            balance += m_monthlyDeposit;  // Add deposit first
            double interest = balance * monthlyInterestRate;
            balance += interest;
            yearlyInterest += interest;
        }
        // Display results for the year
        cout << setw(4) << year << " | "
            << setw(16) << balance << " | "
            << setw(23) << yearlyInterest << endl;
    }
    cout << endl;  // Extra line for readability
}