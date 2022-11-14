#include "Object.h"
bool KiemTraDauVao(LIST l, Customer x){
    int checkemail = 0, checkphone = 0; 
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getEmail().c_str(), x.getEmail().c_str())==0)
            checkemail++;
        if(strcmp(k->data.getPhone().c_str(), x.getPhone().c_str())==0)
            checkphone++;
    }
    if(checkemail == 0 && checkphone == 0) return true;
    else if(checkemail > 0 && checkphone > 0) cout<<"\t\tEmail va So dien thoai vua nhap da ton tai\n";
    else if(checkemail == 0 && checkphone > 0) cout<<"\t\tSo dien thoai vua nhap da ton tai\n";
    else cout<<"\t\tEmail vua nhap da ton tai\n";
    return false;
}
void XuatCacTruong(ofstream &FileOut){
    ifstream FileIn;
    FileOut<<setw(lenid)<<left<<"ID";
    FileOut<<setw(lenname)<<left<<"NAME";
    FileOut<<setw(lenaddress)<<left<<"ADDRESS";
    FileOut<<setw(lenemail)<<left<<"EMAIL";
    FileOut<<setw(lenphone)<<left<<"PHONE";
    FileOut<<setw(lenrate)<<left<<"FEEDBACK";
    FileOut<<setw(lenbill)<<left<<"BILL";
    FileOut<<"SERVICE"<<" ";
}

void AddInfoRaFile(ofstream &FileOut, LIST l){
    l.pTail->data.setID(l.SoPhanTu());
    FileOut<<endl;
    FileOut<<setw(lenid)<<left<<l.pTail->data.getID();
    FileOut<<setw(lenname)<<left<<l.pTail->data.getName();
    FileOut<<setw(lenaddress)<<left<<l.pTail->data.getAddress();
    FileOut<<setw(lenemail)<<left<<l.pTail->data.getEmail();
    FileOut<<setw(lenphone)<<left<<l.pTail->data.getPhone();
    FileOut<<setw(lenrate)<<left<<"   "+to_string(l.pTail->data.getRate())+"*";
    FileOut<<setw(lenbill)<<left<<TachDonVi(l.pTail->data.getBill());
    FileOut<<l.pTail->data.getService();
}
void XuatDSInFoRaFile(ofstream &FileOut, LIST l){
    XuatCacTruong(FileOut);
    int id=0;
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        k->data.setID(++id);
        FileOut<<endl;
        FileOut<<setw(lenid)<<left<<k->data.getID();
        FileOut<<setw(lenname)<<left<<k->data.getName();
        FileOut<<setw(lenaddress)<<left<<k->data.getAddress();
        FileOut<<setw(lenemail)<<left<<k->data.getEmail();
        FileOut<<setw(lenphone)<<left<<k->data.getPhone();
        FileOut<<setw(lenrate)<<"   "+to_string(k->data.getRate())+"*";
        FileOut<<setw(lenbill)<<left<<TachDonVi(k->data.getBill());
        FileOut<<k->data.getService();
    }
}