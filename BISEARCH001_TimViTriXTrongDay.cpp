
#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005], b[100005];
int binarySearch(int x){
    int l=1, r=n;
    while(l<=r){
        int mid=(r+l)/2;
        if(a[mid]==x && a[mid-1]<x) return mid;
        if(a[mid]>=x) r=mid-1;
        else l=mid+1;
    }
    return 0;
}
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) 
        cin >> a[i];
    for(int i=1; i<=m; i++) 
        cin >> b[i];
    for(int i=1; i<=m; i++){
        cout << binarySearch(b[i])<<" ";
    }
}