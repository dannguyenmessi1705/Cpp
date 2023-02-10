#include<bits/stdc++.h>
using namespace std;
int n,c[16][16],x[16],check[16],res=1e18,cmin=1e18,s;
void Try(int i){
	for(int j=2;j<=n;j++){
		if(!check[j]){
			check[j]=1;
			x[i]=j;
			s+=c[x[i-1]][j];
			if(i==n){
				if(s+c[j][1]<res){
					res=s+c[j][1];
				}
			}
			else if(s+(n-i+1)*cmin<res){
				Try(i+1);
			}
			s-=c[x[i-1]][j];
			check[j]=0;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]<cmin and c[i][j]!=0){
				cmin=c[i][j];
			}
		}
	}
	x[1]=1;
	Try(2);
	cout<<res<<endl;
}
