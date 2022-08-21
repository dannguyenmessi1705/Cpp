#include <iostream>
#include <string>
using namespace std;
int main(){
    string x;
    cin>>x;
    if(x[0]=='-') cout<<x.length()-1;
    else cout<<x.length();
}