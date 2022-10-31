#include <bits/stdc++.h>
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
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
    FileOut<<endl;
    FileOut<<setw(4)<<left<<SoPhanTu(l);
    FileOut<<setw(30)<<left<<k->data.getName();
    FileOut<<setw(30)<<left<<k->data.getAddress();
    FileOut<<setw(30)<<left<<k->data.getEmail();
    FileOut<<setw(14)<<left<<k->data.getPhone();
    FileOut<<setw(60)<<left<<k->data.getService();
    FileOut<<k->data.getBill()<<" VND";
    }
}
//-------------TIM KIEM THONG TIN KHACH HANG----------------
bool CompareString(string a, string b){
    bool check = false;
    for(int i=0; i<a.length(); i++){
        if(b[0] == a[i]){
            check = true;
            for(int j=1;j<b.length();j++){
                if(b[j] != a[i+j]){
                    check = false;
                    break;
                }
            }
            continue;
        }
        else continue;
    }
    return check;
}

void SearchName(LIST l, string name){
    LIST tmp;
    KhoiTaoList(tmp);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(CompareString(k->data.getName(), name)){
            NODE *them = KhoiTaoNode(k->data);
            ThemCuoi(tmp, them);
        }
    }
    if(IsEmpty(tmp)){
        cout<<"\n\t\tKhong co tim kiem phu hop!\n\t\t";
        system("pause");
        return;
    }
    else{
        cout<<"\n\t\tTim kiem thanh cong";
        cout<<"\n\t\t1. In ra man hinh";
        cout<<"\n\t\t2. In ra FILE\n\t\t";
        cout<<"Nhap lua chon: ";
        int choice1 = -1;
        cin>>choice1;
        if(choice1 == 1){
            XuatDS(tmp);
            system("pause");
        }
        else if(choice1 == 2){
            ofstream FileOut;
            FileOut.open("0.txt", ios::out);
            XuatDSInFoRaFile(FileOut, tmp);
        }

    }
}



//--------------XOA THONG TIN CUA KHACH HANG RA KHOI DANH SACH--------------------------



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
        cout<<"\n\t\t3. Tim kiem va Xuat thong tin Khach hang";
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
            FileOut.open("data.txt", ios::app);
            Customer x;
            NhapThongtin(x);
            NODE *p = KhoiTaoNode(x);
            ThemCuoi(l, p);
            AddInfoRaFile(FileOut, l);
            FileOut.close();
        }
        else if(choice == 3){
            ClearList(l);
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            int choice1;
            while(1){
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
                if(choice1<0 || choice1>6){
                    cout<<"\t\tBan da nhap sai cu phap!!!";
                    cout<<"\n\t\t";
                    system("pause");
                    continue;
                }
                else if(choice1 == 1){
                    string name;
                    cout<<"\t\tNhap ten can tim kiem: ";
                    cin.ignore();
                    getline(cin, name);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    ThemCustomerVaoList(FileIn, l);
                    SearchName(l, name);
                }
                else{
                    cout<<"\t\tNhan ENTER de thoat: ";
                    cout<<"\n\t\t";
                    system("pause");
                    break; 
                }

            }
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