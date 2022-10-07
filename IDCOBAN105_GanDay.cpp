#include <bits/stdc++.h>
using namespace std;
const long int MOD = 1e9 + 7;
int main(){
	int test;
	cin>>test;
	while (test--){
		int n;
		cin>>n;
		int x, s = 0;
        // Hang doi uu tien, sap xep thu tu tu nho den lon, khong lam bai toan TLE
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i=0; i<n; i++){
			cin>>x; // Nhap chieu dai cac day
			q.push(x); // Push tung day vao hang doi tu duoi len tren, vi su dung hang doi uu tien priority_queue
                       // Nen phan tu sau khi push vao se lai tu dong sap xep tu tren xuong theo tu nho den lon
		}
		while (q.size() > 1){ // Neu hang doi co hon 1 phan tu thi moi thuc hien noi day duoc
			int s1 = q.top(); // Lay phan tu dau tien cua hang doi
			q.pop(); // Xoa phan tu vua lay ra
			int s2 = q.top(); // Sau khi xoa phan tu dau tien, hang doi tiep tuc day len gia tri khac, lay phan tu do ra s2 
			q.pop(); // Xoa phan tu vua lay ra
			int k = (s1 + s2) % MOD; // Tinh tong chieu dai cua 2 day vua lay roi chia cho MODULE theo de bai 
			s = (s + k) % MOD; // Tra ve ket qua tong chieu dai sau khi noi cac day
			q.push(k); // Tiep tuc push tong chieu dai cua 2 day vao hang doi, tu sap xep tu nho den lon, tao thanh 1 day moi
		}
		cout<<s<<endl;
	}
}