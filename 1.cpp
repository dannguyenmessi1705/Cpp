#include <bits/stdc++.h>
using namespace std;
int main(){
    string c = "Hello";
    string s(c.size(), 0);
    for(int i=0;i<s.size();i++){
        s[i]=65;
    }
    cout<<s;
}