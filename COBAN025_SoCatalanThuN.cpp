#include <iostream>
using namespace std;
typedef unsigned long long ll;
int test, n;
ll c[32];
void CatThuN(void){
    c[0] = 1;
    c[1] = 1;
    for(int i=2; i<=31; i++){
        for(int j=0; j<i; j++){
            c[i] += c[j] * c[i-j-1]; // VD, i=4 => C4 = C0xC3 + C1xC2 + C2xC1 + C3xC0;
        }
    }
}
int main(){
    cin>>test;
    CatThuN();
    while(test--){
        cin>>n;
        cout<<c[n]<<endl;
    }
}