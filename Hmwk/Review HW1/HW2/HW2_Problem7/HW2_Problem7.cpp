#include <iostream>
using namespace std;

// prototypes
int **getData(int &,int &);                          // Get the Matrix Data
void printDat(const int * const *,int,int);          // Print 
int **augment(const int * const *,int,int);          // Augment the og array
void destroy(int **,int);                            // Destroy

int main(){
    int r,c;
    int **a = getData(r,c);          // og
    printDat(a,r,c);                 // print 
    cout << "\n";                    // separator line

    int **b = augment(a,r,c);        // augmented (
    printDat(b,r+1,c+1);             // print augmented

    destroy(a,r);
    destroy(b,r+1);
    return 0;
}

int **getData(int &rows,int &cols){
    cin >> rows >> cols;
    int **m = new int*[rows];
    for(int i=0;i<rows;i++){
        m[i] = new int[cols];
        for(int j=0;j<cols;j++){
            cin >> m[i][j];
        }
    }
    return m;
}

void printDat(const int * const *m,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << m[i][j];
            if(j<cols-1) cout << " ";
        }
        if(i<rows-1) cout << "\n";  // no endl to make codeE happy :)
    }
}

int **augment(const int * const *m,int rows,int cols){
    int **x = new int*[rows+1];
    for(int i=0;i<rows+1;i++){
        x[i] = new int[cols+1];
    }

    // zero first row
    for(int j=0;j<cols+1;j++) x[0][j] = 0;
    // zero first col
    for(int i=0;i<rows+1;i++) x[i][0] = 0;

    // copy original shifted by +1 row and +1 col
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            x[i+1][j+1] = m[i][j];
        }
    }

    return x;
}

void destroy(int **m,int rows){
    for(int i=0;i<rows;i++){
        delete [] m[i];
    }
    delete [] m;
}
