#include <iostream>
using namespace std;
int main(){
    int n;
    long long s=0;
    do
    cin>>n;
    while(n<2 || n>10000);
    for(int i=2;i<=n;i++){
        s+=i;
    }
    s+=2*n;
    cout<<s;
}