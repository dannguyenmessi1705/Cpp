#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long long int lli;
int Kiemtra(lli number){
    if(number == 0) return 1;
    double test;
    test = sqrt(number);
    if(test == (int)test) return 1;
    return 0;
}
int TachKiemTra(lli n){
    if(n>=0){
        while(n>0){
            lli a = n%10;
            if(Kiemtra(a)==0) return 0;
            n/=10;
        }
        return 1;
    }
    return 0;
}
lli SoCP(int n){
    if(n<2) return 0;
    else{
        lli a=pow(10,n-1);
        lli b=pow(10,n)-1;
        lli begin;
        if(Kiemtra(a)==0) 
            begin=(int)sqrt(a)+1;
        else 
            begin=sqrt(a);
        for(lli i=begin;i<=(int)sqrt(b);i++){
            lli ktra = 0;
            ktra = i*i;
            if(TachKiemTra(ktra)==1) return ktra;
        }
    }
    return 0;


}
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        cout<<SoCP(n)<<endl;
    }
}