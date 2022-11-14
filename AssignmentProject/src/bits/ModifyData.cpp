#include "Object.h"
#include "AddData.h"
//=================SUA THONG TIN KHACH HANG=========================
// Vi email dinh danh khach hang la duy nhat, khong trung lap
void SuaName(LIST &l, NODE *q, string name){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0){
            k->data.setName(name); // Cap nhat thong tin trong LIST
            // q->data.setName(name); // Cap nhat thong tin trong NODE de dong bo
        }
    }
}

void SuaAddress(LIST &l, NODE *q, string address){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0){
            k->data.setAddress(address);
            // q->data.setAddress(address);
        }
    }
}

void SuaEmail(LIST &l, NODE *q, string email){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0){
            k->data.setEmail(email);
            // q->data.setEmail(email);
        }
    }
}

void SuaPhone(LIST &l, NODE *q, string phone){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0){
            k->data.setPhone(phone);
            // q->data.setPhone(phone);
        }
    }
}

void SuaService(LIST &l, NODE *q, string service){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0){
            k->data.setService(service);
            // q->data.setService(service);
        }
    }
}

void SuaBill(LIST &l, NODE *q, ll bill){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(k->data.getEmail() == q->data.getEmail()){
            k->data.setBill(bill);
            // q->data.setBill(bill);
        }
    }
}

void SuaRate(LIST &l, NODE *q, int rate){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(k->data.getEmail() == q->data.getEmail()){
            k->data.setRate(rate);
            // q->data.setRate(rate);
        }
    }
}


void SuaInfo(LIST &l, LIST &tmp){
    string choice2;
    while(1){
        system("cls");
        cout<<"\t\t\t==========================CHINH SUA=============================";
        cout<<"\n\t\t\t|    1. Sua ten Khach hang                                     |";
        cout<<"\n\t\t\t|    2. Sua dia chi cua Khach hang                             |";
        cout<<"\n\t\t\t|    3. Sua email cua Khach hang                               |";
        cout<<"\n\t\t\t|    4. Sua so dien thoai cua Khach hang                       |";
        cout<<"\n\t\t\t|    5. Sua dich vu da su dung cua Khach hang                  |";
        cout<<"\n\t\t\t|    6. Sua so tien hoa don dich vu da su dung cua Khach hang  |";
        cout<<"\n\t\t\t|    7. Sua danh gia dich vu cua Khach hang                    |";
        cout<<"\n\t\t\t|    0. Thoat tinh nang                                        |";
        cout<<"\n\t\t\t================================================================";
        cout<<"\n\t\t\tMoi ban nhap lua chon de sua: ";
        cin>>choice2;
        ofstream FileOut;
        if(choice2 == "1"){
            string name;
            cout<<"\t\t\tNhap ten thay the: ";
            cin.ignore();
            getline(cin, name);
            NODE *q = tmp.pHead; // Cho node q tro toi dau LIST de check tim cac phan tu khac trong danh sach co trung thong tin de sua hay khong
            while(q != NULL){
                SuaName(l, q, name);
                q->data.setName(name); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua ten thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";
            string choice3;
            cin>>choice3;
            if(choice3 == "1"){
                continue;
            }
            else{   
                break;
            }
        }
        else if(choice2 == "2"){
            string address;
            cout<<"\t\t\tNhap dia chi thay the: ";
            cin.ignore();
            getline(cin, address);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaAddress(l, q, address);
                q->data.setAddress(address);  // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua dia chi thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            string choice3;
            cin>>choice3;
            if(choice3 == "1"){
                continue;
            }
            else{
                break;
            }
        }
        else if(choice2 == "3"){
            string email;
            cout<<"\t\t\tNhap email thay the: ";
            cin.ignore();
            getline(cin, email);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaEmail(l, q, email);
                q->data.setEmail(email);  // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua email thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            string choice3;
            cin>>choice3;
            if(choice3 == "1"){
                continue;
            }
            else{
                break;
            }                 
        }
        else if(choice2 == "4"){
            string phone;
            cout<<"\t\t\tNhap so dien thoai thay the: ";
            cin.ignore();
            getline(cin, phone);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaPhone(l, q, phone);
                q->data.setPhone(phone); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua so dien thoai thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            string choice3;
            cin>>choice3;
            if(choice3 == "1"){
                continue;
            }
            else{
                break;
            }
        }
        else if(choice2 == "5"){
            string service;
            cout<<"\t\t\tNhap ten dich vu thay the: ";
            cin.ignore();
            getline(cin, service);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaService(l, q, service);
                q->data.setService(service); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua ten dich vu thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            string choice3;
            cin>>choice3;
            if(choice3 == "1"){
                continue;
            }
            else{
                break;
            }
        }
        else if(choice2 == "6"){
            ll bill;
            cout<<"\t\t\tNhap so tien hoa don thay the: ";
            cin>>bill;
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaBill(l, q, bill);
                q->data.setBill(bill); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua so tien trong hoa don thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            string choice3;
            cin>>choice3;
            if(choice3 == "1"){
                continue;
            }
            else{ 
                break;
            }
        }
        else if(choice2 == "7"){
            int rate;
            do{
                cout<<"\t\t\tNhap lai danh gia thay the(0-5): ";
                cin>>rate;
                if(rate<0 || rate>5){
                    cout<<"\n\t\t\tBan da nhap sai, vui long nhap lai\n";
                }
            }while(rate<0 || rate>5);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaRate(l, q, rate);
                q->data.setRate(rate); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua danh gia dich vu thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            string choice3;
            cin>>choice3;
            if(choice3 == "1"){
                continue;
            }
            else{ 
                break;
            }
        }
        else if(choice2 == "0"){
            FileOut.close();
            return;
        }
        else{
            cout<<"\t\t\tBan da nhap sai cu phap\n\t\t\t";
            system("pause");
        }
    }
}
