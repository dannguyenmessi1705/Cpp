#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
void PhanTich(lli n){
int dem=0;
    lli Uoc[10000], SL[10000];
    int x=0, tmp=0;
    Uoc[x]=0, SL[x]=0;
    while(n%2==0){
        n/=2;
        tmp++;
    }
    if(tmp>0){
        Uoc[x]=2;
        SL[x]=tmp;
        x++;
    }
    for(lli i=3; i<=sqrt(n);i+=2){
        tmp=0;
        while(n%i==0){
            tmp++;
            n/=i;
        }
    if(tmp>0){ 
        Uoc[x]=i;
        SL[x]=tmp;
        x++;
    }
    }
    if(n>2){
        Uoc[x]=n;
        SL[x]=1;
    }
    for(int i=0;Uoc[i]!=0;i++){
        dem++;
    }
    cout<<dem<<endl;
    for(int i=0;Uoc[i]!=0;i++){
        cout<<Uoc[i]<<" "<<SL[i]<<endl;
    }
    for(int i=0;i<=x;i++){
        Uoc[i]=0, SL[i]=0;
    }
}
int main(){
    int test;
    cin>>test;
    while(test--){
        lli n;
        cin>>n;
        PhanTich(n);
    }
}