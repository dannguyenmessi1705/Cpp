#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
struct ThuaSo{
    lli Uoc[10000];
    lli SL[10000];
    int dem;
} typedef TS;
void PhanTich(lli n){
    TS z;
    z.dem=0;
    int x=0, tmp=0;
    z.Uoc[x]=0, z.SL[x]=0;
    while(n%2==0){
        n/=2;
        tmp++;
    }
    if(tmp>0){
        z.Uoc[x]=2;
        z.SL[x]=tmp;
        x++;
    }
    for(lli i=3; i<=sqrt(n);i+=2){
        tmp=0;
        while(n%i==0){
            tmp++;
            n/=i;
        }
    if(tmp>0){ 
        z.Uoc[x]=i;
        z.SL[x]=tmp;
        x++;
    }
    }
    if(n>2){
        z.Uoc[x]=n;
        z.SL[x]=1;
    }
    for(int i=0;z.Uoc[i]!=0;i++){
        z.dem++;
    }
    cout<<z.dem<<endl;
    for(int i=0;z.Uoc[i]!=0;i++){
        cout<<z.Uoc[i]<<" "<<z.SL[i]<<endl;
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