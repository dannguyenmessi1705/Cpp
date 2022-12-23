#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sbd(int n, int k){
    if (n < k) return 0;
    if (k == 1) return 1;
    ll cnt = n - 1;
    for (int i = 2; i <= k - 1; ++i){
        cnt *= n - i;
        cnt /= i;
    }
    return cnt;
}
int main (){
    int test;
    cin>>test;
    while(test--){
        int n, k;
        cin>>n>>k;
        cout<<sbd(n, k)<<endl;
    }
}