#include <iostream>
#include <iomanip>
using namespace std;
float FtoC(float f){
    float kq;
    kq = (f-32)/1.8;
    return kq;
}
float AbsVal(float f){
    float kq;
    kq = ((f-32)/1.8)+273.15;
    return kq;
}
int main(){
    float up, low, step;
    cin>>up>>low>>step;
    cout<<setw(10)<<left<<"F";
    cout<<setw(10)<<left<<"C";
    cout<<setw(20)<<right<<"Absolute Value"<<endl;
    cout<<setfill('-');
    cout<<setw(40)<<"-"<<endl;
    cout<<setfill(' ');
    for(float i=up;i<=low;i+=step){
        cout<<setw(10)<<left<<i;
        cout<<setw(10)<<left<<fixed<<setprecision(3)<<FtoC(i);
        cout<<setw(20)<<right<<fixed<<setprecision(3)<<AbsVal(i);
        cout<<endl;
    }


}
