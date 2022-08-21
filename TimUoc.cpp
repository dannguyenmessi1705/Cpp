#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0) cout<<"INF";
    else{
        if(n<0) n=n*(-1);
            int tmp;
        	for(int i=1;i<=n;i++){
            	if(n%i==0){
                	tmp = n/i;
                	cout<<tmp<<" ";
            	}
        	}
		}
}