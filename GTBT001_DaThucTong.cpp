#include <bits/stdc++.h>
using namespace std;
float Tong(float x, int n){
    float result = 0; // KQ phải ra float bài mới đúng :))
    float tu = 1;
    int mau = 0;
    for(int i=1;i<=n;i++){
        tu *= x;
        mau += i;
        result += tu/mau;
    }
    return result;

}
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        float x;
        cin>>n>>x;
        cout<<fixed<<setprecision(3)<<Tong(x,n)<<endl;
    }
}