#include <iostream>
using namespace std;
char Convert(char c){
    if(c>=65 && c<=90) return c+=32;
    else if(c>=97 && c<=122) return c-=32;
    else return 0;
}
int main(){
    char c;
    cin>>c;
    cout<<Convert(c);
}