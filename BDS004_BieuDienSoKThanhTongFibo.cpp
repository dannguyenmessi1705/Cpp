#include <iostream>
using namespace std;

int Fi[43] = { 0 }; // Day fibo co 42 so la du chua kieu int 

// Ham tim so Fibo thu i
void Fibonacci(){
	Fi[0] = 1;
	Fi[1] = 2;
	for (int i = 2; i < 43; i++)
		Fi[i] = Fi[i - 1] + Fi[i - 2];
}

// Ham tra ve so cach
int BieuDien(int n, int k, int last)
{

	if (k == 0) {
		if (n == 0) // Neu n = 0 && k = 0 thi chi co 1 cach 
			return 1;
		return 0; // Neu n != 0 ma so cach bieu dien k > 0 thi khong co cach nao
	}
	int so_cach = 0; 

    // Cho vao for tim phan tu gan voi n nhat roi de quy cac cach bieu dien thanh k so
	for (int i = last; i >= 0 && Fi[i] * k >= n; i--) {
		if (Fi[i] > n)
			continue;
        // Khi tim duoc Fi[i] <= n thi dequy de tim tiep cac cach
        // VD n=13, k2=2, sau khi tim duoc Fi[5] <= 13, thi se dequy ham voi n = 13-Fi[5], k = k-1 = 2, vi chi con tim 2 so nua co thoa man khong, i chinh la phan tu sao cho Fi[i] max
		so_cach += BieuDien(n - Fi[i], k - 1, i);
	}
	return so_cach;
}

int main(){
	Fibonacci();
    int test;
    cin>>test;
    while(test--){
	    int n, k;
        cin>>n>>k;
		cout<<BieuDien(n, k, 42)<<endl;
    }
	return 0;
}
