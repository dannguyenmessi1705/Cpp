#include <bits/stdc++.h>
#include "GenCheck.cpp"
using namespace std;
static char ListPass[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz" "@%&";
int lenchar = sizeof(ListPass) - 1;
char GenPass(){
    return ListPass[rand() % lenchar];
}
int main(){
    int dai, t=0;
    string Pass = "";
    do{
        if(t!=0) cout<<"DO DAI CUA PASSWORD KHONG HOP LE!\n";
        cout<<"NHAP DO DAI MUON TAO PASSWORD: ";
        cin>>dai;
        t++;
    }while(dai<6);
    cout<<"PASSWORD CUA BAN XUAT HIEN TRONG GIAY LAT: ";
    do{    
        srand(time(0));
        Pass="";
        for(int i=0;i<dai;i++)
        Pass+=GenPass();
    }while(!(CheckChar(Pass)&&CheckLowUp(Pass)));
    cout<<Pass;
    return 0;
}