#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    long double s=0;
    do
    cin>>n;
    while(n<2 || n>10000);
    for(int i=2;i<=n;i++){
        s+=(long double)1/i;
    }
    cout<<fixed<<setprecision(4)<<s;
}