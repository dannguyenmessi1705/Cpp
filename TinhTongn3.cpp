#include <iostream>
using namespace std;
int main(){
    long long n;
    long long s=0;
    cin>>n;
    for(int i=1;i<=3*n+1;i++){
        if(i%2==0) s-=i;
        else s+=i;
    }
    cout<<s;
}