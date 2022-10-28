#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll test, X, Y, M;
int main(){
    cin>>test;
    while(test--){
        cin>>X>>Y>>M;
        ll tong_so_hop = M/X;;
        ll tmp = tong_so_hop;
        while(tmp >= Y){
            ll so_hop_doi_duoc = tmp/Y;
            tong_so_hop += so_hop_doi_duoc;
            tmp -= so_hop_doi_duoc*Y;
            tmp += so_hop_doi_duoc;
        }
        cout<<tong_so_hop<<endl;

    }
}