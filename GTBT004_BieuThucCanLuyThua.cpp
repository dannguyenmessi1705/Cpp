#include <bits/stdc++.h>
using namespace std;
float Mu(float x, int i){
    float gt=1;
    for(int k=1;k<=i;k++) gt*=x;
    return gt;
}
float Calculate(float x, int n){
    float kq=0;
    for(int i=1;i<=n;i++){
        kq = sqrt(Mu(x,i)+kq);
    }
    return kq;
}
int main(){
    int test;
    int n;
    float x;
    cin>>test;
    while(test--){
        cin>>n;
        cin>>x;
        cout<<fixed<<setprecision(3)<<Calculate(x,n)<<endl;
    }
}
