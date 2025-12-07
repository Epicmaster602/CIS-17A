#include <iostream>
using namespace std;

// prototypes
int *getData(int &);             
int *sumAry(const int *,int);    
void prntAry(const int *,int);   

int main(){
    int n;
    int *arr = getData(n);       // get input array
    int *sum = sumAry(arr,n);    
    prntAry(arr,n);              // print original
    cout << endl;
    prntAry(sum,n);              

    delete [] arr;
    delete [] sum;
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

int *sumAry(const int *a,int n){
    int *b = new int[n];
    int running=0;
    for(int i=0;i<n;i++){
        running += a[i];
        b[i] = running;
    }
    return b;
}

void prntAry(const int *a,int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
}
