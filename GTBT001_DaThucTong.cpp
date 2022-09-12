#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
float Tong(double x, int n){
    float result = 0; // KQ phải ra float bài mới đúng :))
    long double tu = 1;
    int mau = 0;
    for(int i=1;i<=n;i++){
        tu *= x;
        mau += i;
        result += tu/mau;
    }
    result = trunc(1000*result)/1000; // lấy 3 số dsau dấu phẩy mà không làm tròn
    return result;

}
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        long double x;
        cin>>n>>x;
        cout<<fixed<<setprecision(3)<<Tong(x,n)<<endl;
    }
}