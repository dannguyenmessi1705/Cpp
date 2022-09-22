#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef unsigned long long int lli;
typedef long double ld;
lli Giaithua(int n){
    if(n==0 || n==1) return 1;
    return n * Giaithua(n-1);
}
ld Calculate(int n){
    ld kq=0;
    for(int i=1;i<=n;i++){
        lli GT = Giaithua(i);
        ld can = 1.0/(i+1);
        kq = pow(kq + GT, can);
    }
    return kq;
}
int main(){
    int test;
    int n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<fixed<<setprecision(3)<<Calculate(n)<<endl;
    }
}