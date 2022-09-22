#include <bits/stdc++.h>
using namespace std;
string SUM(string &n1, string &n2){
    if(n1.length()<n2.length()){
        swap(n1, n2);
    }
    string tmp="";
    int l1=n1.length();
    int l2=n2.length();
    int dis=l1-l2; // n1 dài hơn n2 bao số
    int sum=0;
    int nho=0; // lưu biến nhớ
    for(int i = l2-1;i>=0;i--){
        sum = (n1[i+dis]-'0')+(n2[i]-'0')+nho;
        int donvi = sum%10; // tìm giá trị đơn vị
        nho = sum/10;
        tmp.push_back(donvi+'0');
    }
    for(int i = dis-1;i>=0;i--){
        sum=(n1[i]-'0') + nho;
        int donvi = sum%10;
        nho = sum/10;
        tmp.push_back(donvi+'0');
    }
    if(nho>0){
        tmp.push_back(nho +'0');
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}
int main(){
    string n1;
    string n2;
    int test;
    cin>>test;
    cin.ignore();
    while(test--){
        cin>>n1;
        cin>>n2;
        cout<<SUM(n1, n2)<<endl;
    }
}