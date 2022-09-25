#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#define PI 3.14159265358979323846
//calculate value of sin
void cal_sin(double n) {    
    double acc = 0.0001, denominator, sinx, sinval;
    n = n * (PI / 180.0);  //convert in radian
    double temp = n;
    sinx = n;          
    sinval = sin(n);    
    int i = 1;
    do {
        denominator = 2 * i * (2 * i + 1);
        temp = -temp * n * n / denominator;
        sinx = sinx + temp;
        i = i + 1;
    } while (acc <= fabs(sinval - sinx));
    cout<<fixed<<setprecision(6)<<sinx;
}
int main() {
    double n = 6;
    n=(6/PI)*180.0;
    cout<<"value of Sin is : "; cal_sin(n);
cout<<"\n";
    return 0;
}