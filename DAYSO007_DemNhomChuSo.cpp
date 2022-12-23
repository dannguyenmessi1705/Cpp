#include <bits/stdc++.h>
using namespace std;
#define MAX 40
int D[MAX][10 * MAX]; 

int DemNhom(int curr_pos, int curr_sum, int N, char * num){
	if(curr_pos == N)
		return 1;
	if(D[curr_pos][curr_sum] != -1)
		return D[curr_pos][curr_sum];	
	D[curr_pos][curr_sum] = 0;
	int sum = 0;
	int temp = 0;
	for (int i = curr_pos; i < N; i++){
		sum += (num[i] - 48);
		if(sum >= curr_sum)
		    temp += DemNhom(i+1, sum, N, num); 
	}
	D[curr_pos][curr_sum] = temp;
	return temp;
}
int main (){
	int test;
	cin>>test;
	while(test--){
		int N;
		cin>>N;
		char num[MAX + 1];
		for(int i = 0; i < N; i++){
			cin>>num[i];
		}
		num[N] = '\0'; //ki tu ket thuc xau
		memset(D, -1, sizeof(D));
		cout<<DemNhom(0, 0, N, num)<<endl;
	}
}