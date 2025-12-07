/* 
 * File:   main.cpp
 * Author: Tyler Purba
 * Created on 10/24/25
 * Purpose:  Monthly budget comparison
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct MonthlyBudget {
    double housing;
    double utilities;
    double household;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double misc;
};

void getSpending(MonthlyBudget &spent);
void showReport(MonthlyBudget budget, MonthlyBudget spent);
void compare(string name, double budgetAmt, double spentAmt);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    MonthlyBudget budget = {500.00,150.00,65.00,50.00,250.00,30.00,100.00,150.00,75.00,50.00};
    MonthlyBudget spent;
    
    //Initialize Variables
    getSpending(spent);
    
    //Process or map Inputs to Outputs
    showReport(budget, spent);
    
    //Exit stage right!
    return 0;
}

void getSpending(MonthlyBudget &s) {
    cout << "Enter housing cost for the month:$" << endl;
    cin >> s.housing;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> s.utilities;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> s.household;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> s.transportation;
    cout << "Enter food cost for the month:$" << endl;
    cin >> s.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> s.medical;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> s.insurance;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> s.entertainment;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> s.clothing;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> s.misc;
}

void compare(string name, double b, double s) {
    if (s == b) cout << name << " Even" << endl;
    else if (s < b) cout << name << " Under" << endl;
    else cout << name << " Over" << endl;
}

void showReport(MonthlyBudget b, MonthlyBudget s) {
    cout << fixed << setprecision(2);
    
    double totalBudget = b.housing + b.utilities + b.household + b.transportation + b.food +
                         b.medical + b.insurance + b.entertainment + b.clothing + b.misc;
    double totalSpent = s.housing + s.utilities + s.household + s.transportation + s.food +
                        s.medical + s.insurance + s.entertainment + s.clothing + s.misc;
    double diff = totalBudget - totalSpent;

    compare("Housing", b.housing, s.housing);
    compare("Utilities", b.utilities, s.utilities);
    compare("Household Expenses", b.household, s.household);
    compare("Transportation", b.transportation, s.transportation);
    compare("Food", b.food, s.food);
    compare("Medical", b.medical, s.medical);
    compare("Insurance", b.insurance, s.insurance);
    compare("Entertainment", b.entertainment, s.entertainment);
    compare("Clothing", b.clothing, s.clothing);
    compare("Miscellaneous", b.misc, s.misc);

    if (diff > 0)
        cout << "You were $" << diff << " under budget";
    else if (diff < 0)
        cout << "You were $" << -diff << " over budget" ;
    else
        cout << "You met your budget exactly" ;
}
