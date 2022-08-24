#include<iostream>
using namespace std;
void Nhap(int a[], int &n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void Xuat(int a[], int &n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void Merge(int a[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int *L = new int[n1];
    int *R = new int[n2];
    for(int i=0;i<n1;i++){
        L[i]=a[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=a[m+1+j];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]) a[k]=L[i++];
        else a[k]=R[j++];
        k++;
    }
    while(i<n1){ // Neu mang L con thua phan tu
        a[k++]=L[i++];
    }
    while(j<n2){ // Neu mang R con thua phan tu
        a[k++]=R[j++];
    }
    delete[] L;
    delete[] R;
}
void MergeSort(int a[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2; // Tranh tran bo nho so voi (l+r)/2
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        Merge(a, l, m, r);
    }
}
int BinSearch(int a[], int l, int r, int x){
    if(l<r){
        int m=l+(r-l)/2;
        if(a[m]==x) 
            return m;
        else if(a[m]<x) // Chi duyet mang ben phai
            return BinSearch(a, m+1, r, x);
        else // Chi duyet mang ben trai
            return BinSearch(a, l, m-1, x);
    }
    return -1; // Khong tim kiem duoc phan tu nao
}
int main(){
    int n, x;
    cin>>n;
    int *a=new int[n];
    Nhap(a, n);
    MergeSort(a, 0, n-1);
    cout<<"Mang da sap xep de tim kiem: ";
    Xuat(a, n);
    cout<<"\nNhap gia tri can tim kiem trong mang: ";
    cin>>x;
    if(BinSearch(a, 0, n-1, x)==-1) 
        cout<<"Khong co phan tu nao trong mang";
    else
        cout<<"Phan tu "<<x<<" can tim o vi tri thu: "<<BinSearch(a, 0, n-1, x);
    delete[] a;
}