#ifndef _OBJECT_H
#define _OBJECT_H
#include "FormatType.h"
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//=============KHAI BAO CLASS CUSTOMER=============
class Customer{
private:
    string user = "admin";
    string password;
    string name;
    string address;
    string email;
    string phone;
    string service;
    ll bill;
    int rate;
    int id;
public:
    Customer(){}; // Constructor mac dinh cua class
    // Truyen thuoc tinh vao class Customer
    Customer(int id, string name, string address, string email, string phone, int rate, ll bill, string service){
        this->name = name;
        this->address = address;
        this->email = email;
        this->phone = phone;
        this->service = service;
        this->bill = bill;
        this->rate = rate;
        this->id = id;
    }
    bool CheckLogin(string us, string pass); // Phuong thuc dat pass, check tai khoan dang nhap he thong
    void setName(string name); // Phuong thuc dat ten KH 
    string getName(); // Phuong thuc goi ten KH
    void setAddress(string adddress); // Phuong thuc dat bien dia chi
    string getAddress(); // Phuong thuc tra ve bien dia chi
    void setEmail(string email); // Phuong thuc dat bien email
    string getEmail(); // Phuong thuc tra ve bien email
    void setPhone(string phone); // Phuong thuc dat bien so dien thoai
    string getPhone(); // Phuong thuc tra ve so dien thoai....
    void setService(string service);
    string getService();
    void setBill(ll bill);
    ll getBill();
    void setRate(int rate);
    int getRate();
    void setID(int id);
    int getID();
    void XuatInfo();    // Phuong thuc xuat thong tin Khach hang
    void NhapThongtin(); // Phuong thuc dung de nhap thong tin Khach hang
};
bool Customer::CheckLogin(string us, string pass){
    time_t t = time(0);   // lay thoi gian hien tai
    tm* now = localtime(&t); // Chuyen doi sang kieu int
    string h, min, day, mon, y;
    h = to_string(now->tm_hour);
    if(h.length()==1){
        h = "0"+h;
    }
    min = to_string(now->tm_min);
    if(min.length()==1){
        min= "0"+min;
    }
    day = to_string(now->tm_mday);
    if(day.length()==1){
        day="0"+day;
    }
    mon = to_string(now->tm_mon + 1);
    if(mon.length()==1){
        mon="0"+mon;
    }    
    y = to_string(now->tm_year + 1900);
    this->password = h+min+day+mon+y;
    if(strcmp(us.c_str(), user.c_str())==0 && strcmp(pass.c_str(), password.c_str())==0 ) // Neu nhap dung
        return true;
    else return false;
}
void Customer::setName(string name){
    this->name = name;
}
string Customer::getName(){
    return name;
}
void Customer::setAddress(string address){
    this->address = address;
}
string Customer::getAddress(){
    return address;
}
void Customer::setEmail(string email){
    this->email = email;
}
string Customer::getEmail(){
    return email;
}
void Customer::setPhone(string phone){
    this->phone = phone;
}
string Customer::getPhone(){
    return phone;
}
void Customer::setService(string service){
    this->service = service;
}
string Customer::getService(){
    return service;
}
void Customer::setBill(ll bill){
    this->bill = bill;
}
ll Customer::getBill(){
    return bill;
}
void Customer::setRate(int rate){
    this->rate = rate;
}
int Customer::getRate(){
    return rate;
}
void Customer::setID(int id){
    this->id = id;
}
int Customer::getID(){
    return id;
}
void Customer::XuatInfo(){
    cout<<setw(lenid)<<this->getID();
    cout<<setw(lenname)<<this->getName();
    cout<<setw(lenaddress)<<this->getAddress();
    cout<<setw(lenemail)<<this->getEmail();
    cout<<setw(lenphone)<<this->getPhone();
    cout<<setw(lenrate)<<"   "+to_string(this->getRate())+"*";
    cout<<setw(lenbill)<<TachDonVi(this->getBill());
    cout<<this->getService();
}
void Customer::NhapThongtin(){
    ll bill;
    string name, address, email, phone, service;
    int rate;
    cout<<"\t\tNhap ten(25 ky tu): ";
    do{
        getline(cin, name);
        if(name.length() > 25 ) cout<<"Ten qua dai, vui long nhap lai(25 ky tu): ";
    } while(name.length() > 25);
    this->setName(name);
    cout<<"\t\tNhap dia chi(18 ky tu): ";
    do{
        getline(cin, address);
        if(address.length() > 18 ) cout<<"Dia chi qua dai, vui long nhap lai(18 ky tu): ";
    } while(address.length() >  18);
    this->setAddress(address);
    cout<<"\t\tNhap email(30 ky tu): ";
    do{
        getline(cin, email);
        if(email.length() > 30 ) cout<<"Email qua dai, vui long nhap lai(30 ky tu): ";
    } while(email.length() > 30);
    this->setEmail(email);
    cout<<"\t\tNhap so dien thoai(12 so): ";
    do{
        getline(cin, phone);
        if(phone.length() > 12 ) cout<<"So dien thoai qua dai, vui long nhap lai(12 so): ";
    } while(phone.length() > 12);
    this->setPhone(phone);
    cout<<"\t\tNhap ten cac dich vu da su dung: ";
    getline(cin, service);
    this->setService(service);
    cout<<"\t\tNhap tong so tien hoa don: ";
    cin>>bill;
    this->setBill(bill);
    do{
        cout<<"\t\tVui long danh gia dich vu (0-5): ";
        cin>>rate;
        if(rate<0 || rate>5){
            cout<<"\t\tBan da nhap sai\n";
        }
    }while(rate<0 || rate>5);
    this->setRate(rate);
}
//============KHAI BAO CLASS NODE===========
// 1 Node bao gio cung gom 2 phan. 1 la du lieu chua trong node, 2 la con tro de xac dinh vi tri tro toi node tiep theo
// Khoi tao Node chua co lien ket bat ki voi node nao => con tro pNext = NULL
class NODE{
public:
    Customer data;
    NODE *pNext;
    NODE(){
        this->pNext = NULL;
    }
    NODE(Customer x){
        this->data = x;
        this->pNext = NULL;
    }
};

//===========KHAI BAO CLASS LIST============
// Duoc quan ly bang 2 node dau cuoi pHead, pTail, LIST moi khoi tao bao gio cung la LIST rong
class LIST{
public:
    NODE *pHead;
    NODE *pTail;
    LIST(){
        this->pHead = NULL;
        this->pTail = NULL;
    }
    bool IsEmpty(){ // Ham check Danh sach co rong hay khong
        if(this->pHead == NULL) return true;
        else return false;
    }
    void ThemCuoi(NODE *p){ // Ham them 1 node vao cuoi danh sach
        if(this->pHead == NULL){ // Neu list rong
            this->pHead = this->pTail = p;
        }
        else{
        this->pTail->pNext = p;
        this->pTail = p;
        }
    }
    // Ham xoa NODE dau tien
    void XoaDau(){
        // Neu Danh sach dang rong tra ve list
        if(this->pHead == NULL){
            return;
        }
        NODE *p = this->pHead;     // Gan 1 node p cho node dau
        this->pHead = this->pHead->pNext; // Gan node dau = node sau
        delete p; // Xoa node p la node dau tien di => node sai chinh la node dau tien

    }
    // Ham dem so phan tu node co trong LIST
    int SoPhanTu(){ 
        int dem = 0;
        for(NODE *k = this->pHead; k != NULL; k = k->pNext){
            dem++;
        }
        return dem;
    }
    // Ham giai phong bo nho cho LIST
    void ClearList(){
        NODE *k = new NODE();
        while (this->pHead != NULL){
        k = this->pHead; // Gan node k vao vi tri dau de xoa sau  khi cho pHead tro toi node tiep theo, khong phat sinh loi
        this->pHead = this->pHead->pNext;
        delete k; 
        }
    }
    // Ham xuat du lieu trong LIST 
    void XuatDS();

};
void LIST::XuatDS(){
    cout<<setw(lenid)<<left<<"ID";
    cout<<setw(lenname)<<left<<"NAME";
    cout<<setw(lenaddress)<<left<<"ADDRESS";
    cout<<setw(lenemail)<<left<<"EMAIL";
    cout<<setw(lenphone)<<left<<"PHONE";
    cout<<setw(lenrate)<<left<<"FEEDBACK";
    cout<<setw(lenbill)<<left<<"BILL";
    cout<<"SERVICE"<<endl;
    for(NODE *k = this->pHead; k != NULL; k = k->pNext){
        k->data.XuatInfo(); // Goi phuong thuc cua Customer (k->data = Customer)
        cout<<endl;
    }
}
#endif