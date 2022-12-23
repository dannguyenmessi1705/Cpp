#include <bits/stdc++.h>
using namespace std;

int p, n, s, a[20], snt[505], c, k, check[505], z;
bool checknt(int n){
    if(n<=1) return 0;
    if(n==2) return 1;
    for(int i=2; i<=sqrt(n); i++) 
        if(n%i==0) return 0;
    return 1;
}
void print(){
    z=1;
    for(int i=1; i<=n; i++) 
        cout<<snt[a[i]]<<" ";
    cout<<endl;
}
void Try(int k, int sum){
    if(k==n+1){
        if(sum==s) print();
    }
    else{
        for(int i=a[k-1]+1; i<=c; i++){
            if(check[i]==0){
                if(sum+i<=s){
                    check[i]=1;
                    a[k]=i;
                    Try(k+1,sum+snt[i]);
                    check[i]=0;
                }
            else break;
            }
        }
    }
}
int main(){
    cin>>p>>n>>s;
    for(int i=p+1; i<=s; i++) 
        if(checknt(i)) 
            snt[++c]=i;
    Try(1,0);
    if(z==0) cout<<-1;
    return 0;
}