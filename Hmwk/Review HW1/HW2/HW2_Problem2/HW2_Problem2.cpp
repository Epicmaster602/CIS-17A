#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
int  *getData(int &);         // read size n and n ints
void  prntDat(int *, int);    
float* median(int *, int);    // build float array [size, median, data...]
void  prntMed(float *);       


static void sortCopy(int *a, int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        if(m!=i){ int t=a[i]; a[i]=a[m]; a[m]=t; }
    }
}

int main(){
    int n=0;
    int *arr = getData(n);     
    prntDat(arr,n);          
    
    float *med = median(arr,n);// build median array
    prntMed(med);            

   
    delete [] arr;
    delete [] med;
    return 0;
}

int *getData(int &n){

    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++) cin >> a[i];
    return a;
}

void prntDat(int *a,int n){
 
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
    cout << "\n";
}

float *median(int *a,int n){
 
    int fsz = n + 2;
    float *out = new float[fsz];

    
    int *cpy = new int[n];
    for(int i=0;i<n;i++) cpy[i]=a[i];
    sortCopy(cpy,n);

    float med;
    if(n==0){
        med = 0.0f; 
    } else if(n%2){ // odd
        med = cpy[n/2];
    } else {        // even
        med = (cpy[n/2 - 1] + cpy[n/2]) / 2.0f;
    }

    // fill float arrsy
    out[0] = static_cast<float>(fsz); // size of this float array
    out[1] = med;                     // the median
    for(int i=0;i<n;i++) out[2+i] = static_cast<float>(a[i]);

    delete [] cpy;
    return out;
}

void prntMed(float *m){
    int fsz = static_cast<int>(m[0]);

    //print as int to make codeE happy :D
    cout << fsz;

    
    cout << fixed << setprecision(2);
    for(int i=1;i<fsz;i++){
        cout << " " << m[i];
    }
    // no endl here to make codeE happy :)
}


