#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, cs, a, m, key[100005], mx, t, gt, ans, test[100005];
ll tinh(ll x){
    ll ans=1;
    while(x) ans*=(x%10), x/=10;
    return ans;
}
int main() {
    for(int i=1; i<=1e3; i++){
        if(tinh(i)>mx) mx=tinh(i), gt=i;
        key[i]=gt;
    }
    cin>>t;
    while(t--){
        cin>>n;
        if(n<1000){
            cout<<tinh(key[n])<<endl;
            continue;
            }
        m=n, cs=0, ans=1;
        while(m){
            cs++;
            m/=10;
        }
        a=n;
        for(int i=1; i<=cs-3; i++) 
            a/=10;
        m=a;
        for(int i=1; i<=cs-3; i++) 
            m=m*10+9;
        if(m==n) 
            m=key[a];
        else 
            m=key[a-1];
        for(int i=1; i<=cs-3; i++) 
            m=m*10+9;
        cout<<tinh(m)<<endl;
    }
return 0;
}