#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount
{
public:
    SavingsAccount(float);          // Constructor
    void Transaction(float);        // Procedure
    float Total(float=0,int=0);     // Savings Procedure (loop)
    float TotalRecursive(float=0,int=0);
    void toString();                // Output Properties

private:
    float Withdraw(float);          // Utility Procedure
    float Deposit(float);           // Utility Procedure
    float Balance;                  // Property
    int FreqWithDraw;               // Property
    int FreqDeposit;                // Property
};

#endif
