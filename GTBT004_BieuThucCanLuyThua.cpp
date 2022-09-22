#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld Calculate(ld x, int n){
    ld kq=0;
    for(int i=1;i<=n;i++){
        ld GT = pow(x,i);
        ld can = 1.0/(i+1);
        kq = pow(kq + GT, can);
    }
    return kq;
}
int main(){
    int test;
    int n;
    ld x;
    cin>>test;
    while(test--){
        cin>>n;
        cin>>x;
        cout<<fixed<<setprecision(3)<<Calculate(x,n)<<endl;
    }
}