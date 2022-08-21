#include <iostream>
using namespace std;
int main(){
int a;
cin>>a;
int i=1;
while(i<=5){
for(int j=1;j<=4;j++){
if(i==1 || i==5) cout<<a<<" ";
else
if(j==1 || j==4) cout<<a<<" ";
else cout<<"  ";
}
i++;
}
}
