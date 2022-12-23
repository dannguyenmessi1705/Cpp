#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a; i<=b; ++i)
using namespace std;

int tc, m, n, a[1005][1005], dp[1005][1005];
int main(){
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        f(i,1,n) f(j,1,m) cin >> a[i][j];
        f(i,1,m) dp[1][i]=a[1][i];
        f(i,1,n) dp[i][0]=-1, dp[i][m+1]=-1;
        f(i,2,n) f(j,1,m) dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]))+a[i][j];
        int ans=0;
        f(i,1,m) ans=max(ans,dp[n][i]);
        cout<<ans<<'\n';
    }
}