#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll Uoc(ll n){
    ll mu=2, luythua=0;
    // 6! = 6x5x4x3x2x1
    // 6/2^1 = 3 => 2^3 < 6!
    // 6/2^2 = 1 => (2^2)^1 < 6!
    // => 3+1 = 4
    // 6/2^3(8) = 0, khong con luy thua cua 2 => break 
    while(n/mu){
        luythua += n/mu;
        mu*=2;
    }
    return luythua;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        cout<<Uoc(n)<<endl;
    }
}