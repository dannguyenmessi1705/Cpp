// Bai toan Quy Hoach Dong
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(x,a,b) for(int x=a;x<=b;x++)
void Nhap(int A[][105], int m, int n){
    F(i,1,m){
        F(j,1,n){
            cin>>A[i][j];
        }
    }
}
int main(){
    int test;
    cin>>test;
    while(test--){
        int m, n, Gia_tri_max = -INT_MAX; 
        int A[105][105], MAX[105][105];
        cin>>m>>n;
        Nhap(A,m,n);
        F(i,1,n){
            MAX[0][i] = MAX[m+1][i] = -INT_MAX; // Khoi tao 2 can tren duoi cua MT = - infinity
        }
        // Cho cot dau tien cua MA Tran F = cot dau tien cua Ma Tran A, do lan can cua no khong co so nao hoac la -infinity
        // Nen gia tri Max cot 1 cua Ma tran F = Gia tri cot dau cua Ma Tran A
        F(i,1,m){
            MAX[i][1] = A[i][1];
        }
        // Xet gia tri tu cot thu 2 cua Ma Tran
        // Gan gia tri max cho Ma Tran F tu MA tran A + gia tri max cua 1 trong 3 o di lui lai so voi de bai
        // De  bai 3 o next la   (i, j+1), (i-1, j+1), (i+1, j+1)
        // Lui lai cua 3 o do la (i, j-1), (i+1, j-1), (i-1, j-1)
        F(j,2,n){
            F(i,1,m){
                MAX[i][j] = A[i][j] + max(max(MAX[i-1][j-1], MAX[i][j-1]), MAX[i+1][j-1]);
            }
        }
        // Sau khi quy hoach xong, cac gia tri max se o cot cuoi cung cua ma Tran
        // Tim 1 gia tri max trong cot do roi in kq
        F(i,1,m){
            Gia_tri_max = max(Gia_tri_max, MAX[i][n]);
        }
        cout<<Gia_tri_max<<endl;
    }
}