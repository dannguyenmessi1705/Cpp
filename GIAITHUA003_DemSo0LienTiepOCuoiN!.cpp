#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n;
int Count(ll n){
    int cnt=0;
    while(n >= 5){
        n/=5;
        cnt++;
    }
    return cnt;
}
int main(){
    int t; cin >>t;
    while(t--){
        cin >>n;
        ll ans = 0;
        for(int i = 1; i <= Count(n); ++i){
            ans += n/(pow(5,i));
        }
        cout <<ans<<endl;
    }
}