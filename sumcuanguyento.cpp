#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int *n){
    if(*n<2) return false;
    for(int i=2;i<=sqrt(*n);i++){
        if(*n%i==0) return false;
    } 
    return true;
}
int factorSum(int n)
{
    int tmp=n;
    int sum=0;
    for(int i=2;i<=tmp;i++){
        if(tmp%i==0){
            tmp/=i;
            sum+=i;
            i--;
        }
    }
    if(isPrime(&sum)==true) return sum;
    else factorSum(sum);
}
int main(){
    int n;
    cin>>n;
    cout<<factorSum(n);
    
}