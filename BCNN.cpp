#include <iostream>
using namespace std;
int UCLN(int a, int b){
    while(a!=0){
        int tmp=a;
        a=b%a;
        b=tmp;
    }
    return b;
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