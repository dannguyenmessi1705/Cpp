#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
string Pass;
bool CheckLength(){
    if(Pass.length()>=6) return true;
    return false;
}
bool CheckChar(){
    bool checkdigit = false, checkspecial = false;
    f(i, 0, Pass.length()){
        if(Pass[i] - '0' >= 0 && Pass[i]-'0' <=9) checkdigit = true;
        if(Pass[i] == '@' || Pass[i] == '%' || Pass[i] == '&') checkspecial = true;
        if(checkdigit && checkspecial) return true;
    }
    return false;
}
bool CheckLowUp(){
    bool checkup = false, checklow = false;
    f(i, 0, Pass.length()){
        if(Pass[i]>=65 && Pass[i]<=90) checkup = true;
        if(Pass[i]>=97 && Pass[i]<=122) checklow = true;
        if(checklow && checklow) return true;
    }
    return false;
}
int main(){
    int t = 0;
    do{
        if(t!=0) cout<<"BAN DA NHAP PASSWORD KHONG DUNG DINH DANG!!!\n";
        cout<<"MOI BAN NHAP PASSWORD: ";
        cin>>Pass;
        t++;
    }while(!(CheckChar() && CheckLength() && CheckLowUp()));
    cout<<"CHUC MUNG BAN DA NHAP DUNG DINH DANG PASSWORD";
    return 0;
}