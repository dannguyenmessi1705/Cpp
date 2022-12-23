#include <bits/stdc++.h>
#define ll unsigned long long
#define f(i,a,b) for(int i=a; i<=b; ++i)
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int n, l, a;
        ll sum=0;
        cin >>n >>l;
        f(i,1,n-1) cin >>a, sum += a;
        ll ans = l*n + pow(n,2)/2 - n/2;
        ans-=sum;
        cout <<ans<<'\n';
    }
    return 0;
}