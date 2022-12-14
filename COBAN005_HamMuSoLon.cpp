#include <iostream>
using namespace std;
typedef unsigned long long int lli;
const long int MOD = 1000000007; // gan MOD = 10^9 + 7
lli powerLL(lli x, lli n){
	lli result = 1;
	while (n) {
		if (n%2==1)
			result = result * x % MOD;
		n = n / 2;
		x = x * x % MOD;
	}
	return result;
}
lli powerStrings(string sa, string sb)
{
	// chuyen dinh dang string sang so

	lli a = 0, b = 0;

	// Tinh a % MOD
	for (int i = 0; i < sa.length(); i++)
		a = (a * 10 + (sa[i] - '0')) % MOD;

	// Tinh b % (MOD - 1)
	for (int i = 0; i < sb.length(); i++)
		b = (b * 10 + (sb[i] - '0')) % (MOD - 1);

	// a va b da co dinh dang la lli, tim a^b bang ham powerLL
	return powerLL(a, b);
}

int main(){
    int test;
    cin>>test;
    while(test--){
	    string sa, sb;
        cin>>sa>>sb;
	    cout<<powerStrings(sa, sb)<<endl;
    }
	return 0;
}