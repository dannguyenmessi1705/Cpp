#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
long long Giaithua(int x){
    if(x==1 || x==0) return 1;
    return x*Giaithua(x-1);
}
int main(){
    short n;
    float x;
    long double s=0;
    cin>>x>>n;
    for(int i=1;i<=n;i++){
        s+=pow(x,i)/Giaithua(i);
    }
    cout<<fixed<<setprecision(2)<<s;
}