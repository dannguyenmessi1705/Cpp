#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a; i<=b; ++i)
#define fn(i,a,b) for(int i=a; i>=b; --i)
typedef long long ll;
const int MOD=1e9+7;
using namespace std;


map<ll,int>cnt;
int main(){
    ll t, n, a[100005], b[100005], c;
    cin >> t;
    while(t--){
        cin >> n;
        f(i,1,n) {cin >> a[i]; cnt[a[i]]=0;}
        sort(a+1,a+n+1);
        c=0;
        f(i,1,n){
        cnt[a[i]]++;
        if(cnt[a[i]]==1) b[++c]=a[i];
        }
        ll ans=1;
        f(i,1,c) ans=(ans*(cnt[b[i]]+1))%MOD;
        cout<<(ans-1+MOD)%MOD<<" ";
        c=0;
        f(i,1,n) if(a[i]>=0) b[++c]=a[i];
        if(c>1){
        cout<<"["<<b[1]<<", ";
        f(i,2,c-1) cout<<b[i]<<", ";
        cout<<b[c]<<"]";
        cout<<'\n';}
        else if(c==1){
        cout<<"["<<b[1]<<"]"<<'\n';
        }
        else{
        cout<<"["<<a[n]<<"]"<<'\n';
        }
    }
}