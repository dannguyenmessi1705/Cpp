#include <iostream>
using namespace std;
int main(){
    int a, b, i, j;
    cin >> a >> b;
    int l=b;
    for(i=1;i<=a;i++){
        if(i==1){
            for(j=1;j<=b;j++) cout << j;
            --l;
            cout << "\n";
        }
        if(i!=1 && i<b){
            cout << i;
            for(j=i-1;j>=1;j--) cout << j;
            for(j=2;j<=l;j++) cout << j;
            --l;
            cout << "\n"; 
        }
        if(i==b){
            for(j=b;j>=1;j--) cout << j;
            ++l;
            cout << "\n";
        }
        if(i>b){
            cout << i;
            for(j=i-1;j>=l;j--) cout << j;
            ++l;
            cout << "\n";
        }
    }
}