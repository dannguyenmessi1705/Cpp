#include <bits/stdc++.h>
using namespace std;
void MaxOfTime(string &hour){
    for(int i=0; i<hour.length(); i++){
        if(hour[i]=='?'){
            if(i==0){
                if((int)(hour[i+1] - '0') <= 3) hour[i]='2';
                else if(hour[i+1]=='?'){
                    hour[i]='2';
                    hour[i+1]='3';
                }
                else hour[i]='1';
            } 
            if(i==1){
                if((int)(hour[i-1] - '0') < 2) hour[i]='9';
                else hour[i]='3';
            }
            if(i==2) hour[i]='5';
            if(i==3) hour[i]='9';
        }
    }
}
string chu, dau, hour;
int test;
int main(){
    cin>>test;
    cin.ignore();
    while(test--){
        cin>>chu>>dau>>hour;
        hour.pop_back();
        hour.erase(hour.begin());
        hour.erase(hour.begin()+2);
        MaxOfTime(hour);
        cout<<"\"";
        for(int i=0;i<hour.length();i++){
            if(i==2) cout<<":";
            cout<<hour[i];
        }
        cout<<"\""<<endl;

    }
}