#include <bits/stdc++.h>
using namespace std;

int n, check[100005], u[100005], snt[100005], c, ans[100005];
int main() {
    check[1]=1;
    for(int i=2; i*i<=100005; ++i){
        if(check[i]==0) 
            for(int j=i*i; j<=100005; j+=i) 
                check[j]=1;
    }
    for(int i=1;i<=100005; i++) 
        if(check[i]==0) 
            snt[++c]=i;
    for(int i=c; i>=1; i--){
        for(int j=snt[i]; j<=100005; j+=snt[i])
        if(u[j]==0) 
            u[j]=snt[i];
    }
    for(int i=1; i<=100005; i++){
        if(u[i]>sqrt(i)) 
            ans[i]=i;
        else ans[i]=ans[i-1];
    }
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        if(n==0) cout<<-1<<endl;
        else cout<<ans[n]<<endl;
    }
}