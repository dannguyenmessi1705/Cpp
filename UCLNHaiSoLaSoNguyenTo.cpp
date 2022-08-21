#include <iostream>
#include <math.h>
using namespace std;
int isPrime(int n){
    if(n<=2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int UCLN(int a, int b){
    int tmp;
    while (a!=0){
        tmp=a;
        a=b%a;
        b=tmp;
    }
    return b;
}
int UCLNisPrime(int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0 && isPrime(n/i)==1) return n/i;
    }
    return 0;
}
int main(){
    int a,b;
    cout<<"Nhap vao so a: ";
    cin>>a;
    cout<<"Nhap vao so b: ";
    cin>>b;
    if(UCLNisPrime(UCLN(a, b))==0) cout<<"-1"; // Không có giá trị nào
    else cout<<"Uoc Chung Lon Nhat Cua a va b La So Nguyen To: "<<UCLNisPrime(UCLN(a, b));
    return 0;

}