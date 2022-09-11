#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld Tu(int &n, ld x){
  ld tu = pow(x, n);
  return tu;
}
ld Mau(int &n){
  ld mau = 0;
  for(int i=n;i>0;i--){
    mau+=i;
  }
  return mau;
}
ld PS(int &n, ld x){
  return Tu(n, x)/Mau(n);
}
ld Tong(int n, ld x){
  int tmp=1;
  ld Sum=0;
  while(tmp<=n){
    Sum += PS(tmp,x);
    tmp++;
  }
  Sum = trunc(1000*Sum)/1000;
  return Sum;
}

int main(){
  int test, n;
  ld x;
  cin>>test;
  while(test--){
    cin>>n>>x;
    cout<<fixed<<setprecision(3)<<Tong(n,x)<<endl;

  }
}