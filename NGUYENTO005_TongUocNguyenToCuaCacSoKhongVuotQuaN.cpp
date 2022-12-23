#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll test, n, check[1000005], c, snt[100005], uoc[1000005], m=5e5, ans[1000005];
int main() {
    check[1]=1;
    for(int i=2; i*i<=m; ++i){
        if(check[i]==0)
            for(int j=i*i; j<=m; j+=i) 
                check[j]=1;
    }
    for(int i=m; i>=2; --i) 
        if(check[i]==0) 
            snt[++c]=i;
    for(int i=1; i<=c; i++){
        int tmp=snt[i];
        while(tmp<=m){
            if(uoc[tmp]==0){
            uoc[tmp]=snt[i];
            }
        tmp+=snt[i];
        }
    }
    for(int i=1; i<=m; i++) 
        ans[i]=ans[i-1]+uoc[i];
    cin>>test;
    while(test--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
}