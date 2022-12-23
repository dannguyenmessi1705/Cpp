#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        ll ans=0, tmp=1;
        for(int i=s.length()-1; i>=0; --i){
        if(s[i]=='1'){
            ans+=tmp;
        }
        tmp=tmp<<1;
        }
        cout<<ans<<endl;
    }
}