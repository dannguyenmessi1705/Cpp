#include <iostream>
#include <iomanip>
using namespace std;
float Div(float a, int b){
    return a/b;
}
int Sum(int a, int b){
    return a+b;
}
int Sub(int a, int b){
    return a-b;
}
int Mul(int a, int b){
    return a*b;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<Sum(a,b)<<"\n";
    cout<<Sub(a,b)<<"\n";
    cout<<Mul(a,b)<<"\n";
    if(b==0){
        cout<<"INF";
        return 0;
    }
    else cout<<fixed<<setprecision(2)<<Div(a,b);
}