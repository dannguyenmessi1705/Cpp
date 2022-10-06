#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
// Lay M chu so tu kq N^K
void findFirstAndLastM(lli N, lli K, lli M){
    // Ham tinh M chu so cuoi cung cua Ham mu
    /*lli lastM
        = modPower(N, K, (1LL) * pow(10, M)); // Ham tinh mu su dung Module 10^9+7 o bai COBAN005
	*/
    // Ham tinh M chu so dau tien cua Ham mu
    lli firstM;
	/*
	So N^K co the viet thanh 10^Y, Y la so thap phan N^K=10^Y
	=> Y = K * log10(N)
	*/
    double y = (double)K * log10(N * 1.0);
 
	/*
	Y se co dang so thap phan abc.xyz => N^K = 10^abc.xyz
	10^abc.xyz = 10^abc+0.xyz = 10^abc * 10^0.xyz
	*/
    // Lay phan so thap phan sau dau "."
    y = y - (lli)y;
 
    // Tinh 10^y
    double temp = pow(10.0, y);
 
    // Di chuyen M-1 chu so len phia truoc, vi 10^0 <=> M=1 => phai lay M-1
    firstM = (lli)(temp * pow(10, M - 1));
 
    // In KQ
    cout<<firstM<<endl;
}

int main(){
	int test;
	cin>>test;
	while(test--){
    	lli N, K, M;
		cin>>N>>K>>M;
		findFirstAndLastM(N, K, M);
	}
    return 0;
}