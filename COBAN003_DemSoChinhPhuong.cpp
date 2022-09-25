#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
lli Count(lli L, lli R){
    lli left, right;
    lli count=0;
    if(sqrt(L)*1.0==(lli)sqrt(L)) left=(lli)sqrt(L);
    else left=(lli)sqrt(L)+1;
    for(lli i=left; i<=(lli)sqrt(R); i++) count++;
    return count; 
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