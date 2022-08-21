#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b,c,max,max1;
    cin>>a>>b>>c;
    max1=fmax(a,b);
    max=fmax(max1,c);
    cout<<max;
}