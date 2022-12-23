#include <bits/stdc++.h>
using namespace std;
int t, n, a[15][15], ans, check[15][15];
void mark(int x, int y, int key){
    for(int j=1; j<=n; j++){
        check[x][j]+=key; 
        check[j][y]+=key;
    }
    int z=1;
    while(x+z<=n && y+z<=n){ 
        check[x+z][y+z]+=key; 
        z++;
    }
    z=1;
    while(x+z<=n && y-z>=1){ 
        check[x+z][y-z]+=key;
        z++;
    }
    z=1;
    while(x-z>=1 && y+z<=n){ 
        check[x-z][y+z]+=key;
        z++;
    }
    z=1;
    while(x-z>=1 && y-z>=1){ 
        check[x-z][y-z]+=key;
        z++;
    }
}
void Try(int k){
    if(k==n+1) ans++;
    else{
        for(int i=1; i<=n; ++i){
            if(check[k][i]==0){
                mark(k,i,1);
                Try(k+1);
                mark(k,i,-1);
            }
        }
    }
}
int main() {
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) 
                a[i][j]=0;
        ans=0;
        Try(1);
        cout<<ans<<endl;
    }
}