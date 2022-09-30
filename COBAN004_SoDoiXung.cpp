#include <bits/stdc++.h>
using namespace std;
int Count(int k){
    int count=9; 
    int mu=(k-1)/2;
    return count*pow(10, mu);
}
int main(){
    int test;
    cin>>test;
    while(test--){
        int k;
        cin>>k;
        cout<<Count(k)<<endl;
    }
}