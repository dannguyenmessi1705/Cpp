#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
bool CheckLength(string Pass){
    if(Pass.length()>=6) return true;
    return false;
}
bool CheckChar(string Pass){
    bool checkdigit = false, checkspecial = false;
    f(i, 0, Pass.length()){
        if(Pass[i] - '0' >= 0 && Pass[i]-'0' <=9) checkdigit = true;
        if(Pass[i] == '@' || Pass[i] == '%' || Pass[i] == '&') checkspecial = true;
        if(checkdigit && checkspecial) return true;
    }
    return false;
}
bool CheckLowUp(string Pass){
    bool checkup = false, checklow = false;
    f(i, 0, Pass.length()){
        if(Pass[i]>=65 && Pass[i]<=90) checkup = true;
        if(Pass[i]>=97 && Pass[i]<=122) checklow = true;
        if(checklow && checklow) return true;
    }
    return false;
}