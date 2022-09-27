#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void Nhap(lli a[], lli n){
    for(lli i=0;i<n;i++)
        cin>>a[i];
}
void Max(lli a[], lli n){
    lli max1=a[0], max2=0, tmp=a[0];
    lli ktd=0;
    for(lli i=0;i<n;i++){
        if(a[i]>0) ktd=1;
        else 
            if(a[i]>max1) max1=a[i];
    }
    if(ktd==0) cout<<max1;
    else{
        for(lli i=0;i<n;i++){
            max2+=a[i];
            if(max2<0){
                max2=0;
                continue;
            }
            if(max2>tmp) tmp=max2;
        }
        cout<<tmp;
    }
}
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli a[n];
        Nhap(a,n);
        Max(a,n);
		cout<<endl;
    }
}
