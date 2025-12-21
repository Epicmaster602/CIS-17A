#include "SavingsAccount.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount(float bal)
{
    if (bal > 0)
        Balance = bal;
    else
        Balance = 0;

    FreqWithDraw = 0;
    FreqDeposit = 0;
}

void SavingsAccount::Transaction(float amt)
{
    if (amt > 0)
    {
        Deposit(amt);
        FreqDeposit++;
    }
    else if (amt < 0)
    {
        float wamt = -amt;
        float res = Withdraw(wamt);
        if (res > 0)
            FreqWithDraw++;
    }
    // amt == 0: do nothing
}

float SavingsAccount::Deposit(float amt)
{
    Balance += amt;
    return Balance;
}

float SavingsAccount::Withdraw(float amt)
{
    if (amt > Balance)
    {
        cout << "WithDraw not Allowed" << endl;
        return 0;
    }

    Balance -= amt;
    return Balance;
}

void SavingsAccount::toString()
{
    cout << "Balance=" << Balance << endl;
    cout << "WithDraws=" << FreqWithDraw << endl;
    cout << "Deposit=" << FreqDeposit << endl;
}

float SavingsAccount::Total(float savint, int time)
{
    float tot = Balance;

    for (int i = 1; i <= time; i++)
    {
        tot = tot * (1 + savint);
    }

    return tot;
}

float SavingsAccount::TotalRecursive(float savint, int time)
{
    if (time <= 0)
        return Balance;

    return (1 + savint) * TotalRecursive(savint, time - 1);
}
