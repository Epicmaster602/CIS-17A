/* 
 * File:main.cpp
 * Author: Tyler Purba
 * Date: September 15, 2025
 * Purpose: Demonstrate C++ math operations
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
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
    int a;
    int b;
    int c;
    //3 integers a b c  
    /*
    a + b
    b + a - c
    (a+b)*c
    (a/b)*c
    (a*c)/b
    */

    //Initialize or input data here
    cin>>a;
    cin>>b;
    cin>>c;
    
    //Display initial conditions, headings here
   
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout <<"A + B is: "<< a+b<<endl;
    cout <<"B + A - C is: "<<b+a-c<<endl;
    cout <<"(A + B) * C is: "<<(a+b) *c<<endl;
    cout<<"(A / B) * C is: "<<(a/b) *c<<endl; 
    cout<<"(A * C) / B is: "<<(a*c) /b <<endl; 
    cout<< "A % B is: "<<a%b<<endl;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}