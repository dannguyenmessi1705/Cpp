#include <iostream>
#include <iomanip>
#define Pi 3.14;
using namespace std;
int main(){
    float r, p, s;
    cin>>r;
    p=2*r*Pi;
    s=r*r*Pi;
    cout<<fixed<<setprecision(3)<<p<<" "<<fixed<<setprecision(3)<<s;
}