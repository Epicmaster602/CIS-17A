/* 
 * File:   main.cpp
 * Author: Tyler Purba
 * Created on:
 * Purpose:  To tell the Truth
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void TruthRw(bool x, bool y);
//Program Execution Begins Here
void TruthRw (bool x, bool y){ //Rather then paste four times over, make it a function
    cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"  "
        <<(!x?'T':'F')<<"  "
        <<(!y?'T':'F')<<"   "
        <<(x&&y?'T':'F')<<"    "
        <<(x||y?'T':'F')<<"   "
        <<(x^y?'T':'F')<<"    "
        <<(x^y^x?'T':'F')<<"     "
        <<(x^y^y?'T':'F')<<"       "
        <<(!(x&&y)?'T':'F')<<"      "
        <<(!x||!y?'T':'F')<<"        "
        <<(!(x||y)?'T':'F')<<"      "
        <<(!x&&!y?'T':'F')
        <<endl;
}
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x, y;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "
          " !(X||Y) !X&&!Y"<<endl;
    
    // Keep looping until no more input
    while (cin >> x >> y) {
        TruthRw(x, y);
    }

    cout << endl;
    return 0;
}

