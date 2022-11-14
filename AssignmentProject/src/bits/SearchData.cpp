#include "Object.h"
#include "ReadData.h"
#include "ManagerData.h"
using namespace std;
//-------------TIM KIEM THONG TIN KHACH HANG----------------
// Ham kiem tra ky tu nhap vao co phai la chuoi con cua 1 chuoi cha lon hon hay khong
bool CompareStringParentWithChild(string a, string b){
    bool check = false;
    for(int i=0; i<a.length(); i++){
        if(b[0] == a[i]){
            check = true;
            int j;
            for(j=1;j<b.length();j++){
                if(b[j] != a[i+j]){
                    check = false;
                    break;
                }
            }
            if(j==b.length()) return check;
            else continue;
        }
        else continue;
    }
    return check;
}

void SearchID(ifstream &FileIn, LIST l, int id){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data.getID() == id){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }
}

void SearchName(ifstream &FileIn, LIST l, string name){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getName(), name)){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }
}

void SearchAddress(ifstream &FileIn, LIST l, string address){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getAddress(), address)){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }

}

void SearchEmail(ifstream &FileIn, LIST l, string email){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getEmail(), email)){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }

}

void SearchPhone(ifstream &FileIn, LIST l, string phone){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getPhone(), phone)){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }
}

void SearchService(ifstream &FileIn, LIST l, string service){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getService(), service)){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }
}

void SearchBill(ifstream &FileIn, LIST l, ll bill){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data.getBill()==bill){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }

}

void SearchRate(ifstream &FileIn, LIST l, int rate){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp = LIST();
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data.getRate()==rate){
            NODE *them = new NODE(k->data);
            tmp.ThemCuoi(them);
        }
    }
    if(tmp.IsEmpty()){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        cout<<"\n\t\tSo khach hang co thong tin tim kiem phu hop: "<<tmp.SoPhanTu();
        Sleep(2000);
        ManageCustomer(l, tmp);
    }

}