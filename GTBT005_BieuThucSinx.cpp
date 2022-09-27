#include<bits/stdc++.h>
#define PI 3.14159265358979323846
#define epsilon 0.00001
using namespace std;
float SinX(float x){
    while(x > 2*PI)
        x-=2*PI;
    float mau = 1.0;
    float tu = x;
    float sinx = x;
    int dau = -1;
    for(int i=1;(tu/mau)>epsilon;i++){
        tu*=x*x;
        mau*=(2*i)*(2*i+1);
        sinx+=dau*(tu/mau);
        dau=-dau;
    }
    return sinx;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
    	float x;
        cin>>x;
        cout<<fixed<<setprecision(6)<<SinX(x)<<endl;
    }
}