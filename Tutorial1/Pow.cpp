#include <iostream>
#include <iomanip>
using namespace std;
double Pow(double x, int n){
    double kq = 1;
    for(int i=1;i<=n;i++){
        kq*=x;
    }
    return kq;
}
int main(){
    int n;
    double x;
    cin>>x>>n;
    if(Pow(x,n)==(int)Pow(x,n)) cout<<(int)Pow(x,n);
    else cout<<fixed<<setprecision(3)<<Pow(x,n);
}