#include <iostream>
#include <vector>
using namespace std;
void Nhap(vector<long long> Tu, vector<long long> Mau){
    short t, m;
    long long k;
    cin>>t>>m;
    for(int i=0;i<t;i++){
        cin>>k;
        Tu.push_back(k);
    }
    for(int i=0;i<m;i++){
        cin>>k;
        Mau.push_back(k);
    }
}
int maxFraction(vector<long long> Tu, vector<long long> Mau){
    int max=0;
    for(int i=1;i<Tu.size();i++){
        if(((Tu[max]*Mau[i])-(Tu[i]*Mau[max]))<0) 
            max=i;
    }
    return max;
}
int main(){
    vector<long long> Tu; 
    vector<long long> Mau;
    Nhap(Tu, Mau);
    cout<<maxFraction(Tu, Mau);
}