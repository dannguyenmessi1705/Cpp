#include <iostream>
using namespace std;
int Ktra(int y){
    if((y%4==0 && y%100!=0) || y%400==0)
        return 1;
    else return 0;
}
int main(){
    int m,y;
    cin>>m>>y;
    if((m<1 || m>100) || (y<1 || y>100000)) cout<<"INVALID";
    switch (m){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout<<31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout<<30;
        break;
    case 2:
        if(Ktra(y)==1) cout<<29;
        else cout<<28;
        break;
    default:
        cout<<"INVALID";
        break;
    }
}