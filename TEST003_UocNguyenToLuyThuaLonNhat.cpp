#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define MAX 100000
ull Coso[MAX], Mu[MAX];
void PhanTich(ull n, ull Coso[], ull Mu[]){
    ull k = 0, count, mincoso=0, maxmu=0;
    for(ull i=2; i<=n; i++){
        count=0;
        if(n%i==0) Coso[k]=i;
        while(n%i==0){
            n/=i;
            count++;
        }
        Mu[k]=count;
        if(count!=0){ 
            if(Mu[k]>maxmu){
                maxmu = Mu[k];
                mincoso = Coso[k];
            }
            k++;
        }
    }
    cout<<mincoso<<" "<<maxmu;
}
int main(){
    int test;
    ull n;
    cin>>test;
    while(test--){
        cin>>n;
        PhanTich(n, Coso, Mu);
        cout<<endl;
    }
}
