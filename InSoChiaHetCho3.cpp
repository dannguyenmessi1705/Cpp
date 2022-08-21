#include <iostream>
using namespace std;
int main(){
    int a, b;
    do{
    cin>>a>>b;
    }
    while(a>b);
    int i=b-1, k=0;
    for(;i>a;i--){
        if(i%3==0){ 
            k=1;
            cout<<i<<" ";
        }
    }
    if(k==0) cout<<"NOT FOUND";
}