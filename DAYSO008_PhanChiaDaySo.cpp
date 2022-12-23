#include<bits/stdc++.h>
using namespace std;
map<int,int>dp;
long long sum,sum2,ans;
int main(){
    int test, n , a[100];
    cin>>test;
    while(test--){
        cin>>n;
        sum=0;
        ans=INT_MAX;
        for(int i=1; i<=n; ++i){
            cin>>a[i];
            sum+=a[i];
        }
        sum2 = sum/2;
        for(int i=1; i<=sum2; ++i)
            dp[i]=0;
        dp[0]=1;
        for(int i=1; i<=n; ++i){
            for(int j=sum2; j>=a[i]; --j){
                if(dp[j-a[i]]==1)
                    dp[j]=1;
            }
        }
        for(int i=0; i<=sum2; ++i){
            if(dp[i]==1)
                ans=min(ans,abs(sum-2*i));
        }
        cout<<ans<<endl;
    }
}