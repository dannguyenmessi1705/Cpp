#include <iostream>
using namespace std;
int P(int a, int b){
    return (a+b)*2;
}
int S(int a, int b){
    return a*b;
}
int main(){
    int a, b;
    cin>>a>>b;
    cout<<P(a,b)<<"\n"<<S(a,b);
}