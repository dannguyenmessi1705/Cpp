#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long long int lli;
int Dem(lli N){
    int count=0;
    while(N>0){
        count++;
        N/=10;
    }
    return count;
}
int ArmStrong(lli N){
    lli tmp=N;
    int bac=Dem(N);
    lli sum=0;
    while(N>0){
        int n=N%10;
        sum+=pow(n,bac);
        N/=10;
    }
    if(sum==tmp) return 1;
    else return 0;
}
int main(){
    int test;
    cin>>test;
    while (test--){
        lli n;
        cin>>n;
        if(ArmStrong(n)==1) cout<<"1\n";
        else cout<<"0\n";

    }
    
}