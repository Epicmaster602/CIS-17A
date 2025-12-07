/* 
 * File:   main.cpp
 * Author: Tyler Purba
 * Created on 10/23/25
 * Purpose:  Store and display sales data for 4 divisions
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Division {
    string name;
    double q1, q2, q3, q4;
    double total;
    double average;
};

void getSales(Division &d);
void calcSales(Division &d);
void showData(Division d);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Division north, west, east, south;
    
    //Initialize Variables
    east.name = "East";
    west.name = "West";
    north.name = "North";
    south.name = "South";
    
    //Process or map Inputs to Outputs
    getSales(north);
    calcSales(north);
    showData(north);
    cout<<endl;
    
    getSales(west);
    calcSales(west);
    showData(west);
    cout<<endl;
    
    getSales(east);
    calcSales(east);
    showData(east);
    cout<<endl;
    
    getSales(south);
    calcSales(south);
    showData(south);
    
    
    //Display Outputs
   
    

    //Exit stage right!
    return 0;
}

void getSales(Division &d) {
    cout << d.name << endl;
    cout << "Enter first-quarter sales:"<<endl;
    cin >> d.q1;
    cout << "Enter second-quarter sales:"<<endl;
    cin >> d.q2;
    cout << "Enter third-quarter sales:"<<endl;
    cin >> d.q3;
    cout << "Enter fourth-quarter sales:"<<endl;
    cin >> d.q4;
    
    
}

void calcSales(Division &d) {
    d.total = d.q1 + d.q2 + d.q3 + d.q4;
    d.average = d.total / 4;
}

void showData(Division d) {
    cout << fixed << setprecision(2);
    cout << "Total Annual sales:$"<< d.total << endl;
    cout << "Average Quarterly Sales:$" << d.average ;
}
