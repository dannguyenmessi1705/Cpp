#include<bits/stdc++.h>
using namespace std;
int n,check[31],ok=0;
long long s,sum,a[31];
void Try(int i,int figure){
	if(sum==s and i==figure){
		ok=1;
		return;
	}
	if(i==figure and sum!=s){
		return;
	}
	for(int j=1;j<=n;j++){
		if(j>check[i-1]){
			sum+=a[j];
			check[i]=j;
			if(sum<=s){
				Try(i+1,figure);
			}
			sum-=a[j];
			check[i]=0;
		}
    } 
}
void solve(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ok=0;
	int figure;
	for(figure=1;figure<=n;figure++){
		sum=0;
		Try(0,figure);
		if(ok==1){
			break;
		}
	}
	if(ok==1){
		cout<<figure<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
