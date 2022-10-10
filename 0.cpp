// Tong luy thua bac n
#include <bits/stdc++.h>
using namespace std;
int sum_of_powers(int num, int power, int val){
   int check = (num - pow(val, power));
   if(check == 0){
      return 1;
   }
   else if(check < 0){
      return 0;
   } else {
      int temp = val + 1;
      return sum_of_powers(check, power, temp) + sum_of_powers(num, power, temp);
   }
}
int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		
   int num , power ;
   cin>> num >> power;
   cout<<sum_of_powers(num, power, 1)<<endl;
   }
}
