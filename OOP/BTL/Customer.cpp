#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
class Customer{
private:
    string name;
    string address;
    string email;
    string phone;
    string service;
    ll bill;
public:
    Customer(){};
    Customer(string name, string address, string email, string phone, string service, ll bill){
        this->name = name;
        this->address = address;
        this->email = email;
        this->phone = phone;
        this->service = service;
        this->bill = bill;
    }
    void setName(string name);
    string getName();
    void setAddress(string adddress);
    string getAddress();
    void setEmail(string email);
    string getEmail();
    void setPhone(string phone);
    string getPhone();
    void setService(string service);
    string getService();
    void setBill(ll bill);
    ll getBill();

};
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

struct Node{
    Customer data;
    struct Node *pNext;
}typedef NODE;

struct List{
    NODE *pHead;
    NODE *pTail;
}typedef LIST;

void KhoiTaoList(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE *KhoiTaoNode(Customer x){
    NODE *p = new NODE;
    if(p == NULL){
        cout<<"Cap phat bo nho khong thanh cong";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

bool IsEmpty(LIST l){
    if(l.pHead == NULL) return true;
    else return false;
}

void ThemCuoi(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
    l.pTail->pNext = p;
    l.pTail = p;
    }
}


//------------XUAT THONG TIN RA MAN HINH==================
void DocInfoTuFile(ifstream &FileIn, Customer &x){
    string name, address, email, phone, service, tmp;
    int id = 0, checkname = 0, checkaddress = 0, checkemail = 0, checkphone = 0, checkservice = 0, checkbill = 0;
    FileIn>>id;
    getline(FileIn, tmp);
    int cat = 0;
    for(int i=0;i<tmp.length();i++){
        if(tmp[i] != ' ') break;
        cat++;
    }
    tmp = tmp.substr(cat);
    for(int i=0; i<tmp.length();i++){
        if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkname == 0){
            name = tmp.substr(0, i+1);
            x.setName(name);
            checkname = 1;
            while(tmp[++i]==' ');
            tmp.erase(tmp.begin(), tmp.begin()+i);
            i = -1;
            continue;
        }
        if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkaddress == 0){
            address = tmp.substr(0, i+1);
            x.setAddress(address);
            checkaddress = 1;
            while(tmp[++i]==' ');
            tmp.erase(tmp.begin(), tmp.begin()+i);
            i = -1;
            continue;        
        }
        if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkemail == 0){
            email = tmp.substr(0, i+1);
            x.setEmail(email);
            checkemail = 1;
            while(tmp[++i]==' ');
            tmp.erase(tmp.begin(), tmp.begin()+i);
            i = -1;
            continue;        
        }
        if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkphone == 0){
            phone = tmp.substr(0, i+1);
            x.setPhone(phone);
            checkphone = 1;
            while(tmp[++i]==' ');
            tmp.erase(tmp.begin(), tmp.begin()+i);
            i = -1;
            continue;        
        }        
        if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkservice == 0){
            service = tmp.substr(0, i+1);
            x.setService(service);
            checkservice = 1;
            while(tmp[++i]==' ');
            tmp.erase(tmp.begin(), tmp.begin()+i);
            i = -1;
            break;        
        }        
    }
    ll bill = stoull(tmp);
    x.setBill(bill);
}

void ThemCustomerVaoList(ifstream &FileIn, LIST &l){
    while(! FileIn.eof()){
        Customer x;
        DocInfoTuFile(FileIn, x);
        NODE *p = KhoiTaoNode(x);
        ThemCuoi(l, p);
    }
}

void XuatInfo(Customer x){
    cout<<"\nNAME: "<<x.getName();
    cout<<"\nADDRESS: "<<x.getAddress();
    cout<<"\nEMAIL: "<<x.getEmail();
    cout<<"\nPHONE: "<<x.getPhone();
    cout<<"\nSERVICE: "<<x.getService();
    cout<<"\nBILL: "<<x.getBill()<<" VND";
}


void XuatDS(LIST l){
    int id = 0;
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        cout<<"ID: "<<++id;
        XuatInfo(k->data);
        cout<<endl;
    }
}

//-------------THEM THONG TIN KHACH HANG--------------------
void NhapThongtin(Customer &x){
    ll bill;
    string name, address, email, phone, service;
    cout<<"Nhap ten: ";
    getline(cin, name);
    x.setName(name);
    cout<<"Nhap dia chi: ";
    getline(cin, address);
    x.setAddress(address);
    cout<<"Nhap email: ";
    getline(cin, email);
    x.setEmail(email);
    cout<<"Nhap so dien thoai: ";
    getline(cin, phone);
    x.setPhone(phone);
    cout<<"Nhap ten cac dich vu da su dung: ";
    getline(cin, service);
    x.setService(service);
    cout<<"Nhap tong so tien hoa don: ";
    cin>>bill;
    x.setBill(bill);
}

void XuatInfoRaFile(ofstream &FileOut, LIST &l){
    int id = 0;
    FileOut<<setw(4)<<left<<"ID";
    FileOut<<setw(30)<<left<<"NAME";
    FileOut<<setw(30)<<left<<"ADDRESS";
    FileOut<<setw(30)<<left<<"EMAIL";
    FileOut<<setw(14)<<left<<"PHONE";
    FileOut<<setw(60)<<left<<"SERVICE";
    FileOut<<setw(20)<<left<<"BILL"<<" ";
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        FileOut<<endl;
        FileOut<<setw(4)<<left<<++id;
        FileOut<<setw(30)<<left<<k->data.getName();
        FileOut<<setw(30)<<left<<k->data.getAddress();
        FileOut<<setw(30)<<left<<k->data.getEmail();
        FileOut<<setw(14)<<left<<k->data.getPhone();
        FileOut<<setw(60)<<left<<k->data.getService();
        FileOut<<k->data.getBill()<<" VND";
    }

}
//---------------CLEAR LIST--------------
void ClearList(LIST &l){
    NODE *k = new NODE;
    while (l.pHead != NULL){
        k = l.pHead;
        l.pHead = l.pHead->pNext;
        delete k;
    }
}
void MENU(LIST l){
    int choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t------------MENU------------";
        cout<<"\n\t\tMOI BAN NHAP TUY CHON";
        cout<<"\n\t\t1. Xuat Danh Sach Khach hang tu FILE ra man hinh";
        cout<<"\n\t\t2. Them Thong tin Khach hang vao FILE";
        cout<<"\n\t\t2. Sap Xep Danh Sach Sinh Vien theo thu tu diem Trung Binh tang dan vao FILE";
        cout<<"\n\t\t3. Tim kiem va Xuat thong tin Sinh Vien ra man hinh tu FILE & DS LIEN KET DON";
        cout<<"\n\t\t0. Thoat Menu va Xoa bo nho danh sach";
        cout<<"\n\t\t----------------------------";

        cout<<"\n\t\tNhap lua chon: ";
        cin>>choice;
        if(choice<0 || choice>3){
            cout<<"\t\tBan da nhap sai cu phap!!!";
            cout<<"\n\t\t";
            system("pause");
            continue;
        }
        if(choice == 1){
            ClearList(l);
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            string xuongdong;
            getline(FileIn, xuongdong);
            ThemCustomerVaoList(FileIn, l);
            if(IsEmpty(l)){
                cout<<"Danh sach dang rong!\n";
                system("pause");
                return;
            }
            else{
                XuatDS(l);
                system("pause");
                FileIn.close();
            }
        }
        else if(choice == 2){
            ClearList(l);
            cin.ignore();
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            string xuongdong;
            getline(FileIn, xuongdong);
            ThemCustomerVaoList(FileIn, l);
            ofstream FileOut;
            FileOut.open("data.txt", ios::out);
            Customer x;
            NhapThongtin(x);
            NODE *p = KhoiTaoNode(x);
            ThemCuoi(l, p);
            XuatInfoRaFile(FileOut, l);
            FileOut.close();

        }
        else{
            cout<<"\t\tNhan ENTER de thoat: ";
            cout<<"\n\t\t";
            system("pause");
            break;
        }
    }

}


int main(){
    LIST l;
    KhoiTaoList(l);
    MENU(l);
}