/*
 * File:   main_vectors_student.cpp
 * Purpose: Compare 1 and 2 Dimensional Dynamic Arrays (utilize vectors)
 * Note: tried to keep it close to the original layout, just with vectors
 */

 //System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntAry(const vector<int> a, int perLine);      
void prntAry(vector<vector<int>> a);               

vector<int> fillAry(int n, int hr, int lr);          // 1D maker (was int* before)
vector<vector<int>> fillAry(int rows, int cols);     // 2D maker (was int** before)
void fillAry(vector<vector<int>> &a, vector<int> c, int rowSize, int wchCol); 

void swap(int &x,int &y);                            
void smlLst(vector<int> &a,int n,int pos);          
void mrkSort(vector<int> &a,int n);

//Program Execution Begins Here
int main(int argc, char** argv){
     //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    int rowsize = 4;
    int colsize = 3;

    // now vectors
    vector<int> array;
    vector<int> brray;
    vector<int> crray;
    vector<vector<int>> table;

    int lowRng=100, highRng=999;
    int perLine=4;

   //Fill each parallel array
    array = fillAry(rowsize,highRng,lowRng);
    brray = fillAry(rowsize,highRng/10,lowRng/10);
    crray = fillAry(rowsize,highRng/100,lowRng/100);

    //Sort the array the for all positions
    mrkSort(array,(int)array.size());
    mrkSort(brray,(int)brray.size());
    mrkSort(crray,(int)crray.size());

    //Fill the 2-D array
    table = fillAry(rowsize,colsize);
    fillAry(table,array,rowsize,0);
    fillAry(table,brray,rowsize,1);
    fillAry(table,crray,rowsize,2);

   //Print the values in the array
    prntAry(array,perLine);
    prntAry(brray,perLine);
    prntAry(crray,perLine);
    prntAry(table);

    // no deletes (vectors clean themselves)
    return 0;
}

// “destroy” not needed (vectors)


void fillAry(vector<vector<int>> &a, vector<int> c, int rowSize, int wchCol){
  
    for(int r=0; r<rowSize; r++){
        a[r][wchCol] = c[r];
    }
}


vector<int> fillAry(int n,int hr,int lr){
    if(n<2) n=2;
    vector<int> a(n);

    int span = hr - lr + 1;
    for(int i=0;i<n;i++){
        a[i] = rand()%span + lr;
    }
    return a; }


vector<vector<int>> fillAry(int rows,int cols){
    //Allocate Memory for 2-D Array
    if(rows<2) rows=2;
    if(cols<2) cols=2;
    vector<vector<int>> a;
    a.resize(rows);
    for(int r=0;r<rows;r++){
        a[r].resize(cols);
        for(int c=0;c<cols;c++){
            a[r][c]=0; 
        }
    }
    return a;
}


void prntAry(vector<vector<int>> a){
    cout << endl << "The Array Values" << endl;
    for(int r=0; r<(int)a.size(); r++){
        for(int c=0; c<(int)a[r].size(); c++){
            cout << setw(4) << a[r][c];
        }
        cout << endl;
    }
}


void prntAry(const vector<int> a,int perLine){
     //Print the values in the array
    cout << endl << "The Array Values" << endl;
    for(int i=0;i<(int)a.size();i++){
        cout << a[i] << " ";
        if(perLine>0 && i%perLine==(perLine-1)) cout << endl;
    }
    cout << endl;
}

// selection-sort, same as before, just vectors
void mrkSort(vector<int> &a,int n){
    for(int pos=0; pos<n-1; pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(vector<int> &a,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &x,int &y){
    int t=x; x=y; y=t;
}
