/* 
 * File: main.cpp
 * Author: Tyler Purba
 * Date: September 15, 2025
 * Purpose: Input Output manipulator practice
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    double char1;
    float char2;
    float char3;
    float char4;
    //Initialize or input data here
    cin >>char1>>char2>>char3>>char4;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    
    cout<<"        "<<fixed<<setprecision(0)<<char1<<"       "<<setprecision(1)<<char1<<"      "<<setprecision(2)<<char1<<endl;
    cout<<"        "<<fixed<<setprecision(0)<<char2<<"       "<<setprecision(1)<<char2<<"      "<<setprecision(2)<<char2<<endl;
    cout<<"        "<<fixed<<setprecision(0)<<char3<<"       "<<setprecision(1)<<char3<<"      "<<setprecision(2)<<char3<<endl;
    cout<<"        "<<fixed<<setprecision(0)<<char4<<"       "<<setprecision(1)<<char4<<"      "<<setprecision(2)<<char4;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}