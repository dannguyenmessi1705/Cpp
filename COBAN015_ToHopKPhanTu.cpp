#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int a[1000];
ull GT(int x){
    if(x==0 ||x==1) return 1;
    else return x * GT(x-1);
}
ull SoToHop(int n, int k){
    ull tu, mau;
    tu = GT(n);
    mau = GT(k)*GT(n-k);
    return tu/mau;
}
void Out(int a[], int n, int k){
    cout<<"[";
    for(int i=1; i<=k; i++){
        cout<<a[i];
        if(i != k) cout<<" ";
    }
    cout<<"]\n";
}
void ToHop(int x, int n, int k){
    for(int i = a[x-1]+1; i <= n-(k-x); i++){
        a[x] = i;
        if(x==k) Out(a, n, k);
        else ToHop(x+1, n, k);
    }
}
int main(){
    int n, k, test;
    cin>>test;
    while(test--){
        cin>>n>>k;
        cout<<SoToHop(n, k)<<endl;
        ToHop(1, n, k);
    }
}