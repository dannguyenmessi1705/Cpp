#include <iostream>
using namespace std;
int main(){
    int a,b,abs;
    cin>>a>>b;
    abs=a-b;
    if(abs<0) abs*=-1;
    cout<<abs;
}