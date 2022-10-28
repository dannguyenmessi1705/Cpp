#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
// Ham nhap mang 
void Nhap(lli *a, lli n){
    for(lli i=0;i<n;i++)
        cin>>*(a+i);
}
// Ham tim day con co tong la lon nhat
void Max(lli *a, lli n){
    lli max1=a[0], max2=0, tmp=a[0];
    lli ktd=0; // Bien kiem tra day con co tong max bat dau xuat phat tu vi tri nao(0 la day am, 1 la chi kiem tra day con co so duong)
    for(lli i=0;i<n;i++){
        if(a[i]>0){
            ktd=1; // Neu la phan tu co gia tri am thi bo qua, duong thi bat dau danh dau vi tri xuat phat roi xet tiep cac vi tri duong khac
            break;
        }
        else 
            if(a[i]>max1) max1=a[i]; // Neu la gia tri am thi xet tiep cac phan tu sau, de tim gia tri max, neu tat ca phan tu trong mang
                                    // deu la am thi day con co tong max chinh la phan tu max cua mang
    }
    if(ktd==0) cout<<max1; // ktd=0, chung to cac phan tu trong mang deu la so am, va ta chi can in gia tri max trong mang la xong
    else{ // Nguoc lai neu xuat hien phan tu duong
        for(lli i=0;i<n;i++){ // Xet tu dau den cuoi mang
            max2+=a[i];
            if(max2<0){ // Neu max2<0, chung to da cong voi 1 phan tu am nao do trong mang, ta bo qua bang viec dat lai gia tri max2=0
                max2=0;
                continue;
            }
            if(max2>tmp) tmp=max2; // Neu max2 > tmp thi gia tri day con co tong max chinh la tmp
        }
        cout<<tmp;
    }
}
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli a[n];
        Nhap(a,n);
        Max(a,n);
		cout<<endl;
    }
}
