#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, y=1;
    cin>>a>>b;
    while(1){
        a*=3;
        b*=2;
        if(a>b) break;
        y++;
    }
    cout<<y;
}