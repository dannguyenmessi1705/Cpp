#include <bits/stdc++.h>
using namespace std;
int test, n, k, x, y, NuocDi[20][20];
int l[]={-2,-2,-1,-1,1,1,2,2};
int r[]={-1,1,-2,2,-2,2,-1,1};
bool check(int x, int y, int n){
  	if(1<=x && x<=n && 1<=y && y<=n) return true;
  	return false;
}
void Try(int a, int b, int step){
  	if(step==k+1) return;
  	NuocDi[a][b]=1;
	for(int i=0;i<=7;i++){
    if(check(a+l[i],b+r[i],n)==true){
      	Try(a+l[i],b+r[i],step+1);
    	}
  	}
}
int main () {
    cin>>test;
    while(test--){
        cin >> n >> k >> x >> y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                NuocDi[i][j]=0;
            }
        }
        Try(x,y,0);
        int tmp=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(NuocDi[i][j]==1) tmp++;
            }
        }
        cout<<tmp<<endl;
    }
}
