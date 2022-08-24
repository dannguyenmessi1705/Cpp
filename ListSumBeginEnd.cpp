#include <iostream>
#include <list>
#include <vector>
using namespace std;
list<int> Creat(int n){
    list<int> a;
    int value;
    for(int i=0;i<n;i++){
        cin>>value;
        a.push_back(value);
    }
    return a;
}
int Sum(list<int> a){
    if(a.empty()) return -1;
    else if(a.size()==1) return a.front();
    else return a.front() + a.back();
}
int Xuat(int n){
    list<int> i = Creat(n);
    return Sum(i);
}

int main(){
    int n;
    cout<<"Nhap gia tri cua n: ";
    cin>>n;
    cout<<"Nhap gia tri cua phan tu: ";
    cout<<"Tong la: "<<Xuat(n);

}