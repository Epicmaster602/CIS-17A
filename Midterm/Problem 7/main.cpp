#include <iostream>
using namespace std;

struct Prime{
    unsigned char power; // power of prime
    unsigned short prime;// prime value
};

struct Primes{
    unsigned short n;    // original number
    unsigned char nPrimes; // count of distinct primes
    Prime *pStrAry;      // array of Prime
};

// req fns
Primes *factor(int n);
void prtPrms(const Primes *p);


bool isPrime(int x);
int power(int f, int &m);
int nPrimes(int n);
void cleanUp(Primes *p);


int main(){
    int val;
    cout<<"Enter an integer [2..65000]: ";
    if(!(cin>>val)) { cout<<"bad input"<<endl; return 0; }
    if(val<2 || val>65000){ cout<<"Invalid."<<endl; return 0; }

   
    int tmp = val; val = tmp;

    Primes* r = factor(val); 
    prtPrms(r);
    cleanUp(r);
    return 0;
}


bool isPrime(int x){
    if(x<2) return false; if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}

int power(int f, int &m){
    int cnt=0;
   
    int t=m;
    while(t%f==0){ t/=f; cnt++; }
    m=t; 
    return cnt;
}

int nPrimes(int n){
   
    int m=n, c=0;
    if(m%2==0){
        while(m%2==0) m/=2;
        c++;
    }
    
    int i=3;
    while(i*i<=m){
        if(m%i==0){
            while(m%i==0) m/=i;
            c++;
        }
        i+=2;
    }
    if(m>1) c++;
    return c;
}


Primes *factor(int n){
    
    Primes *p = (Primes*) new Primes;
    p->n = (unsigned short) n;
    p->nPrimes = 0;
    p->pStrAry = 0; 

    int cnt = nPrimes(n);
    p->nPrimes = (unsigned char)cnt;

    if(cnt==0){ 
        return p;
    }

    // allocate array
    p->pStrAry = new Prime[cnt];

    int m=n, idx=0;

    // check 2 first
    if(m%2==0){
      
        int pw = power(2,m);
        p->pStrAry[idx].prime = (unsigned short)2;
        p->pStrAry[idx].power = (unsigned char)pw;
        idx = idx + 1;
    }

    
 
    for(int f=3; (long long)f*f<=m; f+=2){
        if(m%f==0){
            int pw = power(f,m);
            
            p->pStrAry[idx].prime = (unsigned short)f;
            p->pStrAry[idx].power = (unsigned char)pw;
            ++idx;
        }
    }

 
    if(m>1){
        p->pStrAry[idx].prime = (unsigned short)m;
        p->pStrAry[idx].power = (unsigned char)1;
        idx++;
    }

    
    return p;
}

void prtPrms(const Primes *p){
   
    cout<<p->n<<" = ";
    if(p->nPrimes==0 || p->pStrAry==NULL){
        cout<<"(no primes)"<<endl;
        return;
    }
    
    for(int i=0;i<p->nPrimes;i++){
        cout<<p->pStrAry[i].prime<<"^"<<(int)p->pStrAry[i].power;
        if(i<p->nPrimes-1) cout<<" ";
    }
    
}

void cleanUp(Primes *p){
    if(!p) return;
    // tiny “student” defensive check
    if(p->pStrAry) delete [] p->pStrAry;
    delete p;
}
