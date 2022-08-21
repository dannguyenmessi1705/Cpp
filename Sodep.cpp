#include <iostream>
#include <math.h>
using namespace std;
typedef long long ng;
int Sodep(ng n){
    ng s=1, tmp=n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            s+=i;
            s+=n/i;
        }
        if(s>tmp) return 0;
    }
    if(s==tmp) return 1;
    else return 0;

}
int main(){
    ng n;
    cin>>n;
    if(n<6){
        cout<<"NO";
        return 0;
    }
    if(Sodep(n)) cout<<"YES";
    else cout<<"NO";
}