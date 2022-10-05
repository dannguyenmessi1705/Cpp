#include <bits/stdc++.h>
typedef unsigned long long int lli;
using namespace std;

int t;
lli n;
stack<int>st;
int main() {
    cin >> t;
    while(t--){
      cin >> n;
      while(n!=0){ 
          st.push(n%2); // Them gia tri vao ngan xep tu duoi len tren
          n/=2;
      }
      while(!st.empty()) {
        cout<<st.top(); // Lay gia tri dau tien cua ngan xep
        st.pop(); // Loai bo gia tri dau cua ngan xep
      }
      cout<<'\n';
    }

  return 0;
}