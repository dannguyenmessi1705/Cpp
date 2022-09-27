#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
lli Uoc(lli n){
    lli mu=2, luythua=0;
    while(n/mu){
        luythua+=n/mu;
        mu*=2;
    }
    return luythua;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        lli n;
        cin>>n;
        cout<<Uoc(n)<<endl;
    }  
}
