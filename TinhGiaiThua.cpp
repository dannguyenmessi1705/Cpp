#include <iostream>
using namespace std;
long long Giaithua(int n){
    if(n==0 || n==1) return 1;
    else return Giaithua(n-1)*n;
}
int main(){
    int n;
    do
    cin>>n;
    while(n>12);
    cout<<Giaithua(n);
}   