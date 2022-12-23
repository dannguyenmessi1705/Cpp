#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num;
ll Find(ll n){
    ll ans = 0;
    while(n%2==0) ans = 2, n/=2;
    while(n%3==0) ans = 3, n/=3;
    for(int i = 5; i <= sqrt(n); i+=6){
        while(n%i == 0) ans = i, n/=i;
        while(n%(i+2) == 0) ans = i + 2, n=n/(i+2);
    }
    if(n > 4) ans = n;
    return ans;
}
int main () {
    int test;
    cin>>test;
    while(test--){
        cin>>num;
        cout<<Find(num)<<endl;
    }
}