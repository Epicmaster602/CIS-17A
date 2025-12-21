#include "Employee.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

Employee::Employee(char name[], char job[], float rate)
{
    // copy name/job (safe copy)
    strncpy(MyName, name, 19);
    MyName[19] = '\0';

    strncpy(JobTitle, job, 19);
    JobTitle[19] = '\0';

    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;

    // validate hourly rate
    if(rate > 0 && rate < 200)
        HourlyRate = rate;
    else
    {
        cout << "Unacceptable Hourly Rate" << endl;
        HourlyRate = 0;
    }
}

int Employee::setHoursWorked(int hrs) //Extra Credit #5!!!
{
    try
    {
        if(!(hrs > 0 && hrs < 84))
            throw "Unacceptable Hours Worked";
        HoursWorked = hrs;
    }
    catch(const char *msg)
    {
        cout << msg << endl;
        HoursWorked = 0;
    }
    return HoursWorked;
}


float Employee::setHourlyRate(float rate)
{
    try
    {
        if(!(rate > 0 && rate < 200))
            throw "Unacceptable Hourly Rate";
        HourlyRate = rate;
    }
    catch(const char *msg)
    {
        cout << msg << endl;
        HourlyRate = 0;
    }
    return HourlyRate;
}


float Employee::getGrossPay(float rate, int hrs)
{
    float pay = 0;

    if(hrs <= 40)
        pay = hrs * rate;
    else if(hrs <= 50)
        pay = 40 * rate + (hrs - 40) * rate * 1.5f;
    else
        pay = 40 * rate + 10 * rate * 1.5f + (hrs - 50) * rate * 2.0f;

    GrossPay = pay;
    return GrossPay;
}

double Employee::Tax(float gross)
{
    double tax = 0;

    if(gross <= 500)
    {
        tax = 0.10 * gross;
    }
    else if(gross <= 1000)
    {
        tax = 0.10 * 500 + 0.20 * (gross - 500);
    }
    else
    {
        tax = 0.10 * 500 + 0.20 * 500 + 0.30 * (gross - 1000);
    }

    return tax;
}

float Employee::getNetPay(float gross)
{
    double tax = Tax(gross);
    NetPay = gross - (float)tax;
    GrossPay = gross;
    return NetPay;
}

float Employee::CalculatePay(float rate, int hrs)
{
    return getNetPay(getGrossPay(setHourlyRate(rate), setHoursWorked(hrs)));
}

void Employee::toString()
{
    cout << "Name = " << MyName << " Job Title = " << JobTitle << endl;
    cout << "Hourly Rate = " << HourlyRate
         << " Hours Worked = " << HoursWorked
         << " Gross Pay = " << GrossPay
         << " Net Pay = " << NetPay << endl;
}

void Employee::saveBin(const char *fn)
{
    ofstream fout(fn, ios::binary);
    if(!fout) return;

    fout.write(MyName, 20);
    fout.write(JobTitle, 20);
    fout.write((char*)&HourlyRate, sizeof(HourlyRate));
    fout.write((char*)&HoursWorked, sizeof(HoursWorked));
    fout.write((char*)&GrossPay, sizeof(GrossPay));
    fout.write((char*)&NetPay, sizeof(NetPay));

    fout.close();
}

void Employee::loadBin(const char *fn)
{
    ifstream fin(fn, ios::binary);
    if(!fin) return;

    fin.read(MyName, 20);
    fin.read(JobTitle, 20);
    fin.read((char*)&HourlyRate, sizeof(HourlyRate));
    fin.read((char*)&HoursWorked, sizeof(HoursWorked));
    fin.read((char*)&GrossPay, sizeof(GrossPay));
    fin.read((char*)&NetPay, sizeof(NetPay));

    fin.close();
}
