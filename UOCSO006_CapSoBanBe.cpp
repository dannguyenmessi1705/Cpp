#include <bits/stdc++.h>
using namespace std;
typedef unsigned long int li;
li TongUoc(li n){
    if(n==1) {
        return 0;
    } 
    li sum=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            sum+=i;
            int tmp=n/i;
            // Dieu kien tranh cho so n/Uoc chinh bang Uoc
            // VD 9/3 = 3 thi bo qua
            // Neu 12/3 = 4 != 3, thi sum = 3+4
            if(tmp!=i)
                sum+=tmp;
        }
    }
    return sum;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        li a, b;
        cin>>a>>b;
        if(TongUoc(a) == b && TongUoc(b) == a) cout<<"YES\n";
        else cout<<"NO\n";
    }
}