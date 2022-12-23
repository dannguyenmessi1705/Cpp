#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MOD=1e9+7;
ll tinh(int n){
    if(n==0) return 1;
    if(n%2) return (2*tinh(n-1))%MOD;
    ll tmp=tinh(n/2);
    return (tmp*tmp)%MOD;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;
        if(n%2) cout<<-1<<endl;
        else{
            if(n==2) cout<<1<<endl;
            else cout<<tinh((n-2)/2)<<endl;
        }
    }
}