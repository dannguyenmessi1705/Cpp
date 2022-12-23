#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int Step(ll n){
    if(n<=1) return n;
    ll x=sqrt(n);
    ll a=n%2+Step(n/2), b=n%3+Step(n/3), c=n-x*x+Step(x);
    return 1+min(a,min(b,c));
}
int main(){
    int test;
    ll n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<Step(n)<<endl;
    }
}