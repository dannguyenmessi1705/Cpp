#include <bits/stdc++.h>
using namespace std;
typedef unsigned long int li;
li TongUoc(li n, li m){
    if(n==m) {
        return 0;
    } 
    li sum=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(m%i != 0)
                sum+=i;
            li tmp=n/i;
            // Dieu kien tranh cho so n/Uoc chinh bang Uoc
            // VD 9/3 = 3 thi bo qua
            // Neu 12/3 = 4 != 3, thi sum = 3+4
            if(tmp!=i && m%tmp!=0)
                sum+=tmp;
        }
    }
    return sum;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        li n, m;
        cin>>n>>m;
        cout<<TongUoc(n,m)<<endl;
    }
}