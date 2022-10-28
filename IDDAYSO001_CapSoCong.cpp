#include <iostream>
using namespace std;
typedef long long int ll;
int test, n;
ll Cong_sai, a[10000001];
int main(){
    cin>>test;
    while(test--){
        bool check = true;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        Cong_sai=a[2]-a[1];
        for(int i=2;i<n;i++){
            if(a[i+1]-a[i] != Cong_sai){
                check = false;
                break;
            }
        }
        if(check==true) cout<<"YES\n";
        else cout<<"NO\n";
    }
}