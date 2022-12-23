#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main() {
    ll test, n, f[100005];
    cin>>test;
    f[1]=1, f[2]=1;
    for(int i=3; i<=10005; ++i){
        f[i]=f[i-1]+f[i-2];
        if(f[i]>1000000005) break;
    }
    while(test--){
        cin>>n;
        ll ans=0;
        for(int i=1; i<=10005; ++i){
            if(f[i]>n) break;
            if(f[i]%2==0) ans+=f[i];
        }
        cout<<ans<<endl;
    }
}