#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
    float a,b;
    char c;
    cin>>a>>c>>b;
    switch (c){
    case '+':
        cout<<fixed<<setprecision(2)<<a+b;
        break;
    case '-':
        cout<<fixed<<setprecision(2)<<a-b;
        break;
    case '*':
        cout<<fixed<<setprecision(2)<<a*b;
        break;
    case '/':
        if(b==0) cout<<"Math Error";
        else cout<<fixed<<setprecision(2)<<a/b;
        break;
    default: cout<<"Math Error";
        break;
    }
}