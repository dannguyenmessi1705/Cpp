#include <bits/stdc++.h>
using namespace std;
// Ham tim luy thua lon nhat cua so nguyen to
long long findPowerPrime(long long fact, long long p){
	long long res = 0;
	while (fact > 0){
		res += fact / p;
		fact /= p;
	}
	return res;
} 
// Tra ve tat ca cac tong thua so cua N
long long findPowerComposite(long long fact, long long n){
    long long res = INT_MAX;
    for (int i = 2; i <= sqrt(n); i++) {
        long long count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count > 0) {
            long long curr_pow = findPowerPrime(fact, i) / count;
            res = min(res, curr_pow);
        }
    }
    if (n >= 2) {
        long long curr_pow = findPowerPrime(fact, n);
        res = min(res, curr_pow);
    }
    return res;
}

int main (){
	int test;
	cin>>test;
	while(test--){
		long long fact, n;
		cin>>fact>>n;
		cout<<findPowerComposite(fact, n)<<endl;
	}
}