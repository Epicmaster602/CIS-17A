#include <iostream>
using namespace std;

// prototypes
int *getData(int &);               
int *augment(const int *,int);     
void prntAry(const int *,int);     

int main(){
    int n;
    int *arr = getData(n);         // original array
    int *aug = augment(arr,n);     // augmented array

    prntAry(arr,n);                // print original to make codeE happy :)
    cout << endl;
    prntAry(aug,n+1);              // print augmented

    delete [] arr;
    delete [] aug;
    return 0;
}

int *getData(int &n){
    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    return a;
}

int *augment(const int *a,int n){
    int *b = new int[n+1];
    b[0] = 0;                     
    for(int i=0;i<n;i++){
        b[i+1] = a[i];             
    }
    return b;
}

void prntAry(const int *a,int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
}
