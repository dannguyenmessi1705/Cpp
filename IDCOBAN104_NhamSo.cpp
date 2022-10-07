#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i=a;i<b;i++)
ll MAX(string a, string b){
    // Xet phan tu a, b de doi '3' thanh '5'
    F(i,0,a.length()){
        if(a[i]=='3') a[i]='5';
    }
    F(i,0,b.length()){
        if(b[i]=='3') b[i]='5';
    }
    // Ham chuyen string a, b sang dang so
    int x=0, y=0;
    F(i,0,a.length()){
        x = x * 10 + (a[i]-'0');
    }
    F(i,0,b.length()){
        y = y * 10 + (b[i]-'0');
    }
    return x+y;
}
ll MIN(string a, string b){
    // Xet phan tu a, b de doi '5' thanh '3'
    F(i,0,a.length()){
        if(a[i]=='5') a[i]='3';
    }
    F(i,0,b.length()){
        if(b[i]=='5') b[i]='3';
    }
    // Ham chuyen string a, b sang dang so
    int x=0 ,y=0;
    F(i,0,a.length()){
        x = x * 10 + (a[i]-'0');
    }
    F(i,0,b.length()){
        y = y * 10 + (b[i]-'0');
    }
    return x+y;
}
int main(){
    int test;
    cin>>test;
    cin.ignore();
    while(test--){
        string a,b;
        cin>>a>>b;
        cout<<MIN(a,b)<<" "<<MAX(a,b)<<endl;
    }
    return 0;
}