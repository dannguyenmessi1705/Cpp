#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> result;
void Recur(int i, int s, int n, vector <int> x){
	if (i > n || s > n)
	return;
	if (s==n){
	result.push_back(x);
	return;
	}
	for (int k = i; k < n; k++){
		if (s * k > n)
		return;
		if (n%k==0){
			x.push_back(k);
			// Lay k roi thi nhan k vao s
			Recur(k, s*k, n, x);
			// lay phan tu vao th�  day phan tu 0 o dau ra
			// tranh sai kich thuoc mang
			x.pop_back();
		}	
	}
}
void PhanTich(int n){
	vector <int> x;
	x.clear();
	Recur(2, 1, n , x);
}
int main (){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		//Tim nghiem luu vao vector ket qua
		result.clear();
		PhanTich(n);
		cout<<result.size()<<endl;
		for (int i = 0; i < result.size(); i++){
			for (int j = 0; j < result[i].size(); j++){
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}