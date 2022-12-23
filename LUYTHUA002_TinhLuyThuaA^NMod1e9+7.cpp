#include <bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;
using namespace std;
ll tinh(ll a, ll n){
    if(n==0) return 1;
    if(n%2==0){
        ll tmp=tinh(a,n/2);
        return (tmp*tmp)%MOD;
    }
    else{
        ll tmp=tinh(a,n/2);
        return ((tmp*tmp)%MOD*a)%MOD;
    }
}
int main() {
    int t, a, n;
    cin >> t;
    while(t--){
        cin >> a >> n;
        cout<<tinh(a,n)<<'\n';
    }
}