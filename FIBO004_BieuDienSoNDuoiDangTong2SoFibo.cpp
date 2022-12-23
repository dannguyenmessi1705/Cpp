#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, f[10005], n;
    f[1]=0, f[2]=1;
    for(int i=3; i<=32; i++) 
        f[i]=f[i-1]+f[i-2];
    cin >>t;
    while(t--){
        cin >> n;
        int z=0;
        for(int i=1; i<=32; i++){
        for(int j=i+1; j<=32; j++){
            if(f[i]+f[j]==n){
                cout<<f[i]<<" "<<f[j]<<'\n'; 
                z=1; 
                break;
            }
        }
        if(z==1) break;
        }
        if(z==0) cout<<-1<<endl;
    }
}