#include <bits/stdc++.h>
using namespace std;
static char ListPass[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz" "@%&";
int lenchar = sizeof(ListPass) - 1;
char GenPass(){
    return ListPass[rand() % lenchar];
}
int main(){
    srand(time(0));
    int dai, t=0;
    do{
        if(t!=0) cout<<"DO DAI CUA PASSWORD KHONG HOP LE!\n";
        cout<<"NHAP DO DAI MUON TAO PASSWORD: ";
        cin>>dai;
        t++;
    }while(dai<6);
    cout<<"PASSWORD CUA BAN LA: ";
    for(int i=0;i<dai;i++) cout<<GenPass();
    return 0;
}