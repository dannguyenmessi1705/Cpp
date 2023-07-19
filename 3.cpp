#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main(){
    int a, b;
    cin>>a;
    scanf("/"); // VD: Nhap 3/4 thi chi in ra 3 4, dong nay nhu de loai bo dau "/" khi minh nhap
                //no se tach 2 so boi dau / thay vi dau cach hoac Enter
    cin>>b;
    cout<<setfill('0')<<setw(2)<<a<<" "<<b; 
}