#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
typedef unsigned long long int lli;
typedef long double ld;
lli GT(int n){
    if(n==0 || n==1) return 1;
    return n * GT(n-1);
}
ld DegtoRad(ld x){
    x = x/PI*180;
    return x;
}
ld RadtoDeg(ld x){
    x = x * PI /180;
    return x;
}
ld Sin(ld x){
    ld kq=0.0;
    x = RadtoDeg(x);
    for(int i=0;i<=10;i++){
        kq += pow(-1, i) * pow(x, 2*i+1) / GT(2*i+1);
    }
    return kq;
}

int main(){
    int test;
    ld x;
    cin>>test;
    while (test--)
    {
        cin>>x;
        cout<<fixed<<setprecision(6)<<Sin(DegtoRad(x))<<endl;
    }
    
}