#include "Object.h"
void Login(){
    system("Color 02");
    Customer x;
    string us, pass;
    do{
        system("Color 02");
        system("cls");
        cout<<"\n\t\tVui long nhap tai khoan:";
        cout<<"\n\t\tUser: ";
        cin>>us;
        cout<<"\t\tPassword: ";
        cin>>pass;
        if(!x.CheckLogin(us, pass)){
            TextColor(4);
            cout<<"\t\tThong tin tai khoan hoac mat khau khong hop le";
            Sleep(1000);
        }
    }while(!x.CheckLogin(us, pass)); 
    TextColor(11);
    cout<<"\t\tDang nhap thanh cong";
    Sleep(1000);
}