#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	int a[k+1]={0};
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int i=k;
	while(a[i]==a[i-1]+1){
		--i;
	}
	if(i==0){
		for(int j=k;j>=1;j--){
			a[j]=n-k+j;
		}
	}
	else{
		a[i]--;
		for(int j=i+1;j<=k;j++){
			a[j]=n-k+j;
		}
	}
	for(int i=1;i<=k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
