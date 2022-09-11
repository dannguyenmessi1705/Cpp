#include <iostream>
using namespace std;
typedef unsigned long long int lli;
lli TongSoLeTu1DenN(lli n){
    lli Pt = (n+1)/2;
    lli sum = Pt*Pt; 
    return sum;
}
lli TongSoLeTrongL_R(lli left, lli right){
    return TongSoLeTu1DenN(right) - TongSoLeTu1DenN(left-1);
}

int main(){
    int test;
    lli left, right;
    cin>>test;
    while(test--){
        cin>>left>>right;
        cout<<TongSoLeTrongL_R(left, right);
        cout<<endl;
    }
}