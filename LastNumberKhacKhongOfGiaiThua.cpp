#include<iostream>
using namespace std;
int lastDigitDiffZero(int n) {
    int gT = 1;
    for (int i = 2; i <= n; ++i) { // vòng lặp giai thừa
        gT *= i;
        while (!(gT % 10)) { // nếu số cuối == 0 thì /10 đến khi hết 0, vì 0 * n = 0 // giảm size
            gT /= 10;
        }
        gT %= 100; // lấy 2 số cuối // 1 % 100 = 1  // giảm size
    }    
    return gT % 10;
}
int main(){
    int n;
    cout<<"Nhap so n: ";
    cin>>n;
    cout<<"So chu so cuoi cung khac khong cua "<<n<<" sau khi gia thua la: "<<lastDigitDiffZero(n);
}