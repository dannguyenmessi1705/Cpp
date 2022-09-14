#include <iostream>
using namespace std;
int CtoF(int n){
    float kq;
    kq = n*1.8+32;
    return kq;
}
int FtoC(int n){
    float kq;
    kq = (n-32)/1.8;
    return kq;
}
int main(){
    int n;
    cin>>n;
    cout<<n<<"C -> "<<CtoF(n)<<"F"<<endl;
    cout<<n<<"F -> "<<FtoC(n)<<"C"<<endl;
}