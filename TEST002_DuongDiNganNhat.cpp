#include <bits/stdc++.h>
typedef long long ll;
#define fi first
#define se second
using namespace std;
ll t, m, n, dp[101][101], a[101][101], x, y;
int main() {
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i=1; i<=m; i++) 
            for(int j=1; j<=n; j++) 
                cin >> a[i][j];
        cin >> x >> y;
        for(int i=1; i<=n; i++) 
            dp[0][i]=INT_MAX, dp[m+1][i]=INT_MAX;
        for(int i=1; i<=m; i++) 
            if(i!=x) 
                a[i][y]=INT_MAX;
        for(int i=1; i<=m; i++) 
            dp[i][y]=a[i][y];
        for(int j=y+1; j<=n; j++){
            for(int i=1; i<=m; i++){
                dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i+1][j-1])+a[i][j];
            }
        }
        ll result=INT_MAX;
        for(int i=1; i<=m; i++) 
            result=min(result,dp[i][n]);
        cout<<result<<endl;
    }
    return 0;
}