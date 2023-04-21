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
int ChiaPhan(int a[], int low, int high){ // Hàm trả về vị trí cần chia pivot 
    int left=low;
    int right=high-1;
    int pivot=a[high];
    while(1){
        while(left<=right && a[left]<pivot) left++;
        while(right>=left && a[right]>pivot) right--;
        if(left>right) break;
        Swap(a[left], a[right]);
        left++;
        right--;
    }
    Swap(a[left], a[high]);
    return left;
}
void Sapxep(int a[], int low, int high){
    if(low < high){
    int pos=ChiaPhan(a, low, high);    Sapxep(a, low, pos-1);
    Sapxep(a, pos+1, high);
    }
}
int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    Nhap(a,n);
    Sapxep(a, 0, n-1);
    Xuat(a,n);
}