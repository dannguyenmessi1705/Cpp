#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    ll n;
    int t;
    stack<ll>st;
    cin >> t;
    while(t--){
        cin >> n;
        if(n==0) {cout<<0<<'\n'; continue;}
        while(n!=0){
            ll x=n%16;
            st.push(x);
            n/=16;
        }
        while(!st.empty()){
            if(st.top()<10) cout<<st.top();
            else cout<<char(st.top()+'A'-10);
            st.pop();
        }
        cout<<endl;
    }
}