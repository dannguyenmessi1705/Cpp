#include <iostream>
#include <math.h>
using namespace std;
int a,b,n;
int KiemTra(int n){
    if(a<=b){
        long long int x,y;
        x=a*a;
        y=b*b;
        if((sqrt(x+y)==(int)sqrt(x+y)) && (sqrt(x+y)<n)) return 1;
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=0;i<=n;i++){
        a=i;
        for(int j=i;j<=n;j++){
            b=j;
            if(KiemTra(n)) cout<<"a = "<<a<<"\tb = "<<b<<"\tc = "<<sqrt(a*a + b*b)<<endl;
            }
        }
    }