#include <iostream>
#include <string>
using namespace std;
string KiemTra(string time){
    char d='?';
    for(int i=1;i<time.length()-1;i++){
        if(time[i]==d && i==1){
            if(time[i+1]==d){
                time[i]='2';
                time[i+1]='3';
            }
            else if((int)(time[i+1]-'0')<=2) 
                time[i]='2';
            else 
                time[i]='1';
        }
        if(time[i]==d && i==2){
            if((int)(time[i-1]-'0') < 2)
                time[i]='9';
            else time[i]='3';
        }
        if(time[i]==d && i==4){
            time[i]='5';
        }
        if(time[i]==d && i==5){
            time[i]='9';
        }

    }
    return time;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string time;
        cout<<"time = ";
        cin>>time;
        cout<<KiemTra(time)<<endl;
    }
}