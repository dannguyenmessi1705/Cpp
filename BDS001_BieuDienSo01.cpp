#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MOD=1e9+7;
ll a[1000005];
ll solve(ll n){
	memset(a, 0, sizeof(a));
    a[0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            a[j] = (a[j] + a[j - i]) % MOD;
    return  (a[n] % MOD) - 1;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}