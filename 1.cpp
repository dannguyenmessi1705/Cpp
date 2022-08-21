#include <iostream>
using namespace std;
    int main(){
    int a, b;
    do{
    cin >> a >> b;
    }
    while (a<0 || b<0 || a>1000000 || b>1000000);
    cout << a%b;
}