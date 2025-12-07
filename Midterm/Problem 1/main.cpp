#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

struct Customer {
    string accountNumber;   // keep as string to enforce exactly 5 digits
    string name;
    string address;
    double beginBalance;

    double* checks;         // dynamic array
    int numChecks;

    double* deposits;       // dynamic array
    int numDeposits;
};

static bool isFiveDigit(const string& s) {
    if (s.size() != 5) return false;
    for (char c : s) if (!isdigit(static_cast<unsigned char>(c))) return false;
    return true;
}

static double readMoney(const string& prompt, bool allowNegative = false) {
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) { cin.clear(); continue; }
        if (s.empty()) continue;
        try {
            double x = stod(s);
            if (!allowNegative && x < 0) {
                cout << "Enter a non-negative amount."<<endl;
                continue;
            }
            return x;
        } catch (...) {
            cout << "Invalid number."<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Customer* c = new Customer(); // dynamically create the structure
    c->checks = nullptr;
    c->deposits = nullptr;
    c->numChecks = 0;
    c->numDeposits = 0;

   

    // account number (exactly 5 digits)
    while (true) {
        cout << "Enter a 5-digit account number: ";
        string acc;
        getline(cin, acc);
        if (isFiveDigit(acc)) {
            c->accountNumber = acc;
            break;
        } else {
            cout << "Account number must be exactly 5 digits."<<endl;
        }
    }

    // name
    cout << "Enter customer's full name: ";
    getline(cin, c->name);

    // address
    cout << "Enter customer's address: ";
    getline(cin, c->address);

    // beginning balance
    c->beginBalance = readMoney("Enter beginning balance: ");

    // checks (enter amounts, -1 to stop)
    cout << endl<<"Enter checks written this month. Type -1 to stop."<<endl;
    vector<double> checksVec;
    while (true) {
        double amt = readMoney("Check amount (-1 to stop): ", /*allowNegative=*/true);
        if (amt == -1) break;
        if (amt < 0) {
            cout << "Checks can't be negative (use -1 only to finish)."<<endl;
            continue;
        }
        checksVec.push_back(amt);
    }

    // deposits (enter amounts, -1 to stop)
    cout << endl<<"Enter deposits this month. Type -1 to stop."<<endl;
    vector<double> depsVec;
    while (true) {
        double amt = readMoney("Deposit amount (-1 to stop): ", /*allowNegative=*/true);
        if (amt == -1) break;
        if (amt < 0) {
            cout << "Deposits can't be negative (use -1 only to finish)."<<endl;
            continue;
        }
        depsVec.push_back(amt);
    }

    // copy vectors into dynamic arrays for the struct
    c->numChecks = static_cast<int>(checksVec.size());
    if (c->numChecks > 0) {
        c->checks = new double[c->numChecks];
        for (int i = 0; i < c->numChecks; ++i) c->checks[i] = checksVec[i];
    }

    c->numDeposits = static_cast<int>(depsVec.size());
    if (c->numDeposits > 0) {
        c->deposits = new double[c->numDeposits];
        for (int i = 0; i < c->numDeposits; ++i) c->deposits[i] = depsVec[i];
    }

    // totals and new balance
    double totalChecks = 0.0, totalDeposits = 0.0;
    for (int i = 0; i < c->numChecks; ++i) totalChecks += c->checks[i];
    for (int i = 0; i < c->numDeposits; ++i) totalDeposits += c->deposits[i];

    double newBal = c->beginBalance - totalChecks + totalDeposits;
    bool overdrawn = (newBal < 0.0);
    double fee = overdrawn ? 20.0 : 0.0;
    double finalBal = newBal - fee;

  
    cout << "Account Information"<<endl;
   
    cout << "Account Number: " << c->accountNumber << endl;
    cout << "Customer Name : " << c->name << endl;
    cout << "Address       : " << c->address << endl;
    cout << fixed << setprecision(2);
    cout << "Begin Balance : $" << c->beginBalance << endl;

    cout << endl<<"Checks Written (" << c->numChecks << "):"<<endl;
    if (c->numChecks == 0) cout << "  (none)"<<endl;
    for (int i = 0; i < c->numChecks; ++i) {
        cout << "  Check #" << (i + 1) << ": $" << c->checks[i] << endl;
    }
    cout << "Total Checks  : $" << totalChecks << endl;

    cout << endl<<"Deposits (" << c->numDeposits << "):"<<endl;
    if (c->numDeposits == 0) cout << "  (none)"<<endl;
    for (int i = 0; i < c->numDeposits; ++i) {
        cout << "  Deposit #" << (i + 1) << ": $" << c->deposits[i] << endl;
    }
    cout << "Total Deposits: $" << totalDeposits << endl;

 
    cout << "New Balance   : $" << newBal << endl;
    if (overdrawn) {
        cout << "*** OVERDRAWN: $20 fee applied ***"<<endl;
        cout << "Final Balance : $" << finalBal << endl;
    } else {
        cout << "Final Balance : $" << finalBal << endl;
    }
    

    // clean up
    delete[] c->checks;
    delete[] c->deposits;
    delete c;

    return 0;
}
