#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a; i<=b; ++i)
#define fn(i,a,b) for(int i=a; i>=b; --i)
using namespace std;

int t, n, k, a[200005], check[200005];
int main () {
  cin >> t;
  while(t--){
    cin >> n >> k;
    if(k==0){
        f(i,1,n) cout<<i<<" ";
        cout<<'\n';
        continue;
    }
    if(n%2!=0 || k>n/2){cout<<-1<<'\n'; continue;}
    f(i,1,n){
      if(i+k>n) break;
      if(check[i]==0) a[i]=i+k, a[i+k]=i, check[i+k]++, check[i]++;
    }
    int z=0;
    f(i,1,n) if(check[i]!=1){z=1; break;}
    if(z==0) f(i,1,n) cout<<a[i]<<" ";
    else cout<<-1;
    cout<<'\n';
    f(i,1,n) check[i]=0;
  }
}