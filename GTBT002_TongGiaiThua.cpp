#include <iostream>
#include <iomanip>
using namespace std;
typedef unsigned long long int lli;
lli Giaithua(int n){
    if (n==0 || n==1) return 1;
    return n * Giaithua(n-1);
}
float Tong(long double &x, int &n){
    float result = 0; // KQ phải ra float bài mới đúng :))
    long double tu = 1;
    lli mau;
    for(int i=1;i<=n;i++){
        tu *= x;
        mau = Giaithua(i);
        result += tu/mau;
    }
    // result = trunc(1000*result)/1000; // lấy 3 số sau dấu phẩy mà không làm tròn
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