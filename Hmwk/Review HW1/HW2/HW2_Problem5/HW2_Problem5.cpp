#include <iostream>
using namespace std;

// prototypes
int **getData(int &,int &);        
void prntDat(const int* const *,int,int);
void destroy(int **,int,int);       
int sum(const int * const *, int,int);    

int main(){
    int rows, cols;
    int **arr = getData(rows,cols); // get 2D data

    prntDat(arr,rows,cols);         // print 2D array
    cout << sum(arr,rows,cols);     // print grand sum

    destroy(arr,rows,cols);         
    return 0;
}

int **getData(int &rows,int &cols){
    cin >> rows >> cols;
    int **a = new int*[rows];
    for(int i=0;i<rows;i++){
        a[i] = new int[cols];
        for(int j=0;j<cols;j++){
            cin >> a[i][j];
        }
    }
    return a;
}

void prntDat(const int* const *a,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << a[i][j];
            if(j<cols-1) cout << " ";
        }
        cout << endl;
    }
}

int sum(const int * const *a,int rows,int cols){
    int total=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            total += a[i][j];
        }
    }
    return total;
}

void destroy(int **a,int rows,int cols){
    for(int i=0;i<rows;i++){
        delete [] a[i];
    }
    delete [] a;
}
