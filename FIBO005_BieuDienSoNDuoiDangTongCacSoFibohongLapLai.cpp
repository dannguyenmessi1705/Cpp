#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a[30], s, dp[105][100005], ans[100005], t;    
    a[1]=1, a[2]=2;
    for(int i=3; i<=25; i++) 
        a[i]=a[i-1]+a[i-2];
    dp[1][a[1]]=1;
    for(int i=1; i<=25; i++) 
        dp[i][0]=1;
    for(int i=2; i<=25; i++){
        for(int j=1; j<=100000; j++){
        if(j>=a[i]) dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];
        else dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=1; i<=100000; i++) 
        ans[i]=dp[25][i];
    cin >> t;
    while(t--){
        cin >> n;
        cout<<ans[n]<<endl;
    }
}