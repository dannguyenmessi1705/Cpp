#include <iostream>
using namespace std;
int main(){
    char x,y;
    cin>>x>>y;
    for(int i=x;i<=y;i++){
        cout<<(char)(i-32)<<" ";
    }
}
