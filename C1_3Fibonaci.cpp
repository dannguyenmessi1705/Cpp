#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Nhap so tu nhien n = ";
    cin>>n;
    int f0=0, f1=1, fn=0;
    while(fn<n){
        cout<<fn<<" ";
        fn=f0+f1;
        f0=f1;
        f1=fn;
    }
    }