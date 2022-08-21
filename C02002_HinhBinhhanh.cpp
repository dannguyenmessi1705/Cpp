#include <iostream>
using namespace std;
int main(){
    int n, k, i;
    cin >> n;
    int f=n+n-1;
    for (k=1;k<=n;k++){
        if(k==n){
        for(i=1;i<=n;i++){
        cout << "*";}}
        if(k!=n){
        for(i=1;i<=f-n;i++)
            cout << "~";
        for(i=f-n+1;i<=f;i++)
            cout << "*";
        cout << "\n";
        --f;
            } 
        }

    }