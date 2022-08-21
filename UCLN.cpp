#include <iostream>
using namespace std;
int UCLN(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    while(a!=0){
        int tmp=a;
        a=b%a;
        b=tmp;
    }
    if(b<0) return b*(-1);
    else return b;
}
int main(){
    int a, b;
    cin>>a>>b;
    cout<<UCLN(a,b);
}