#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void Tong(double x, int n){
    long double result = 0;
    long double tu = 1;
    int mau = 0;
    for(int i=1;i<=n;i++){
        tu*=x;
        mau+=i;
        result += tu/mau;
    }
    result = trunc(1000*result)/1000; // lấy 3 số dsau dấu phẩy mà không làm tròn
    cout<<setprecision(3)<<fixed<<result;

}
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        long double x;
        cin>>n>>x;
        Tong(x,n);
        cout<<endl;
    }
}