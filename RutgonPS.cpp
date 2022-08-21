#include <iostream>
using namespace std;
int UCLN(int a, int b){
    if(a==0) return b;
    while (a!=0){
        int tmp=a;
        a=b%a;
        b=tmp;
    }
    if(b>0) return b;
    else return b*(-1);
}
int main(){
    int a, b;
    cin>>a>>b;
    if(b==0){ 
        cout<<"INVALID";
        return 0;
    }
    if(b<0 && (a>0 || a<0)){
        a=a*(-1);
        b=b*(-1);
    }
    int p=UCLN(a,b);
    a/=p;
    b/=p;
    if(a%b==0) cout<<a/b;
    else cout<<a<<" "<<b;
}