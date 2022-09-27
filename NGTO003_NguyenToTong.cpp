#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int li;
int IsPrime(li n){
    if(n<2) return 0;
    if(n==2 || n==3) return 1;
    if(n%2==0 || n&3==0) return 0;
    for(int i=3;i<=sqrt(n);i+=2){
        if(n%i==0) return 0;
    }
    return 1;
}
int Sum(li n){
    if(IsPrime(n)==1 && IsPrime(n-2)==1) return 1;
    else return 0;
}
li FindNum(li n){
    if(n<=2) return 2;
    int check = 0;
    while(check==0){
        n++;
        if(Sum(n)==1) check=1;
    }
    return n;
}
int main(){
    int test;
    li n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<FindNum(n)<<endl;
    }
}