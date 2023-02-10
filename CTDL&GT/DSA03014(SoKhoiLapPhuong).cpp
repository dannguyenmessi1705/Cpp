#include<bits/stdc++.h>
using namespace std;
int m,a[18];
vector<int> v;
long long max_v=-1;

map<long long,bool> map_v;

	

void nhi_phan(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i==m){
		long long sum=0;			
				for(int j=1;j<=m;j++){
					if(a[j]==1){
						sum+=v[j-1];
						sum*=10;
					}
				}			
			sum/=10;
			if(map_v[sum]==1 && sum > max_v && sum!=0) max_v=sum;		
		}
		else{
			nhi_phan(i+1);
		}
	}
}
void solve(){
  long long n;
  cin >> n;
  
  while(n>0){
  	v.push_back(n%10);
  	n/=10;
  }
  reverse(v.begin(),v.end());
  
  m=v.size();
  nhi_phan(1);
  
  cout << max_v;
  max_v=-1;
  v.clear();
  cout << endl;
}
main(){
  for(long long i=1;i<100009;i++) map_v[i*i*i]=1;
  int t;
  cin >> t;
  while(t--)
   solve();
  return 0;
}