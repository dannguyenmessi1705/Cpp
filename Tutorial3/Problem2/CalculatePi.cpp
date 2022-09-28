#include <bits/stdc++.h>
using namespace std;
double Cal(int n){
    double sum=0, dau=0, k=2;
    for(int i=1;i<n;i++){
        if(i%2==0) dau=1;
        else dau=-1;
        sum+=dau * 1/(i+k);
        k++; 
    }
    return 4*(1 + sum);
}
int main(){
    int n;
    cout<<"PLEASE ENTER the number of terms to use in the series: ";
    cin>>n;
    cout<<"Using "<<n<<" terms the approximate value of pi is: "<<Cal(n);
}