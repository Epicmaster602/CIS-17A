#include <iostream>
#include <sstream>
using namespace std;

int strSize(const char* s){
 int i=0;
 while(s[i]!='\0')i++;
 return i;
}

void strCopy(char* d,const char* s){
 int i=0;
 while(s[i]!='\0'){
  d[i]=s[i];
  i++;
 }
 d[i]='\0';
}

void plusEqual(char* a,const char* b,int max=20){
 int i=strSize(a),j=0;
 while(b[j]!='\0'&&i<max-1){
  a[i++]=b[j++];
 }
 a[i]='\0';
}

float str2Flt(stringstream &ss,const char* s){
 ss.clear();
 ss.str(s);
 float n;
 ss>>n;
 return n;
}

int main(){
 int size=20;
 char* str1=new char[size];
 char* str2=new char[10];
 strCopy(str1,"1234");
 strCopy(str2,".567");
 stringstream ss;
 cout<<"Before: "<<str1<<endl;
 plusEqual(str1,str2,size);
 cout<<"After: "<<str1<<endl;
 float num=str2Flt(ss,str1);
 cout<<"Float: "<<num<<endl;
 delete[]str1;
 delete[]str2;
 return 0;
}
