#include<bits/stdc++.h>
using namespace std;
void solve(){
  scanf("\n");
  string s;
  cin >> s;
  stack<char> stk;
  
  for(int i=0;i<s.length();i++){
  	if (i>0 && s[i]=='('){
  		if(s[i-1]=='+' || s[i-1]=='-') stk.push(s[i-1]);
  		else stk.push(stk.top());
		continue;	
	}		
	if(s[i]==')'){
		stk.pop();
		continue;		
	}  	
	if(stk.size()>0){
		if(stk.top()=='-'){
		if(s[i]=='-'){
			s[i]='+';
			continue;
		}
		if(s[i]=='+'){
			s[i]='-';
			continue;
		}
	}
	}  	
  }
  for(int i=0;i<s.length();i++){
  	while(s[i]=='(' || s[i]==')') s.erase(i,1);
  }
  
  for(int i=0;i<s.length();i++) cout << s[i];
  cout << endl;
}
main(){
  int t;
  cin >> t;
  while(t--)
   solve();
  return 0;
}
// a-((b+c)-(d+e));

