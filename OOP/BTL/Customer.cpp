#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef unsigned long long ll;

//-------------Khai bao clss Customer--------------
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

//--------------Khai bao NODE-----------
struct Node{
    Customer data;
    struct Node *pNext;
}typedef NODE;

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

//--------------Khai bao LIST--------------
struct List{
    NODE *pHead;
    NODE *pTail;
}typedef LIST;

void KhoiTaoList(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
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
// Ham xoa NODE dau tien
void XoaDau(LIST &l){
    // Neu Danh sach dang rong tra ve list
    if(l.pHead == NULL){
        return;
    }
    NODE *p = l.pHead;     // Gan 1 node p cho node dau
    l.pHead = l.pHead->pNext; // Gan node dau = node sau
    delete p; // Xoa node p la node dau tien di => node sai chinh la node dau tien

}

int SoPhanTu(LIST l){
    int dem = 0;
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        dem++;
    }
    return dem;
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
    cout<<"\t\tNhap ten: ";
    getline(cin, name);
    x.setName(name);
    cout<<"\t\tNhap dia chi: ";
    getline(cin, address);
    x.setAddress(address);
    cout<<"\t\tNhap email: ";
    getline(cin, email);
    x.setEmail(email);
    cout<<"\t\tNhap so dien thoai: ";
    getline(cin, phone);
    x.setPhone(phone);
    cout<<"\t\tNhap ten cac dich vu da su dung: ";
    getline(cin, service);
    x.setService(service);
    cout<<"\t\tNhap tong so tien hoa don: ";
    cin>>bill;
    x.setBill(bill);
}

void XuatCacTruong(ofstream &FileOut){
    FileOut<<setw(4)<<left<<"ID";
    FileOut<<setw(30)<<left<<"NAME";
    FileOut<<setw(30)<<left<<"ADDRESS";
    FileOut<<setw(30)<<left<<"EMAIL";
    FileOut<<setw(14)<<left<<"PHONE";
    FileOut<<setw(60)<<left<<"SERVICE";
    FileOut<<setw(20)<<left<<"BILL"<<" ";
}

//Ham them thong tin 1 Khach hang ra FILE
void AddInfoRaFile(ofstream &FileOut, LIST l){
    FileOut<<endl;
    FileOut<<setw(4)<<left<<SoPhanTu(l);
    FileOut<<setw(30)<<left<<l.pTail->data.getName();
    FileOut<<setw(30)<<left<<l.pTail->data.getAddress();
    FileOut<<setw(30)<<left<<l.pTail->data.getEmail();
    FileOut<<setw(14)<<left<<l.pTail->data.getPhone();
    FileOut<<setw(60)<<left<<l.pTail->data.getService();
    FileOut<<l.pTail->data.getBill()<<" VND";
}
// Ham them DS thong tin khach hang ra FILE
void XuatDSInFoRaFile(ofstream &FileOut, LIST l){
    XuatCacTruong(FileOut);
    int id=0;
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
//--------------XOA THONG TIN CUA KHACH HANG RA KHOI DANH SACH--------------------------

// Xoa Info, Chi can tim Dia chi, email,... la ta co the truy cao vao ten cua Khach hang, nen chi can tim den Truong cot NAME de tim roi xoa
void XoaInfo(LIST &l, NODE *q){
    // Neu DS rong, tra ve list
    if(l.pHead == NULL){
        return;
    }
    // Neu DS co nhieu hon 1 phan tu va node q nam o vi tri dau tien
    while(strcmp(l.pHead->data.getName().c_str(), q->data.getName().c_str())==0 && l.pHead->pNext != NULL){ // Phong truong hop phan tu tiep theo se thanh pHead lai chinh bang node q
            XoaDau(l); 
    }
    // Neu DS chi co dung 1 phan tu, phan tu do chinh la node q
    if(strcmp(l.pHead->data.getName().c_str(), q->data.getName().c_str())==0 && l.pHead->pNext == NULL){
        XoaDau(l);
        return;
    }

    NODE *g = new NODE; // Khai bao 1 node de tro lien ket toi cac node truoc q
    NODE *k = l.pHead;
    while(k != NULL){
        bool check = false; // Khai bao bien check kiem tra xem tim duoc node q de xoa khong
        NODE *tmp = k; // Khai bao node tmp tro den node k, de sau khi tim duoc node q, ta tro node k den node 
                       // node sau truoc khi xoa node k(tmp), bai toan se khong bi loi
        if(strcmp(k->data.getName().c_str(), q->data.getName().c_str())==0 && k->pNext == NULL){ // Neu phan tu node q can xoa o vi tri cuoi cung
            g->pNext = k->pNext;
            l.pTail = g;
            delete k;
            return;
        }
        if(strcmp(k->data.getName().c_str(), q->data.getName().c_str())==0){
            g->pNext = k->pNext;
            check = true;
        }
        if(check == true){
            k = k->pNext;
            delete tmp;
            continue; // Dung continue de tranh truong hop sau khi delete node tmp(k) roi se nhan gia tri rac va 
                      // node g se van tro den node truoc khi bi xoa chu khong phai tro den node rac da xoa nua
        }
        g = k;
        k = k->pNext;
    }
}

//-------------SUA THONG TIN KHACH HANG---------------
void SuaName(LIST &l, NODE *q, string name){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getName().c_str(), q->data.getName().c_str())==0){
            k->data.setName(name);
            q->data.setName(name);
        }
    }
}

void SuaAddress(LIST &l, NODE *q, string address){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getAddress().c_str(), q->data.getAddress().c_str())==0){
            k->data.setAddress(address);
            q->data.setAddress(address);
        }
    }
}

void SuaEmail(LIST &l, NODE *q, string email){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0){
            k->data.setEmail(email);
            q->data.setEmail(email);
        }
    }
}

void SuaPhone(LIST &l, NODE *q, string phone){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getPhone().c_str(), q->data.getPhone().c_str())==0){
            k->data.setPhone(phone);
            q->data.setPhone(phone);
        }
    }
}

void SuaService(LIST &l, NODE *q, string service){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(strcmp(k->data.getService().c_str(), q->data.getService().c_str())==0){
            k->data.setService(service);
            q->data.setService(service);
        }
    }
}

void SuaBill(LIST &l, NODE *q, ll bill){
    for(NODE *k=l.pHead; k != NULL; k = k->pNext){
        if(k->data.getBill() == q->data.getBill()){
            k->data.setBill(bill);
            q->data.setBill(bill);
        }
    }
}

void SuaInfo(LIST &l, LIST &tmp){
    char choice2;
    while(1){
        system("cls");
        cout<<"\t\t\t1. Sua ten Khach hang";
        cout<<"\n\t\t\t2. Sua dia chi cua Khach hang";
        cout<<"\n\t\t\t3. Sua email cua Khach hang";
        cout<<"\n\t\t\t4. Sua so dien thoai cua Khach hang";
        cout<<"\n\t\t\t5. Sua dich vu da su dung cua Khach hang";
        cout<<"\n\t\t\t6. Sua so tien hoa don dich vu da su dung cua Khach hang";
        cout<<"\n\t\t\t0. Thoat tinh nang";
        cout<<"\n\t\t\tMoi ban nhap lua chon de sua: ";
        cin>>choice2;
        ofstream FileOut;
        FileOut.open("data.txt", ios::out);
        if(choice2 == '1'){
            string name;
            cout<<"\t\t\tNhap ten thay the: ";
            cin.ignore();
            getline(cin, name);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaName(l, q, name);
                q = q->pNext;
            }
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua ten thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";
            char choice3;
            cin>>choice3;
            if(choice3 == '1'){
                continue;
            }
            else{   
                break;
            }
        }
        else if(choice2 == '2'){
            string address;
            cout<<"\t\t\tNhap dia chi thay the: ";
            cin.ignore();
            getline(cin, address);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaAddress(l, q, address);
                q = q->pNext;
            }
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua dia chi thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            char choice3;
            cin>>choice3;
            if(choice3 == '1'){
                continue;
            }
            else{
                break;
            }
        }
        else if(choice2 == '3'){
            string email;
            cout<<"\t\t\tNhap email thay the: ";
            cin.ignore();
            getline(cin, email);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaEmail(l, q, email);
                q = q->pNext;
            }
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua email thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            char choice3;
            cin>>choice3;
            if(choice3 == '1'){
                continue;
            }
            else{
                break;
            }                 
        }
        else if(choice2 == '4'){
            string phone;
            cout<<"\t\t\tNhap so dien thoai thay the: ";
            cin.ignore();
            getline(cin, phone);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaPhone(l, q, phone);
                q = q->pNext;
            }
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua so dien thoai thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            char choice3;
            cin>>choice3;
            if(choice3 == '1'){
                continue;
            }
            else{
                break;
            }
        }
        else if(choice2 == '5'){
            string service;
            cout<<"\t\t\tNhap ten dich vu thay the: ";
            cin.ignore();
            getline(cin, service);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaService(l, q, service);
                q = q->pNext;
            }
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua ten dich vu thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            char choice3;
            cin>>choice3;
            if(choice3 == '1'){
                continue;
            }
            else{
                break;
            }
        }
        else if(choice2 == '6'){
            ll bill;
            cout<<"\t\t\tNhap so tien hoa don thay the: ";
            cin>>bill;
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaBill(l, q, bill);
                q = q->pNext;
            }
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\t\tSua so tien trong hoa don thanh cong\n\t\t\tBan co muon tiep tuc sua!";
            cout<<"\n\t\t\t1. Co";
            cout<<"\n\t\t\t0. Khong va thoat";
            cout<<"\n\t\t\tNhap lua chon: ";                        
            char choice3;
            cin>>choice3;
            if(choice3 == '1'){
                continue;
            }
            else{ 
                break;
            }
        }
        else if(choice2 == '0'){
            cout<<"\t\t\t";
            system("pause");
            FileOut.close();
            return;
        }
        else{
            cout<<"\t\t\tBan da nhap sai cu phap\n\t\t\t";
            system("pause");
        }
    }
}

//--------------THAO TAC QUAN LY THONG TIN KHACH HANG--------------

void ManageCustomer(LIST &l, LIST &tmp){
    while(1){
        system("cls");
        cout<<"\n\t\t1. In thong tin Khach hang ra man hinh";
        cout<<"\n\t\t2. In thong tin Khach hang ra FILE";
        cout<<"\n\t\t3. Xoa thong tin Khach hang trong FILE";
        cout<<"\n\t\t4. Sua thong tin Khach hang trong FILE";
        cout<<"\n\t\t0. Thoat chuong trinh";
        cout<<"\n\t\tNhap lua chon: ";
        char choice1;
        cin>>choice1;
        if(choice1 == '0'){
            cout<<"\t\t";
            system("pause");
            return;
        }
        else if(choice1 == '1'){
            XuatDS(tmp);
            system("pause");
        }
        else if(choice1 == '2'){
            ofstream FileOut;
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, tmp);
            cout<<"\t\tIn FILE thanh cong\n\t\t";
            system("pause");
            FileOut.close();
        }
        else if(choice1 == '3'){
            ofstream FileOut;
            FileOut.open("data.txt", ios::out);
            NODE *q = tmp.pHead;
            while(q != NULL){
                XoaInfo(l, q);
                q = q->pNext;
            }
            XuatDSInFoRaFile(FileOut, l);
            cout<<"\t\tDa xoa thong tin Khach hang";
            system("pause");
            FileOut.close();
        }
        else if(choice1 == '4'){
            SuaInfo(l, tmp);
        }
        else{
            cout<<"\t\tBan da nhap sai cu phap\n\t\t";
            system("pause");
        }
    }    
}

//-------------TIM KIEM THONG TIN KHACH HANG----------------
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

void SearchName(ifstream &FileIn, LIST l, string name){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp;
    KhoiTaoList(tmp);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getName(), name)){
            NODE *them = KhoiTaoNode(k->data);
            ThemCuoi(tmp, them);
        }
    }
    if(IsEmpty(tmp)){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        Sleep(1000);
        ManageCustomer(l, tmp);
    }
}

void SearchAddress(ifstream &FileIn, LIST l, string address){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp;
    KhoiTaoList(tmp);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getAddress(), address)){
            NODE *them = KhoiTaoNode(k->data);
            ThemCuoi(tmp, them);
        }
    }
    if(IsEmpty(tmp)){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        Sleep(1000);
        ManageCustomer(l, tmp);
    }

}

void SearchEmail(ifstream &FileIn, LIST l, string email){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp;
    KhoiTaoList(tmp);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getEmail(), email)){
            NODE *them = KhoiTaoNode(k->data);
            ThemCuoi(tmp, them);
        }
    }
    if(IsEmpty(tmp)){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        Sleep(1000);
        ManageCustomer(l, tmp);
    }

}

void SearchPhone(ifstream &FileIn, LIST l, string phone){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp;
    KhoiTaoList(tmp);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getPhone(), phone)){
            NODE *them = KhoiTaoNode(k->data);
            ThemCuoi(tmp, them);
        }
    }
    if(IsEmpty(tmp)){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        Sleep(1000);
        ManageCustomer(l, tmp);
    }
}

void SearchService(ifstream &FileIn, LIST l, string service){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp;
    KhoiTaoList(tmp);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareStringParentWithChild(k->data.getService(), service)){
            NODE *them = KhoiTaoNode(k->data);
            ThemCuoi(tmp, them);
        }
    }
    if(IsEmpty(tmp)){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        Sleep(1000);
        ManageCustomer(l, tmp);
    }
}

void SearchBill(ifstream &FileIn, LIST l, ll bill){
    ThemCustomerVaoList(FileIn, l);
    LIST tmp;
    KhoiTaoList(tmp);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data.getBill()==bill){
            NODE *them = KhoiTaoNode(k->data);
            ThemCuoi(tmp, them);
        }
    }
    if(IsEmpty(tmp)){
        cout<<"\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\t\tTim kiem thanh cong";
        Sleep(1000);
        ManageCustomer(l, tmp);
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
    char choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t------------MENU------------";
        cout<<"\n\t\tMOI BAN NHAP TUY CHON";
        cout<<"\n\t\t1. Xuat Danh Sach Khach hang tu FILE ra man hinh";
        cout<<"\n\t\t2. Them Thong tin Khach hang vao FILE";
        cout<<"\n\t\t3. Tim kiem Thong tin Khach hang tu FILE va Chinh sua";
        cout<<"\n\t\t0. Thoat Menu va Xoa bo nho danh sach";
        cout<<"\n\t\t----------------------------";

        cout<<"\n\t\tNhap lua chon: ";
        cin>>choice;
        if(choice == '0'){
            cout<<"\t\tNhan ENTER de thoat: ";
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        if(choice == '1'){
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
        else if(choice == '2'){
            ClearList(l);
            cin.ignore();
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            string xuongdong;
            getline(FileIn, xuongdong);
            ThemCustomerVaoList(FileIn, l);
            FileIn.close();
            ofstream FileOut;
            FileOut.open("data.txt", ios::app);
            Customer x;
            NhapThongtin(x);
            NODE *p = KhoiTaoNode(x);
            ThemCuoi(l, p);
            AddInfoRaFile(FileOut, l);
            FileOut.close();
        }
        else if(choice == '3'){
            while(1){
                ClearList(l);
                ifstream FileIn;
                FileIn.open("data.txt", ios::in);
                char choice1;
                system("cls");
                cout<<"\n\t\t1. Tim kiem theo ten";
                cout<<"\n\t\t2. Tim kiem theo dia chi";
                cout<<"\n\t\t3. Tim kiem theo email";
                cout<<"\n\t\t4. Tim kiem theo so dien thoai";
                cout<<"\n\t\t5. Tim kiem theo dich vu da su dung";
                cout<<"\n\t\t6. Tim kiem theo hoa don";
                cout<<"\n\t\t0. Thoat tim kiem";
                cout<<"\n\t\tNhap lua chon: ";

                cin>>choice1;
                if(choice1 == '0'){
                    cout<<"\t\tNhan ENTER de thoat: ";
                    cout<<"\n\t\t";
                    system("pause");
                    FileIn.close();
                    break; 
                }
                else if(choice1 == '1'){
                    string name;
                    cout<<"\t\tNhap ten can tim kiem: ";
                    cin.ignore();
                    getline(cin, name);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchName(FileIn, l, name);
                }
                else if(choice1 == '2'){
                    string address;
                    cout<<"\t\tNhap dia chi can tim kiem: ";
                    cin.ignore();
                    getline(cin, address);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchAddress(FileIn, l, address);                 
                }
                else if(choice1 == '3'){
                    string email;
                    cout<<"\t\tNhap email can tim kiem: ";
                    cin.ignore();
                    getline(cin, email);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchEmail(FileIn, l, email);                 
                }
                else if(choice1 == '4'){
                    string phone;
                    cout<<"\t\tNhap so dien thoai can tim kiem: ";
                    cin.ignore();
                    getline(cin, phone);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchPhone(FileIn, l, phone);                 
                }
                else if(choice1 == '5'){
                    string service;
                    cout<<"\t\tNhap ten dich vu can tim kiem: ";
                    cin.ignore();
                    getline(cin, service);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchService(FileIn, l, service);                 
                }
                else if(choice1 == '6'){
                    ll bill;
                    cout<<"\t\tNhap so tien hoa don can tim: ";
                    cin>>bill;
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchBill(FileIn, l, bill);                 
                }
                else{
                    cout<<"\t\tBan da nhap sai cu phap!!!";
                    cout<<"\n\t\t";
                    system("pause");
                }
            }
        }
        else{
            cout<<"\t\tBan da nhap sai cu phap!!!";
            cout<<"\n\t\t";
            system("pause");

        }
    }

}


int main(){
    LIST l;
    KhoiTaoList(l);
    MENU(l);
}