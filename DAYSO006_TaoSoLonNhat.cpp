#include <bits/stdc++.h>
using namespace std;
int test, n, a[100005];
bool compare(int b, int c){
    stack<int>x,y;
    while(b!=0){ 
        x.push(b%10); 
        b/=10;
    }
    while(c!=0){ 
        y.push(c%10); 
        c/=10;
    }
    while(!x.empty() && !y.empty()){
        if(x.top()>y.top()) return 1;
        if(x.top()<y.top()) return 0;
        x.pop(); 
        y.pop();
    }
    if(!x.empty()) return 1;
    if(!y.empty()) return 0;
    return 1;
}

int main(){
    cin>>test;
    while(test--){
        cin>>n;
        for(int i=1; i<=n; i++) 
            cin>>a[i];
        sort(a+1,a+n+1,compare);
        for(int i=1; i<=n; i++) 
            cout<<a[i];
        cout<<'\n';
    }
}