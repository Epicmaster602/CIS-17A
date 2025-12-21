#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
public:
    Employee(char[],char[],float);          // Constructor
    float CalculatePay(float,int);          // Procedure
    float getGrossPay(float,int);           // Procedure
    float getNetPay(float);                 // Procedure
    void toString();                        // Procedure
    void saveBin(const char *); // Extra Credit: 1!!
    void loadBin(const char *); // Extra Credit: 1!!

    int setHoursWorked(int);                // Procedure
    float setHourlyRate(float);             // Procedure

private:
    double Tax(float);                      // Utility Procedure
    char MyName[20];                        // Property
    char JobTitle[20];                      // Property
    float HourlyRate;                       // Property
    int HoursWorked;                        // Property
    float GrossPay;                         // Property
    float NetPay;                           // Property
};

#endif
