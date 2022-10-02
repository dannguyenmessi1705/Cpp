#include <bits/stdc++.h>
using namespace std;
void swap(string &n1, string &n2){
    string tmp = n1;
    n1 = n2;
    n2 = tmp;
}
string SUM(string n1, string n2){
    if(n1.length()<n2.length()){
        swap(n1, n2);
    }
    string tmp(n1.size()+1, 0); // Khai bao chuoi ket qua co do dai max, gia tri 0
    int l1=n1.length();
    int l2=n2.length();
    int dis=l1-l2; // n1 dài hơn n2 bao số
    int sum=0;
    int nho=0; // lưu biến nhớ
    int k=tmp.size();; // lưu biến độ dài trong SUM
    for(int i = l2-1;i>=0;i--){
        sum = (n1[i+dis]-'0')+(n2[i]-'0')+nho;
        int donvi = sum%10; // tìm giá trị đơn vị
        nho = sum/10;
        tmp[--k] = donvi;
    }
    for(int i = dis-1;i>=0;i--){
        sum=(n1[i]-'0') + nho;
        int donvi = sum%10;
        nho = sum/10;
        tmp[--k] = donvi;
    }
    if(nho>0){
        tmp[--k] = nho;
    }
    for(int i=0;i<tmp.size();i++){
        tmp[i]+='0';
    }
    if(tmp[0]=='0'){
        return tmp.substr(1); //Cat chuoi neu ky tu dau bang 0
    }
    return tmp;
}
string MUL(string n1, string n2) {
   if (n1 == "0" || n2 == "0") {
      return "0";
   }
   string product(n1.size() + n2.size(), 0);  //Khai bao kq co chieu dai max, gia tri chuoi la 000...
   for (int i = n1.size() - 1; i >= 0; i--) {
      for (int j = n2.size() - 1; j >= 0; j--) {
            int n = (n1[i] - '0') * (n2[j] - '0') + product[i + j + 1];
            product[i + j + 1] = n % 10;
            product[i + j] += n / 10;
      }
   }
   for (int i = 0; i < product.size(); i++) { //Doi ve bang Ascii
      product[i] += '0';
   }
   if (product[0] == '0') { 
      return product.substr(1); //Cat chuoi neu gia tri dau la so 0
   }
   return product;
}
int main() {
    ifstream FileIn;
    ofstream FileOut;
    FileIn.open("bignumber.in", ios::in);
    FileOut.open("bignumber.out", ios::out);
    if(FileIn.fail()) return 0;
    int test;
    FileIn>>test;
    FileIn.ignore();
    while(test--){
        string nhap="";
        getline(FileIn, nhap);
        int x=0, y=0;
        for(int i=0;nhap[i]!=' ';i++){
            x++;
        }
        for(int i=nhap.size()-1;nhap[i]!=' ';i--){
            y++;
        }
        string n1=nhap.substr(0, x);
        string n2=nhap.substr(nhap.size()-y, y);
        if(nhap[x+1]=='+'){
            FileOut<<SUM(n1,n2)<<endl;
        }
        else{
            if((n1[0] == '-' || n2[0] == '-') && (n1[0] != '-' || n2[0] != '-')) {
            FileOut<<"-";
            }
            if(n1[0] == '-') {
                n1 = n1.substr(1);
            }
            if(n2[0] == '-') {
                n2 = n2.substr(1);
            }
            FileOut<<MUL(n1, n2)<<endl;
        }
    }
    return 0;
}