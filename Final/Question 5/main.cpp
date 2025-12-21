#include <iostream>
#include "Employee.h"

using namespace std;

int main()
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
    
    cout << "[Extra Credit #2] Serializing Employee object" << endl;

    Mark.saveBin("emp.bin");

    Employee copy((char*)"Temp",(char*)"Temp",1.0f);
    copy.loadBin("emp.bin");

    cout << "[Extra Credit #2] Loaded Employee from binary file:" << endl;
    copy.toString();
    cout<<"[Extra Credit #5] Exception Handling]"<<endl;
    return 0;
}
