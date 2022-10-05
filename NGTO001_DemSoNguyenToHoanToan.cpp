#include <bits/stdc++.h>
using namespace std;
int test, n;
bool IsPrime(int n){
    if(n<2) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=3; i<=sqrt(n); i+=2){
        if(n%i==0) return false;
    }
    return true;
}
bool CheckHoanToan(int n){
    while(n!=0){
        int tmp=n%10;
        if(IsPrime(tmp)==false) return false;
        n/=10; 
    }
    return true;
}
int DemNGT(int n){
    int count=0;
    for(int i=0;i<=n;i++){
        if(IsPrime(i) && CheckHoanToan(i)) count++;
    }
    return count;
}
int main(){
    cin>>test;
    while(test--){
        cin>>n;
        cout<<DemNGT(n)<<endl;
    }
}