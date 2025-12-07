#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


double readDouble(const string &prompt) {
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) {
            cin.clear();
            continue;
        }
        if (s.empty()) continue;
        try {
            size_t idx = 0;
            double x = stod(s, &idx);
            if (idx != s.size()) {
                cout << "Invalid number. Try again."<<endl;
                continue;
            }
            return x;
        } catch (...) {
            cout << "Invalid number. Try again."<<endl;
        }
    }
}

int readInt(const string &prompt) {
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) {
            cin.clear();
            continue;
        }
        try {
            size_t idx = 0;
            int v = stoi(s, &idx);
            if (idx != s.size()) { cout << "Invalid integer."<<endl; continue; }
            return v;
        } catch (...) { cout << "Invalid integer."<<endl; }
    }
}

//Amount to English

string oneToNineteen(int n) {
    static string w[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
                         "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
                         "Sixteen","Seventeen","Eighteen","Nineteen"};
    if (n>=0 && n<20) return w[n];
    return "";
}
string tensWord(int n) {
    static string w[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    if (n>=0 && n<10) return w[n];
    return "";
}

// handles 0..999
string threeDigitsToWords(int n) {
    string out;
    int hundreds = n / 100;
    int rem = n % 100;
    if (hundreds > 0) {
        out += oneToNineteen(hundreds) + " Hundred";
        if (rem > 0) out += " ";
    }
    if (rem >= 20) {
        out += tensWord(rem/10);
        if (rem % 10) out += "-" + oneToNineteen(rem%10);
    } else if (rem > 0) {
        out += oneToNineteen(rem);
    }
    if (out.empty()) out = "Zero";
    return out;
}

// handles large amounts!
string dollarsToWords(long long dollars) {
    if (dollars == 0) return "Zero Dollars";
    string out;
    const long long BILLION = 1000000000LL;
    const long long MILLION = 1000000LL;
    const long long THOUSAND = 1000LL;

    long long b = dollars / BILLION; dollars %= BILLION;
    long long m = dollars / MILLION; dollars %= MILLION;
    long long t = dollars / THOUSAND; dollars %= THOUSAND;
    long long r = dollars;

    if (b) { out += threeDigitsToWords((int)b) + " Billion"; }
    if (m) { if (!out.empty()) out += " "; out += threeDigitsToWords((int)m) + " Million"; }
    if (t) { if (!out.empty()) out += " "; out += threeDigitsToWords((int)t) + " Thousand"; }
    if (r) { if (!out.empty()) out += " "; out += threeDigitsToWords((int)r); }

    if (out.empty()) out = "Zero";
    out += ( (b||m||t||r)==1 && (b+m+t+r)==1 && (b+m+t+r)<=1 ? " Dollar" : " Dollars"); 
    
    return out;
}


string dollarsToWordsFixed(long long dollars) {
    if (dollars == 0) return "Zero Dollars";
    string base = dollarsToWords(dollars);
  
    if (dollars == 1) return "One Dollar";
    return base;
}

string amountToEnglish(double amount) {
    // convert to cents with rounding
    long long centsAll = (long long)(amount * 100.0 + (amount >= 0 ? 0.5 : -0.5));
    if (centsAll < 0) centsAll = -centsAll; 
    long long dollars = centsAll / 100;
    int cents = (int)(centsAll % 100);

    string s = dollarsToWordsFixed(dollars);
    // cents
    s += " and ";
    if (cents == 0) {
        s += "Zero Cents";
    } else if (cents == 1) {
        s += "One Cent";
    } else {
        
        s += threeDigitsToWords(cents) + " Cents";
    }
    return s;
}

//Payroll

double computeGross(double hours, double rate) {
    if (hours <= 0) return 0.0;
    double gross = 0.0;
    double h = hours;

    // first 40 @ 1x
    double h1 = h > 40 ? 40 : h;
    gross += h1 * rate;
    h -= h1;

    if (h > 0) {
        // next up to 10 (40-50) @ 2x
        double h2 = h > 10 ? 10 : h;
        gross += h2 * (2.0 * rate);
        h -= h2;
    }

    if (h > 0) {
        // remaining >50 @ 3x
        gross += h * (3.0 * rate);
    }

    return gross;
}

struct Employee {
    string name;
    double hours;
    double rate;
    double gross;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Midterm Q2: Payroll with Dynamic Array of Structures"<<endl;

    // Company header
    const string COMPANY = "TECH SOLUTIONS.";
    const string ADDRESS = "5885 Haven Ave, Rancho Cucamonga, CA 91737";

    int n = readInt("How many employees are you inputting? ");
    while (n <= 0) {
        cout << "Please enter a positive count."<<endl;
        n = readInt("How many employees are you inputting? ");
    }

    // dynamic array of structures
    Employee* emp = new Employee[n];

    cout << endl<<"Enter employee data (negative hours OR negative rate will stop the process):"<<endl;

    int used = 0;
    for (int i = 0; i < n; ++i) {
        cout << "Employee #" << (i+1) << ""<<endl;
        cout << "Name: ";
        getline(cin, emp[i].name);
        if (emp[i].name.empty()) { 
            getline(cin, emp[i].name);
        }

        emp[i].hours = readDouble("Hours worked: ");
        if (emp[i].hours < 0) {
            cout << "Negative hours entered. Stopping input."<<endl;
            break;
        }

        emp[i].rate = readDouble("Rate of pay: ");
        if (emp[i].rate < 0) {
            cout << "Negative rate entered. Stopping input."<<endl;
            break;
        }

        emp[i].gross = computeGross(emp[i].hours, emp[i].rate);
        used++;

        cout << ""<<endl;
    }

    // print paychecks
    cout << fixed << setprecision(2);
    for (int i = 0; i < used; ++i) {
        double amt = emp[i].gross;

       
        string words = amountToEnglish(amt);

      
        cout << "        " << COMPANY << ""<<endl;
        cout << "        " << ADDRESS << ""<<endl;
      
        cout << "Name:   " << emp[i].name << ""<<endl;
        cout << "Amount: $" << amt << ""<<endl;
      
        cout << "Amount (English):"<<endl << words << ""<<endl;
     
        cout << "Authorized Signature: ______________________"<<endl;
    
    }

    delete[] emp;
    return 0;
}
