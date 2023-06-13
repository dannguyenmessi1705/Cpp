#include <iostream>
using namespace std;
int UCLN(int a, int b){
    if (a==0) return b;
    if (b==0) return a;
    return UCLN(b%a, a);
}
int BCNN(int a, int b){
    return a*b/UCLN(a,b);
}
int main(){
    int a, b;
    do
    cin>>a>>b;
    while(a*b==0);
    if(a<0) a=a*(-1);
    if(b<0) b=b*(-1);
    cout<<BCNN(a,b);
}