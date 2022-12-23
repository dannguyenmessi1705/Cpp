#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
string PowerOf2(int n){
    if(n==0){
        return "1";
    }
    string s(MAX, '0');
    int size = 0, tmp = 2, value = 0, nho = 0;
    while(tmp != 0){
        s[size++] = tmp % 10 + '0';
        tmp/=10;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < size; j++){
            value = 2 * (s[j] - '0') + nho;
            nho = value / 10;
            if(j == size-1) 
                if(2 * (s[j] - '0') + nho >= 10)
                    size++;
            s[j] = (value % 10) + '0';
        }
    }
    string result(size, 0);
    int k = 0;
    for(int i = size-1; i >= 0; i--){
        result[k++] = s[i];
    }
    return result;
}
string Factorial(int n){
    if(n==0 || n==1){
        return "1";
    }
    string s(MAX, '0');
    int tmp = n, size = 0, nho = 0, value = 0;
    while(tmp != 0){
        s[size++] = tmp % 10 + '0';
        tmp/=10;
    }
    for(int i=2; i<n; i++){
        for(int j=0; j<size; j++){
            value = i * (s[j] - '0') + nho;
            nho = value / 10;
            s[j] = (value % 10) + '0';    
            if(j == size-1) 
                while(value >= 10){
                    value/=10;
                    size++;
                }
        }
    }
    string result(size, 0);
    int k = 0;
    for(int i = size-1; i >= 0; i--){
        result[k++] = s[i];
    }
    return result;

}
string MULTIPLY(int n){
    string a = PowerOf2(n);
    string b = Factorial(n);
    int len = a.length() + b.length();
    string result(len, 0);
    for(int i=a.length()-1; i>=0; i--){
        for(int j=b.length()-1; j>=0; j--){
            int value = (a[i]-'0') * (b[j]-'0') + result[i+j+1];
            result[i+j+1] = (value%10);
            result[i+j] += (value/10);
        }
    }
    for(int i=0; i<len; i++){
        result[i]+='0';
    }
    if(result[0] == '0'){
        return result.substr(1);
    }
    return result;
}
int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<MULTIPLY(n)<<endl;
    }
}