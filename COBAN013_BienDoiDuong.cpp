
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a; i<=b; ++i)
#define fn(i,a,b) for(int i=a; i>=b; --i)
using namespace std;
    int t, n, a[100005];
    int main() {
    cin >> t;
    while(t--){
        cin >> n;
        int s0=0, sa=0, sd=0;
        f(i,1,n) {
        cin >> a[i];
        if(a[i]==0) s0++;
        if(a[i]>0) sd++;
        if(a[i]<0) sa++;
        }
        if(s0!=0) {cout<<-1<<'\n'; continue;}
        cout<<min(sa,sd)<<'\n';
    }
}