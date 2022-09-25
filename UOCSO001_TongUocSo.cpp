#include <bits/stdc++.h>
using namespace std;
typedef unsigned long int li;
void TongUoc(int n){
    if(n==1) {
        cout<<"0"<<endl;
        return;
    } 
    li sum=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            sum+=i;
            int tmp=n/i;
            if(tmp!=i)
                sum+=tmp;
        }
    }
    cout<<sum<<endl;
    return;
}
int main(){
    int n, test;
    cin>>test;
    while(test--){
        cin>>n;
        TongUoc(n);
    }
}
