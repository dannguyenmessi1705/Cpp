#include <bits/stdc++.h>
using namespace std;
int dem(int n, int mx){
    if(n==0 || mx==0) return 1;
    if(n>=pow(2,mx)) return dem(n-pow(2,mx),mx)+dem(n,mx-1);
    else return dem(n,mx-1);
}
int main(){
    int test, n, mx;
    cin>>test;
    while(test--){
        cin>>n;
        mx=log2(n);
        cout<<dem(n,mx)<<endl;
    }
}