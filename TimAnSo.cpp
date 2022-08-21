#include <iostream>
using namespace std;
int main(){
    int n, x=1, sum=0;
    cin>>n;
    while(1){
        sum+=x;
        if(sum<=n) x++;
        else break;
    }
    cout<<x-1;
}