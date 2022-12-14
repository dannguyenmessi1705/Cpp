#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll n){
    if(n == 0) return true;
    ll x = sqrt(n);
    if(x*x == n) return true;
    return false;
}
bool check1(ll n){
    while(n!=0){
        ll x = n%10;
        if(x!=0 && x != 1 && x!=4 && x!=9) return false;
        n/=10;
    }
    return true;
}

int main (){
    int t; cin >>t;
    while(t--){
        ll n;
        cin >>n;
        ll low = pow(10,n-1);
        ll high = pow(10,n)-1;
        for(ll i = low; i <= high; ++i){
            if(check(i) && check1(i)){
                cout <<i;
                break;
            }
        }
        cout <<'\n';
    }
    return 0;
}