#include <iostream>
using namespace std;
int main(){
    int a, i, k;
    int j=1;
    cin >> a;
    for(i=1;i<=a;i++){
        if(i==a){
            for(int k=1;k<=a;k++) cout << "*";
        }
        if(i!=a){
            for(int k=1;k<=j;k++) cout << "*";
        }
        ++j;
        cout << "\n";
    }
}