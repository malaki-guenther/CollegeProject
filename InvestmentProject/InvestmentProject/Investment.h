#ifndef AIRGEAD_INVESTMENT_H_  // Define guard per standards
#define AIRGEAD_INVESTMENT_H_

class Investment {
private:
    double m_initialInvestment;  // Member data with m_ prefix
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

public:
    Investment();  // Default constructor
    // Setter methods with t_ prefix for parameters
    void setInitialInvestment(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setAnnualInterest(double t_annualInterest);
    void setNumberOfYears(int t_numberOfYears);
    // Getter methods
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getNumberOfYears() const;
    // Calculation methods
    void calculateWithoutDeposits() const;
    void calculateWithDeposits() const;
};

#endif // AIRGEAD_INVESTMENT_H_