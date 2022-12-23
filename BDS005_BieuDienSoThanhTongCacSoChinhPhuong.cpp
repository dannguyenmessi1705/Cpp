#include <bits/stdc++.h>
using namespace std;
int dem(int n, int mx){
    if(n==0 || mx==1) return 1;
    if(n>=mx*mx) return dem(n-mx*mx,mx)+dem(n,mx-1);
    else return dem(n,mx-1);
}
int main(){
    int test, mx, n;
    cin>>test;
    while(test--){
        cin >> n;
        mx=sqrt(n);
        cout<<dem(n,mx)<<'\n';
    }
}