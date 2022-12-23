#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
	cin >> t;
	while (t--){
        int n;
        cin >>n;
        int a[n+1], b[n+1];
        for(int i=0; i < n; ++i) cin >>a[i];
        for(int i=0; i < n; ++i){
            cout <<"["<<a[0];
            for(int j = 1 ; j < n-i; ++j){
                cout <<" "<<a[j];
                b[j-1] = a[j] +a[j-1];
            }
            cout <<"]" <<'\n';
            for(int j = 0; j < n - i; ++j) a[j]=b[j];
        }

	}
}