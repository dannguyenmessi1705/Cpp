// Sap xep tang dan
#include <iostream>
using namespace std;
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
void Merge(int a[], int left, int mid, int right){
	int n1 = mid - left +1;
	int n2 = right - mid;
	int *x = new int[n1];
	int *y = new int[n2];
	for(int i=0;i<n1;i++){
		x[i] = a[left + i];
	}
	for(int j=0;j<n2;j++){
		y[j] = a[mid + 1 + j];
	}	
	int i=0, j=0, k=left;
	while(i<n1 && j<n2){
		if(x[i]<y[j]){
			a[k] = x[i++];
		}
		else
			a[k]=y[j++];
		k++;
	}
	while(i<n1){
		a[k++]=x[i++];
	}
	while(j<n2){
		a[k++]=y[j++];
	}

}
void MergeSort(int a[], int left, int right){
	if(left < right){
		int mid = left + (right - left)/2;
		MergeSort(a, left, mid);
		MergeSort(a, mid+1, right);
		Merge(a, left, mid, right);
	}
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	Nhap(a, n);
	MergeSort(a, 0, n-1);
	Xuat(a, n);
}
