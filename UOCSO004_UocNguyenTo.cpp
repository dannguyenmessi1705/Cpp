#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
bool Check(lli n){
    lli kq=1, y=0;
    while(n%2==0){
        y++;
        n/=2;
    }
    if(y>1) return true;
    for(lli i=3;i<=sqrt(n);i+=2){
        y=0;
        while(n%i==0){
            y++;
            n/=i;
        }
        if(y>1) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        lli n;
        cin>>n;
        if(Check(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}