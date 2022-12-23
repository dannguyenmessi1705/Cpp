#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
map<int,int>cnt;
int main(){
    ll test, n, fib[100005];
    fib[1]=1, fib[2]=1;
    cnt[1]=1;
    for(int i=3; i<=1005; ++i){
        fib[i]=fib[i-1]+fib[i-2];
        cnt[fib[i]]=1;
        if(fib[i]>1000000005) break;
    }
    cin>>test;
    while(test--){
        cin>>n;
        int x=n+1;
        while(cnt[x]==1) x++;
        cout<<x<<endl;
    }
}