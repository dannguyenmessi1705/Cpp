#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a, count=0;
    do
    cin>>a;
    while(a==0);
    if(a<0) a=a*(-1);
    for(int i=1;i<=sqrt(a);i++){
        if(a%i==0) count++;
        if(a%(a/i)==0) count++;
        if(i*i==a) count--;
    }
    cout<<count;
}