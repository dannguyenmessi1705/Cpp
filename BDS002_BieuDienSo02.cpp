#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MOD=1e9+7;
ll solve(ll n, ll k){
	ll dp[k+1][n+1];
	for(int i=0; i<=n; i++) 
        dp[1][i] = 1;
    ll sum = 0;
    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            sum = 0;
            for(int x=0; x<=j; x++)
                sum += dp[i - 1][x];
            dp[i][j] = sum;
        }
    }
    return dp[k][n];
}
int main(){
    int test;
    cin>>test;
    while(test--){
        ll n, k;
        cin>>n>>k;
        cout<<solve(n, k)<<endl;
    }
}