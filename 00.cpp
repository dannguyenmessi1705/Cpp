#include <iostream>
using namespace std;
void U(int *p, int num){
    int *q;
    q=&num;
    *p=*q+2;
    num=7;
}
void H(int *p, int q, int *num){
    *p=q+*num;
    *num=q;
    num=p;
    p=&q;
    U(num,*p);
}
main(){
    int *q;
    int t[3];
    t[0]=1;
    q=&t[1];
    *q=2;
    t[2]=3;
    H(q,t[0],&t[2]);
    cout<<*q<<" "<<t[0]<<" "<<t[1]<<" "<<t[2];
}