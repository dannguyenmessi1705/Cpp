#include <iostream>
#include <string>
using namespace std;
void swap(string &n1, string &n2){
    string tmp = n1;
    n1 = n2;
    n2 = tmp;
}
void SUM(string &n1, string &n2){
    if(n1.length()<n2.length()){
        swap(n1, n2);
    }
    string tmp="";
    int l1=n1.length();
    int l2=n2.length();
    int dis=l1-l2; // n1 dài hơn n2 bao số
    int sum=0;
    int nho=0; // lưu biến nhớ
    int k=0; // lưu biến độ dài trong SUM
    for(int i = l2-1;i>=0;i--){
        sum = (n1[i+dis]-'0')+(n2[i]-'0')+nho;
        int donvi = sum%10; // tìm giá trị đơn vị
        nho = sum/10;
        tmp[k++] = donvi+'0';
    }
    for(int i = dis-1;i>=0;i--){
        sum=(n1[i]-'0') + nho;
        int donvi = sum%10;
        nho = sum/10;
        tmp[k++] = donvi+'0';
    }
    if(nho>0){
        tmp[k++] = nho +'0';
    }
    tmp[k]='\0';
    
    for(int i=k-1;i>=0;i--) cout<<tmp[i];
}
int main(){
    string n1;
    string n2;
    cin>>n1;
    cin.ignore();
    cin>>n2;
    cin.ignore();
    SUM(n1, n2);
}