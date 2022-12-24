/*Dãy cấp số cộng là một dãy số thoả mãn điều kiện: hai phần tử liên tiếp nhau sai khác nhau một hằng số (gọi là công sai của cấp số cộng).

Ví dụ: Dãy số: 3, 5, 7, 9, 11, ...3,5,7,9,11,... là một cấp số cộng với các phân tử liên tiếp sai khác nhau với công sai là 2.

Cho một dãy số nguyên aa gồm nn phần tử (1≤n≤10^6)(1≤n≤10). Hãy kiểm tra xem dãy đó có phải là dãy cấp số cộng hay không?*/
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