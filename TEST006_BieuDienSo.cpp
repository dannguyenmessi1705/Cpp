#include <bits/stdc++.h>
using namespace std;

int test, n, m, mu;
int dem(int n, int m, int mu){
    // Dieu kien dung cua De quy
    if(n==0 || mu==0) 
        return 1;
    // Neu n >= m^mu thi De quy de tim tiep 1 nhanh giam dan n = n - pow(m, mu) + 1 nhanh giam dan so mu
    // VD n=10, m=3, mu=2 => (1,3,2) + (10,3,1)
    // Tu cac nhanh do tiep tuc de quy de tim them nhanh moi. VD Nhanh(1,3,2) co nhanh con la (1,3,0) sao cho 3^2+3^0 = 10
    // sau moi 1 nhanh n hoac mu se ve 0, se la 1 bieu thuc can tim
    if(n>=pow(m,mu)) 
        return dem(n-pow(m,mu),m,mu)+dem(n,m,mu-1);
    else 
        return dem(n,m,mu-1);
}
int main(){
    cin >> test;
    while(test--){
        cin >> n >> m;
        int tmp=1, mu=-1;
        // Tim so mu toi da cua co so m (m^mu <= n)
        while(tmp<=n){ 
            tmp*=m;
            mu++;
        }
        cout<<dem(n,m,mu)<<'\n';
    }
    return 0;
}
