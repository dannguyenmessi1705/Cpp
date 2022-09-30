#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
lli Tong(int L, int R){
    lli n=R-L+1;
    return n*(L+R)/2; // Su dung Cong Thuc tinh tong so hang tu i toi k
}
int main(){
    int test;
    cin>>test;
    while(test--){
        int L, R;
        cin>>L>>R;
        cout<<Tong(L, R)<<endl;
    }
}