#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
// Ham chuyen string nhi phan ve so thap phan
ull StringBinToDec(string s, int n){
    ull sum = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1'){ // Chi xet den bit 1, bit 0 ko co anh huong den kq
            sum |= 1<<(n-i-1); // sum = sum || 1<<(n-i-1) hay sum += 1.2^(n-i-1), (n-i-1) la so thu tu cua bit '1' tu trai sang
        }
    }
    return sum;
}
// Ham tim khoang cach giua 2 xau nhi phan VD: 100 vs 001(4 vs 1) Co 2 & 3 o giua (2 so)
ull Count(string a, string b, int n){
    ull A = StringBinToDec(a, n);
    ull B = StringBinToDec(b, n);
    if (A == B) return 0; // Khong co so nao o giua
    else if(A > B) return A - B - 1;
    else return B - A - 1; 
}
int main(){
    int test;
    cin>>test;
    while(test--){
        string s1, s2;
        int n;
        cin>>n>>s1>>s2;
        cout<<Count(s1, s2, n)<<endl;
    }
}