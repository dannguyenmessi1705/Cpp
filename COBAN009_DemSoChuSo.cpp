#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
int main(){
    int test;
    cin>>test;
    while(test--){
        cin.ignore();
        string n;
        cin>>n;
        if(n[0]=='-') cout<<n.size()-1<<endl;
        else cout<<n.size()<<endl;
    }
}
