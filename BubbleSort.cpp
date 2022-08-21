// Sắp xếp tăng dần
#include <iostream>
using namespace std;
void Swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}
void Nhap(int a[], int n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void Xuat(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void Sapxep(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) 
                Swap(a[j], a[j+1]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    Nhap(a,n);
    Sapxep(a,n);
    Xuat(a,n);
}