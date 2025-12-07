/* 
 * File:   main.cpp
 * Author: Tyler Purba
 * Purpose: Midterm Menu (Problems 1–7)
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;


// ---- Prototypes ----
void menu();
void prblm1();  // Checking account
void prblm2();  // Payroll
void prblm3();  // Separate project notice
void prblm4();  // Encryption/Decryption
void prblm5();  // Data types
void prblm6();  // NASA float answers (prints)
void prblm7();  // Prime factorization


// pause between runs
void pauseRet(){
    cout << endl<<"Press ENTER to return to the menu...";
    cin.ignore(10000, '\n'); // consume leftover
    cin.get();
}

int main(int argc, char** argv) {
    char choice;
    do{
        menu();
        cin >> choice;
        

        switch(choice){
            case '1': prblm1(); break;
            case '2': prblm2(); break;
            case '3': prblm3(); break;
            case '4': prblm4(); break;
            case '5': prblm5(); break;
            case '6': prblm6(); break;
            case '7': prblm7(); break;
            case '0': cout<<"Exiting Menu"<<endl; break;
            default : cout<<"Invalid choice"<<endl;
        }
        if(choice!='0') pauseRet();
    }while(choice!='0');
    return 0;
}

// ---------------- Menu ----------------
void menu(){
    cout << "MIDTERM MENU"<<endl;
    cout << "1) Problem 1 - Checking Account"<<endl;
    cout << "2) Problem 2 - Payroll Gross Pay"<<endl;
    cout << "3) Problem 3 - Stats (not included)"<<endl;
    cout << "4) Problem 4 - Encrypt/Decrypt"<<endl;
    cout << "5) Problem 5 - Exploration of Data Types"<<endl;
    cout << "6) Problem 6 - NASA 4-byte Float Answers"<<endl;
    cout << "7) Problem 7 - Prime Factorization"<<endl;
    cout << "0) Quit"<<endl;
    cout << "Choice: ";
}

// ---------------- Problem 1 ----------------
struct Customer {
    string accountNumber;
    string name;
    string address;
    double beginBalance;
    double* checks;
    int numChecks;
    double* deposits;
    int numDeposits;
};

static bool isFiveDigit(const string& s) {
    if (s.size() != 5) return false;
    for (char c : s) if (!isdigit(static_cast<unsigned char>(c))) return false;
    return true;
}

// stricter: reject "1400a"
static double readMoney(const string& prompt, bool allowNegative = false) {
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) { cin.clear(); continue; }
        if (s.empty()) continue;
        try {
            size_t idx = 0;
            double x = stod(s, &idx);
            if (idx != s.size()) { cout << "Invalid number."<<endl; continue; }
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

void prblm1() {
    // if the menu did `cin >> choice`, a newline is still pending; clear it once
    if (cin.peek() == '\n') cin.get();

    Customer* c = new Customer();
    c->checks = nullptr;
    c->deposits = nullptr;
    c->numChecks = 0;
    c->numDeposits = 0;

    cout << "=== Checking Account Midterm Q1 ==="<<endl;

    // account number (exactly 5 digits)
    while (true) {
        cout << "Enter a 5-digit account number: ";
        string acc;
        getline(cin, acc);
        if (isFiveDigit(acc)) { c->accountNumber = acc; break; }
        cout << "Account number must be exactly 5 digits."<<endl;
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
        if (amt < 0) { cout << "Checks can't be negative (use -1 only to finish)."<<endl; continue; }
        checksVec.push_back(amt);
    }

    // deposits (enter amounts, -1 to stop)
    cout << endl<<"Enter deposits this month. Type -1 to stop."<<endl;
    vector<double> depsVec;
    while (true) {
        double amt = readMoney("Deposit amount (-1 to stop): ", /*allowNegative=*/true);
        if (amt == -1) break;
        if (amt < 0) { cout << "Deposits can't be negative (use -1 only to finish)."<<endl; continue; }
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

    cout << "Account Number: " << c->accountNumber << ""<<endl;
    cout << "Customer Name : " << c->name << ""<<endl;
    cout << "Address       : " << c->address << ""<<endl;
    cout << fixed << setprecision(2);
    cout << "Begin Balance : $" << c->beginBalance << ""<<endl;

    cout << endl<<"Checks Written (" << c->numChecks << "):"<<endl;
    if (c->numChecks == 0) cout << "  (none)"<<endl;
    for (int i = 0; i < c->numChecks; ++i)
        cout << "  Check #" << (i + 1) << ": $" << c->checks[i] << ""<<endl;
    cout << "Total Checks  : $" << totalChecks << ""<<endl;

    cout << endl<<"Deposits (" << c->numDeposits << "):"<<endl;
    if (c->numDeposits == 0) cout << "  (none)"<<endl;
    for (int i = 0; i < c->numDeposits; ++i)
        cout << "  Deposit #" << (i + 1) << ": $" << c->deposits[i] << ""<<endl;
    cout << "Total Deposits: $" << totalDeposits << ""<<endl;

    cout << endl<<"------------------------------"<<endl;
    cout << "New Balance   : $" << newBal << ""<<endl;
    if (overdrawn) {
        cout << "*** OVERDRAWN: $20 fee applied ***"<<endl;
        cout << "Final Balance : $" << finalBal << ""<<endl;
    } else {
        cout << "Final Balance : $" << finalBal << ""<<endl;
    }
    cout << "------------------------------"<<endl;

    delete[] c->checks;
    delete[] c->deposits;
    delete c;
}

// ---------------- Problem 2 ----------------
double readDouble(const string &prompt) {
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) { cin.clear(); continue; }
        if (s.empty()) continue;
        try {
            size_t idx = 0;
            double x = stod(s, &idx);
            if (idx != s.size()) { cout << "Invalid number. Try again."<<endl; continue; }
            return x;
        } catch (...) { cout << "Invalid number. Try again."<<endl; }
    }
}

int readInt(const string &prompt) {
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) { cin.clear(); continue; }
        try {
            size_t idx = 0;
            int v = stoi(s, &idx);
            if (idx != s.size()) { cout << "Invalid integer."<<endl; continue; }
            return v;
        } catch (...) { cout << "Invalid integer."<<endl; }
    }
}

// --- Amount to English ---

string oneToNineteen(int n) {
    static string w[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
                       "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
                       "Sixteen","Seventeen","Eighteen","Nineteen"};
    if (n>=0 && n<20) return w[n];
    return "";
}
string tensWord(int n) {
    static string w[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    if (n>=0 && n<10) return w[n];
    return "";
}
string threeDigitsToWords(int n) {
    string out;
    int hundreds=n/100, rem=n%100;
    if (hundreds>0){ out+=oneToNineteen(hundreds)+" Hundred"; if(rem>0) out+=" "; }
    if (rem>=20){ out+=tensWord(rem/10); if(rem%10) out+="-"+oneToNineteen(rem%10); }
    else if (rem>0){ out+=oneToNineteen(rem); }
    if (out.empty()) out="Zero";
    return out;
}
string dollarsToWords(long long dollars) {
    if (dollars==0) return "Zero Dollars";
    string out;
    const long long B=1000000000LL,M=1000000LL,T=1000LL;
    long long b=dollars/B; dollars%=B;
    long long m=dollars/M; dollars%=M;
    long long t=dollars/T; dollars%=T;
    long long r=dollars;
    if(b){ out+=threeDigitsToWords((int)b)+" Billion"; }
    if(m){ if(!out.empty()) out+=' '; out+=threeDigitsToWords((int)m)+" Million"; }
    if(t){ if(!out.empty()) out+=' '; out+=threeDigitsToWords((int)t)+" Thousand"; }
    if(r){ if(!out.empty()) out+=' '; out+=threeDigitsToWords((int)r); }
    if(out.empty()) out="Zero";
    out += " Dollars";
    return out;
}
string dollarsToWordsFixed(long long dollars) {
    if (dollars==1) return "One Dollar";
    return dollarsToWords(dollars);
}
string amountToEnglish(double amount) {
    long long centsAll=(long long)(amount*100.0 + (amount>=0?0.5:-0.5));
    if (centsAll<0) centsAll=-centsAll;
    long long dollars=centsAll/100;
    int cents=(int)(centsAll%100);
    string s=dollarsToWordsFixed(dollars);
    s+=" and ";
    if (cents==0) s+="Zero Cents";
    else if (cents==1) s+="One Cent";
    else s+=threeDigitsToWords(cents)+" Cents";
    return s;
}

// --- Payroll core ---

double computeGross(double hours, double rate) {
    if (hours<=0) return 0.0;
    double gross=0.0, h=hours;
    double h1 = h>40 ? 40 : h; gross += h1*rate; h -= h1;
    if (h>0){ double h2 = h>10 ? 10 : h; gross += h2*(2.0*rate); h -= h2; }
    if (h>0){ gross += h*(3.0*rate); }
    return gross;
}

struct Employee {
    string name;
    double hours;
    double rate;
    double gross;
};

void prblm2() {
    // clear the leftover newline from menu's cin >> choice so our getline works
    if (cin.peek()=='\n') cin.get();

    cout << "Midterm Q2: Payroll with Dynamic Array of Structures"<<endl;

    // Company header
    const string COMPANY = "TECH SOLUTIONS.";
    const string ADDRESS = "5885 Haven Ave, Rancho Cucamonga, CA 91737";

    int n = readInt("How many employees are you inputting? ");
    while (n <= 0) {
        cout << "Please enter a positive count."<<endl;
        n = readInt("How many employees are you inputting? ");
    }

    Employee* emp = new Employee[n];

    cout << endl<<"Enter employee data (negative hours OR negative rate will stop the process):"<<endl;

    int used = 0;
    for (int i = 0; i < n; ++i) {
        cout << "Employee #" << (i+1) << ""<<endl;
        cout << "Name: ";
        getline(cin, emp[i].name);
        if (emp[i].name.empty()) getline(cin, emp[i].name);

        emp[i].hours = readDouble("Hours worked: ");
        if (emp[i].hours < 0) { cout << "Negative hours entered. Stopping input."<<endl; break; }

        emp[i].rate = readDouble("Rate of pay: ");
        if (emp[i].rate < 0) { cout << "Negative rate entered. Stopping input."<<endl; break; }

        emp[i].gross = computeGross(emp[i].hours, emp[i].rate);
        used++;
        cout << ""<<endl;
    }

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
}

// ---------------- Problem 3 ----------------
void prblm3(){
    cout << endl<<"[Problem 3: Stats]"<<endl;
    cout << "Problem 3 is included as a separate project."<<endl;
}

// ---------------- Problem 4: Encrypt/Decrypt (same problem) ----------------
static void doEncrypt() {
    int num;
    cout << "Enter a 4-digit number using digits 0-7 only: ";
    cin >> num;

    if (num < 0 || num > 7777) {
        cout << "Invalid input: only digits 0-7 allowed."<<endl;
        return;
    }

    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    if (d1 > 7 || d2 > 7 || d3 > 7 || d4 > 7) {
        cout << "Invalid input: digits must be between 0-7 only."<<endl;
        return;
    }

    d1 = (d1 + 3) % 8;
    d2 = (d2 + 3) % 8;
    d3 = (d3 + 3) % 8;
    d4 = (d4 + 3) % 8;

    int t = d1; d1 = d3; d3 = t;
    t = d2; d2 = d4; d4 = t;

    int encrypted = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
    cout << "Encrypted number: " << encrypted << ""<<endl;
}

static void doDecrypt() {
    int num;
    cout << "Enter the 4-digit encrypted number (digits 0-7 only): ";
    cin >> num;

    if (num < 0 || num > 7777) {
        cout << "Invalid input: only digits 0-7 allowed."<<endl;
        return;
    }

    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    if (d1 > 7 || d2 > 7 || d3 > 7 || d4 > 7) {
        cout << "Invalid input: digits must be between 0-7 only."<<endl;
        return;
    }

    int t = d1; d1 = d3; d3 = t;
    t = d2; d2 = d4; d4 = t;

    d1 = (d1 + 8 - 3) % 8;
    d2 = (d2 + 8 - 3) % 8;
    d3 = (d3 + 8 - 3) % 8;
    d4 = (d4 + 8 - 3) % 8;

    int decrypted = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
    cout << "Decrypted number: " << decrypted << ""<<endl;
}

void prblm4() {
    cout << endl<<"[Problem 4: Encryption / Decryption]"<<endl;
    cout << "(E) Encrypt  /  (D) Decrypt  /  (X) Exit"<<endl;
    cout << "Choice: ";
    char c; 
    cin >> c;

    if (c=='E' || c=='e') {
        doEncrypt();
    } else if (c=='D' || c=='d') {
        doDecrypt();
    } else {
        cout << "Returning to menu."<<endl;
    }
}


// ---------------- Problem 5 ----------------
void prblm5(){
        cout << "Largest n such that n! fits in each type"<<endl;

    cout << "signed char: n = 5"<<endl;
    cout << "unsigned char: n = 5"<<endl;

    cout << "short: n = 7"<<endl;
    cout << "unsigned short: n = 8"<<endl;

    cout << "int: n = 12"<<endl;
    cout << "unsigned int: n = 12"<<endl;

    cout << "long: n = 12"<<endl;
    cout << "unsigned long: n = 12"<<endl;

    cout << "long long: n = 20"<<endl;
    cout << "unsigned long long: n = 20"<<endl;

    cout << "float: n = 34"<<endl;
    cout << "double: n = 170"<<endl;

    cout << "long double: n = 170 "<<endl;
 
}


// ---------------- Problem 6 ----------------
// Prints the fixed answers you derived by hand
void prblm6(){ // prints final results only
    cout << "Problem 6: NASA 4-byte float"<<endl;

    cout << "(a) Base conversions + float hex"<<endl;
    cout << "49.1875     -> bin 110001.0011,  oct 61.14, hex 0x31.3,  float 0x62600006"<<endl;
    cout << "3.07421875  -> bin 11.00010011,  oct 3.046, hex 0x3.13,  float 0x62600002"<<endl;
    cout << "0.2         -> bin 0.001100110011..., oct 0.1463..., hex 0x0.3333..., float 0x666666FE"<<endl<<endl;

    cout << "(b) Negatives (sign bit set)"<<endl;
    cout << "-49.1875    -> bin -110001.0011,  oct -61.14, hex -0x31.3,  float 0xE2600006"<<endl;
    cout << "-3.07421875 -> bin -11.00010011,  oct -3.046, hex -0x3.13,  float 0xE2600002"<<endl;
    cout << "-0.2        -> bin -0.001100110011..., oct -0.1463..., hex -0x0.3333..., float 0xE66666FE"<<endl<<endl;

    cout << "(c) Float hex -> decimal"<<endl;
    cout << "69999902 -> 3.3"<<endl;
    cout << "69999903 -> 6.6"<<endl;
    cout << "966667FF -> -.0875"<<endl;


}


// ----- Problem 7 helpers/structs -----

struct Prime{
    unsigned char power;       // power of prime
    unsigned short prime;      // prime value
};
struct Primes{
    unsigned short n;          // original number
    unsigned char nPrimes;     // count of distinct primes
    Prime *pStrAry;            // array of Prime
};

Primes *factor(int n);
void prtPrms(const Primes *p);
bool isPrime(int x);
int  power(int f, int &m);
int  nPrimes(int n);
void cleanUp(Primes *p);

// ---- impls ----
bool isPrime(int x){
    if(x<2) return false; if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}
int power(int f, int &m){
    int cnt=0; int t=m;
    while(t%f==0){ t/=f; cnt++; }
    m=t; 
    return cnt;
}
int nPrimes(int n){
    int m=n, c=0;
    if(m%2==0){ while(m%2==0) m/=2; c++; }
    for(int i=3;i*i<=m;i+=2){
        if(m%i==0){ while(m%i==0) m/=i; c++; }
    }
    if(m>1) c++;
    return c;
}
Primes *factor(int n){
    Primes *p = (Primes*)new Primes;
    p->n = (unsigned short)n;
    p->nPrimes = 0;
    p->pStrAry = 0;

    int cnt = nPrimes(n);
    p->nPrimes = (unsigned char)cnt;
    if(cnt==0) return p;

    p->pStrAry = new Prime[cnt];

    int m=n, idx=0;
    if(m%2==0){
        int pw = power(2,m);
        p->pStrAry[idx].prime = (unsigned short)2;
        p->pStrAry[idx].power = (unsigned char)pw;
        idx++;
    }
    for(int f=3; (long long)f*f<=m; f+=2){
        if(m%f==0){
            int pw = power(f,m);
            p->pStrAry[idx].prime = (unsigned short)f;
            p->pStrAry[idx].power = (unsigned char)pw;
            idx++;
        }
    }
    if(m>1){
        p->pStrAry[idx].prime = (unsigned short)m;
        p->pStrAry[idx].power = (unsigned char)1;
    }
    return p;
}

// Print
void prtPrms(const Primes *p){
    cout << p->n << " = ";
    if(p->nPrimes==0 || p->pStrAry==NULL){
        cout << "(no primes)"<<endl;
        return;
    }
    for(int i=0;i<p->nPrimes;i++){
        cout << p->pStrAry[i].prime << "^" << (int)p->pStrAry[i].power;
        if(i<p->nPrimes-1) cout << " ";
    }
    cout << ""<<endl;
}
void cleanUp(Primes *p){
    if(!p) return;
    if(p->pStrAry) delete [] p->pStrAry;
    delete p;
}

// ----- Problem 7 entrypoint for menu -----
void prblm7(){
    int val;
    cout << "[Problem 7: Prime Factorization]"<<endl;
    cout << "Enter an integer [2..65000]: ";
    if(!(cin>>val)){ cout<<"bad input"<<endl; cin.clear(); cin.ignore(10000,'\n'); return; }
    if(val<2 || val>65000){ cout<<"Invalid."<<endl; cin.ignore(10000,'\n'); return; }

    Primes* r = factor(val);
    prtPrms(r);
    cleanUp(r);
}

