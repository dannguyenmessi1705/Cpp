#include <iostream>
#include <math.h>
using namespace std;
int main(){
    long long a;
    long double s;
    cin>>a;
    s=sqrt(a);
    if(s==(int)s) cout<<"YES";
    else cout<<"NO";
}