#include <iostream>
using namespace std;

// prototypes
int *getData(int &);               
int *sort(const int *,int);        
int *reverse(const int *,int);     
void prntDat(const int *,int);     

int main(){
    int n;
    int *arr = getData(n);       

    int *sorted = sort(arr,n);   // sort ascending
    int *rev = reverse(sorted,n);

    prntDat(sorted,n);           // print ascending
    cout << endl;
    prntDat(rev,n);              // print descending

   
    delete [] arr;
    delete [] sorted;
    delete [] rev;
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

int *sort(const int *a,int n){
    int *b = new int[n];
    for(int i=0;i<n;i++) b[i]=a[i];
   
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[j]<b[i]){
                int t=b[i];
                b[i]=b[j];
                b[j]=t;
            }
        }
    }
    return b;
}

int *reverse(const int *a,int n){
    int *b = new int[n];
    for(int i=0;i<n;i++){
        b[i]=a[n-1-i];
    }
    return b;
}

void prntDat(const int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i<n-1) cout<<" ";
    }
}
