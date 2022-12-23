#include <bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;
using namespace std;

ll t, n, k, x;
struct matrix{
  ll c[15][15];
};
matrix operator * (matrix a, matrix b){
    matrix res;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
        res.c[i][j] = 0;
        for (int k=0; k<n; k++)
            res.c[i][j] = (res.c[i][j]+a.c[i][k]*b.c[k][j])%MOD;
        }
    return res;
}

matrix tinh(matrix a, ll n){
    if (n==1) return a;
    if (n%2!=0) return tinh(a,n-1)*a;
    matrix tmp = tinh(a,n/2);
    return tmp*tmp;
}
int main(){
    cin >> t;
    while(t--){
      cin >> n >> k;
      matrix a;
      for(int i=0; i<=n-1; i++) 
        for(int j=0; j<=n-1; j++){
            cin >> x;
            a.c[i][j]=x;
      }
      a=tinh(a,k);
      for(int i=0; i<=n-1; i++){
        for(int j=0; j<=n-1; j++) 
            cout<<a.c[i][j]%MOD<<" "; 
        cout<<'\n';}
    }
}