#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "SavingsAccount.h"
#include "Employee.h"

using namespace std;

void prob1();
void prob2();
void prob3();
void prob4();
void prob5();

int main()
{
    srand((unsigned int)time(0));

    int opt;

    do
    {
        cout << "\nFINAL MENU\n";
        cout << "1) Problem 1 - Random Sequence\n";
        cout << "2) Problem 2 - Sorting\n";
        cout << "3) Problem 3 - Spreadsheet Stuff\n";
        cout << "4) Problem 4 - Savings Account\n";
        cout << "5) Problem 5 - Employee Class\n";
        cout << "0) Quit\n";
        cout << "Choice: ";
        cin >> opt;

        switch(opt)
        {
            case 1: prob1(); break;
            case 2: prob2(); break;
            case 3: prob3(); break;
            case 4: prob4(); break;
            case 5: prob5(); break;
            case 0: cout << "Bye\n"; break;
            default: cout << "Bad choice\n";
        }

    } while(opt != 0);

    return 0;
}

// ---------------- Problem 1 ----------------
void prob1()
{
    char n = 5;
    char rndseq[] = {19,34,57,79,126};
    int ntimes = 100000;

    Prob1Random a(n, rndseq);

    for(int i=1;i<=ntimes;i++)
        a.randFromSet();

    int *x = a.getFreq();
    char *y = a.getSet();

    for(int i=0;i<n;i++)
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;

    cout << "The total number of random numbers is " << a.getNumRand() << endl;
}

// ---------------- Problem 2 ----------------
void prob2()
{
    cout << "The start of Problem 2, the sorting problem" << endl;

    Prob2Sort<char> rc;
    bool ascending = true;

    ifstream infile;
    infile.open("Problem2.txt", ios::in);

    char *ch2 = new char[10*16];
    char *ch2p = ch2;

    // Read up to 160 chars to avoid overflow if file is weird
    int cnt = 0;
    char ch;

    while(infile.get(ch) && cnt < 160)
    {
        ch2p[cnt] = ch;
        cout << ch;
        cnt++;
    }

    infile.close();
    cout << endl;

    cout << "Sorting on which column" << endl;
    int column;
    cin >> column;

    char *zc = rc.sortArray(ch2p,10,16,column,ascending);

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
            cout << zc[i*16 + j];
    }

    delete [] zc;
    delete [] ch2;

    cout << endl;
}

// ---------------- Problem 3 ----------------
void prob3()
{
    cout << "Entering problem number 3" << endl;

    int rows = 5;
    int cols = 6;

    Prob3TableInherited<int> tab((char*)"Problem3.txt", rows, cols);

    const int *naugT = tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout << naugT[i*cols + j] << " ";
        cout << endl;
    }

    cout << endl;

    const int *augT = tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
            cout << augT[i*(cols+1) + j] << " ";
        cout << endl;
    }

    // Extra Credit #3
    cout << "\n[EXTRA CREDIT #3] Overloaded + used to add two tables" << endl;
    int *sum = tab + tab; // add table to itself (easy proof)

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout << sum[i*cols + j] << " ";
        cout << endl;
    }

    delete [] sum;
}

// ---------------- Problem 4 ----------------
void prob4()
{
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
        mine.Transaction((float)(rand()%500)*(rand()%3-1));

    mine.toString();

    cout << "Balance after 7 years given 10% interest = "
         << mine.Total((float)(0.10),7) << endl;

    cout << "Balance after 7 years given 10% interest = "
         << mine.TotalRecursive((float)(0.10),7)
         << " Recursive Calculation " << endl;
}

// ---------------- Problem 5 ----------------
void prob5()
{
    Employee Mark((char*)"Mark",(char*)"Boss",215.50f);
    Mark.setHoursWorked(-3);
    Mark.toString();

    Mark.CalculatePay(Mark.setHourlyRate(20.0f),Mark.setHoursWorked(25));
    Mark.toString();

    Mark.CalculatePay(Mark.setHourlyRate(40.0f),Mark.setHoursWorked(25));
    Mark.toString();

    Mark.CalculatePay(Mark.setHourlyRate(60.0f),Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary((char*)"Mary",(char*)"VP",50.0f);
    Mary.toString();

    Mary.CalculatePay(Mary.setHourlyRate(50.0f),Mary.setHoursWorked(40));
    Mary.toString();

    Mary.CalculatePay(Mary.setHourlyRate(50.0f),Mary.setHoursWorked(50));
    Mary.toString();

    Mary.CalculatePay(Mary.setHourlyRate(50.0f),Mary.setHoursWorked(60));
    Mary.toString();

    // Extra Credit #5 (banner; exceptions are in setters internally)
    cout << "\n[EXTRA CREDIT #5] Exception handling used in Employee setters" << endl;

    // Extra Credit #2 (binary serialize / prove)
    cout << "[EXTRA CREDIT #2] Saved Employee to emp.bin" << endl;
    Mary.saveBin("emp.bin");

    Employee copy((char*)"Temp",(char*)"Temp",1.0f);
    copy.loadBin("emp.bin");

    cout << "[EXTRA CREDIT #2] Loaded Employee from emp.bin:" << endl;
    copy.toString();
}
