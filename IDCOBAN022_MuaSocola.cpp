#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll test, x, y, m;
int main() {
  cin >> test;
  while(test--){
    cin >> x >> y >> m;
    ll ans=m/x;
    ll vo=ans;
    while(vo>=y){
      ll doi=vo/y;
      ans+=doi;
      vo-=doi*y;
      vo+=doi;
    }
    cout<<ans<<'\n';
  }
return 0;
}