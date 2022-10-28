#include <bits/stdc++.h>
using namespace std;
int test, n, k, x, y, NuocDi[20][20];
// Khai bao mang bien la tat ca cac nuoc di cua quan ma tren ban co
int l[]={-2,-2,-1,-1,1,1,2,2};
int r[]={-1,1,-2,2,-2,2,-1,1};
// Ham check nuoc di cua quan ma xem co nam tren ban co hay khong
bool check(int x, int y, int n){
  	if(1<=x && x<=n && 1<=y && y<=n) return true;
  	return false;
}
void Try(int a, int b, int step){
  	if(step==k+1) return; // Dieu kien de rung Ham de quy, so buoc di ma lon hon k theo yeu cau de bai thi ta dung
  	NuocDi[a][b]=1; // Danh dau nuoc da di den co gia tri la 1, de sau nay xet mang 2 chieu, nuoc di nao bang 1 thi ta tang bien dem
	for(int i=0;i<=7;i++){ // Goi vong for chay cac nuoc di kha thi cua quan ma tren ban co, co tong 8 nuoc di
    if(check(a+l[i],b+r[i],n)==true){   // Neu nuoc di cua quan ma la hop le
      	Try(a+l[i],b+r[i],step+1); // De quy ve ham Try de danh dau nuoc di hop le do co gia tri = 1, cung nhu thuc hien tiep nuoc di khac neu so buoc chua du dieu kien de dung lai
    	}
  	}
}
int main () {
    cin>>test;
    while(test--){
        cin >> n >> k >> x >> y;
        // Ham dat cac o tren ban co ve gia tri 0
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                NuocDi[i][j]=0;
            }
        }
        Try(x,y,0); // Ham danh dau nuoc di hop le cua quan ma, o hop le tren ban co se co gia tri la 1
        int count=0;
        // Ham dem so nuoc di
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(NuocDi[i][j]==1) count++;
            }
        }
        cout<<count<<endl;
    }
}
