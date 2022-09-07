#include <iostream>
#include <string.h>
using namespace std;
void Cat(char timetmp[], char time[]){
    int k=0;
    for(int i=7;i<strlen(timetmp);i++){
        time[k]=timetmp[i];
        k++;
    }
    time[k]='\0';
}
void KiemTra(char time[]){
    char d='?';
    for(int i=0;i<strlen(time);i++){
        if(time[i]==d && i==1){
            if(time[i+1]==d){
                time[i]='2';
                time[i+1]='3';
            }
            else if((int)(time[i+1]-'0')<=3) 
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
        cout<<time[i];

    }
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        char timetmp[20];
        fgets(timetmp, sizeof(timetmp)+1, stdin);
        char time[10];
        Cat(timetmp, time);
        KiemTra(time);
    }
}