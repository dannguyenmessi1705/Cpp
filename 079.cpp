#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long dp[n+5];
		// dp la so cach it nhat de phan tich so i
		// thanh cac so nho hon ma tong binh phuong
		// bang n
		for(int i=0;i<=n;i++){
			dp[i] = i;
			// cho tat ca deu la 1^2 het
			// thi tai vi tri i thi co i cach bieu dien
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=sqrt(i);j++){
				dp[i] = min(dp[i],dp[i-j*j]+1);
			}
		}
		cout << dp[n] << " ";
	}
}