#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;
void Nhap(int size, double *x, double *y){
    for(int i=0;i<size;i++){
        cin>>x[i]>>y[i];
    }
}
void Dis(double *x, double *y, int size){
    double d;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            d = sqrt(pow(x[j]-x[i],2) + pow(y[j]-y[i],2)*1.0);
            d = trunc(100*d)/100;
            cout<<fixed<<setprecision(2)<<d;
            if(j!=size-1)
                cout<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int size;
    cin>>size;
    double *x=new double[size];
    double *y=new double[size];
    Nhap(size,x,y);
    Dis(x,y,size);
    delete[] x;
    delete[] y;
}