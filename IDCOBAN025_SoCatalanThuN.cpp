#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

ll a[32], n, t;
int main() {
  cin >> t;
    a[0]=1, a[1]=1;
    for(int i=1; i<=30; ++i){
      for(int j=0; j<=i; ++j){
        a[i+1]+=a[j]*a[i-j];
      }
    }
  while(t--){
    cin >> n;
    cout<<a[n]<<endl;
  }
}
