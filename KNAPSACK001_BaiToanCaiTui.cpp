#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, w, a[30], c[30], dp[30][30005];
    cin >> t;
    while(t--){
        cin >> n >> w;
        for(int i=1; i<=n; i++) 
            cin >> a[i];
        for(int i=1; i<=n; i++) 
            cin >> c[i];
        for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(j>=a[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+c[i]);
            else dp[i][j]=dp[i-1][j];
        }
        }
        cout<<dp[n][w]<<endl;
    }
}