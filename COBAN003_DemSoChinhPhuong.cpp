#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
lli Count(lli L, lli R){
    lli left, right;
    if(sqrt(L)*1.0==(lli)sqrt(L)) left=(lli)sqrt(L);
    else left=(lli)sqrt(L)+1;
    right=(lli)sqrt(R);
    return right-left+1;
}
int main(){
    int test;
    lli L, R;
    cin>>test;
    while(test--){
        cin>>L>>R;
        cout<<Count(L, R)<<endl;
    }
}