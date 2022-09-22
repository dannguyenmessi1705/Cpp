#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream FileIn;
    FileIn.open("points.inp", ios::in);
    if(FileIn.fail()) return 0;
    int size;
    FileIn>>size;
    double *x=new double[size];
    double *y=new double[size];
    for(int i=0;i<size;i++){
        FileIn>>x[i]>>y[i];
    }
    ofstream FileOut;
    FileOut.open("points.out", ios::out);
    double dis;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            dis = sqrt(pow(x[j]-x[i],2) + pow(y[j]-y[i],2)*1.0);
            FileOut<<fixed<<setprecision(2)<<dis;
            if(j!=size-1)
                FileOut<<" ";
        }
        FileOut<<"\n";
    }
    delete[] x;
    delete[] y;
}