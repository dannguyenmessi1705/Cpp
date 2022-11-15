#include <bits/stdc++.h>
#include <windows.h>
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

//===========DOI MA MAU TEXT============
void TextColor(int x){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

//=============KIEM TRA DANG NHAP HE THONG=============

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


//============TIM DO DAI CAC TRUONG=====================
void TimDoDai(int &lenid, int &lenname, int &lenaddress, int &lenemail, int &lenphone, int &lenrate, int &lenbill){
    ifstream FileIn; 
    FileIn.open("data.txt", ios::in);
    string line;
    getline(FileIn, line);
    if(line.length() == 0){ // File data rong
        lenid = 6;
        lenname = 30;
        lenaddress = 22;
        lenemail = 30;
        lenphone = 17;
        lenrate = 14;
        lenbill = 27;
    }
    else{
        lenid = 2; // Bang chieu dai "ID"
        for(int i=2;i<=line.length();i++) { // Bat dau tu sau tu "ID" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenid++;
        }
        lenname = 4; // Bang do dai "NAME"
        for(int i=lenid+lenname;i<=line.length();i++) { // Bat dau tu sau tu "NAME" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenname++;
        }
        lenaddress = 7; // Bang do dai "ADDRESS"
        for(int i=lenid + lenname + lenaddress;i<=line.length();i++) { // Bat dau tu sau tu "ADDRESS" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenaddress++;
        }
        lenemail = 5; // Bang do dai "EMAIL"
        for(int i=lenid + lenname + lenemail + lenaddress;i<=line.length();i++) { // Bat dau tu sau tu "EMAIL" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenemail++;
        }
        lenphone = 5; // Bang do dai "PHONE"
        for(int i=lenid + lenname + lenemail + lenphone + lenaddress;i<=line.length();i++) { // Bat dau tu sau tu "PHONE" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenphone++;
        }
        lenrate = 8; // Bang do dai "FEEDBACK"
        for(int i=lenid + lenname + lenemail + lenphone + lenaddress + lenrate;i<=line.length();i++) { // Bat dau tu sau tu "RATE" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenrate++;
        }
        lenbill = 4; // Bang do dai "BILL"
        for(int i=lenid + lenname + lenemail + lenphone + lenaddress + lenrate + lenbill;i<=line.length();i++) { // Bat dau tu sau tu "BILL" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenbill++;
        }
    }
    FileIn.close();
}
int lenid, lenname, lenaddress, lenemail, lenphone, lenbill, lenrate;


//------------XUAT THONG TIN RA MAN HINH==================
ll Pow(int a, int b){
    ll kq = 1;
    for(int i=1; i<=b; i++){
        kq *= a;
    }
    return kq;
}
// Lam dau cham phan cach hang nghin trong hoa don
string TachDonVi(ll bill){
	string tmp = "";
	string num = to_string(bill);
	int count = 0;
	for (int i = num.length() - 1; i >= 0; i--) {
		count++;
		tmp.push_back(num[i]);
		if (count == 3) {
			tmp.push_back('.');
			count = 0;
		}
	}
	reverse(tmp.begin(), tmp.end());
	if (tmp.size() % 4 == 0) {
		tmp.erase(tmp.begin());
	}
	return tmp + " VND";
}
string TachDonVi(string money){
    string tmp = "";
	int count = 0; // dem do dai string de ngan cach
    int dem = 0; // dung de dem so cham ".", phong truong hop khi len den hang ty thi khong can cham nua
	for (int i = money.length() - 1; i >= 0; i--) {
		count++;
		tmp.push_back(money[i]);
		if (count == 3 && dem < 3) {
			tmp.push_back('.');
			count = 0;
            dem++;
		}
	}
	reverse(tmp.begin(), tmp.end());
	if (tmp.size() % 4 == 0) {
		tmp.erase(tmp.begin());
	}
	return tmp + " VND";
}
// Chuyen string sang kieu so nguyen
void DocInfoTuFile(ifstream &FileIn, Customer &x){
    string name, address, email, phone, service, tmp, sbill, srate;
    int rate = 0, id = 0;
    ll bill = 0;
    FileIn>>id;
    getline(FileIn, tmp); // Doc 1 dong trong FILE, sau khi doc xong, con tro tri vi nam o dau dong ke tiep
    int cat = 0;
    for(int i=0;i<tmp.length();i++){
        if(tmp[i] != ' ') break; // Bo qua dau khoang cach
        cat++;
    }
    tmp = tmp.substr(cat);
// CACH THU 1 LAY THONG TIN
    name = tmp.substr(0, lenname);
    for(int i=name.length()-1;i>=0;i--){
        if(name[i] != ' ') break;
        else name.erase(name.end()-1);
    }
    tmp = tmp.substr(lenname);
    address = tmp.substr(0, lenaddress);
    for(int i=address.length()-1;i>=0;i--){
        if(address[i] != ' ') break;
        else address.erase(address.end()-1);
    }
    tmp = tmp.substr(lenaddress);
    email = tmp.substr(0, lenemail);
    for(int i=email.length()-1;i>=0;i--){
        if(email[i] != ' ') break;
        else email.erase(email.end()-1);
    }
    tmp = tmp.substr(lenemail);
    phone = tmp.substr(0, lenphone);
    for(int i=phone.length()-1;i>=0;i--){
        if(phone[i] != ' ') break;
        else phone.erase(phone.end()-1);
    }
    tmp = tmp.substr(lenphone);
    srate = tmp.substr(0, lenrate);
    for(int i=srate.length()-1;i>=0;i--){
        if(srate[i]>='0' && srate[i]<='9'){
            rate = srate[i]-'0';
            break;
        }
        else srate.erase(srate.end()-1);
    }
    tmp = tmp.substr(lenrate);
    sbill = tmp.substr(0, lenbill);
    for(int i=sbill.length()-1;i>=0;i--){
        if(sbill[i] != ' ') break;
        else sbill.erase(sbill.end()-1);
    }
    bill = 0;
    int mu = 0;
    for(int i=sbill.length()-1; i >= 0; i--){ // Chuyen string sang so
        if(tmp[i] >= '0' && tmp[i] <= '9')
            bill += (tmp[i] - '0') * Pow(10, mu++);
    }
    tmp = tmp.substr(lenbill);
    for(int i=tmp.length()-1;i>=0;i--){
        if(email[i] != ' ') break;
        else tmp.erase(tmp.end()-1);
    }
    service = tmp;
// CACH THU 2 LAY THONG TIN
    // int checkname = 0, checkaddress = 0, checkemail = 0, checkphone = 0, checkservice = 0, checkbill = 0, checkrate = 0;
    // Check cac thong tin trong cac truong, den khi gap 2 dau khoang cach thi doc het thong tin trong 1 truong nao do
    // for(int i=0; i<tmp.length();i++){
    //     if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkname == 0){ 
    //         name = tmp.substr(0, i+1); // cat string lay thong tin trong truong NAME
    //         // x.setName(name);
    //         checkname = 1; // Bien kiem tra xem thong tin da duoc lay hay chua
    //         while(tmp[++i]==' '); // Dem so khoang cach phia sau truong NAME
    //         tmp.erase(tmp.begin(), tmp.begin()+i); // Xoa tu dau den cuoi khoang cach trong truong NAME de bat dau tiep tuc doc thong tin trong truong ke tiep  
    //         i = -1; 
    //         continue;
    //     }
    //     // Tuong tu voi cac truong sau
    //     if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkaddress == 0){
    //         address = tmp.substr(0, i+1);
    //         // x.setAddress(address);
    //         checkaddress = 1;
    //         while(tmp[++i]==' ');
    //         tmp.erase(tmp.begin(), tmp.begin()+i);
    //         i = -1;
    //         continue;        
    //     }  
    //     if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkemail == 0){
    //         email = tmp.substr(0, i+1);
    //         // x.setEmail(email);
    //         checkemail = 1;
    //         while(tmp[++i]==' ');
    //         tmp.erase(tmp.begin(), tmp.begin()+i);
    //         i = -1;
    //         continue;        
    //     }
    //     if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkphone == 0){
    //         phone = tmp.substr(0, i+1);
    //         // x.setPhone(phone);
    //         checkphone = 1;
    //         while(tmp[++i]==' ');
    //         tmp.erase(tmp.begin(), tmp.begin()+i);
    //         i = -1;
    //         continue;        
    //     }
    //     if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkrate == 0){
    //         srate = tmp.substr(0, i+1);
    //         rate = srate[0] - '0'; // Lay phan so, bo dau "*" o sau
    //         // x.setRate(rate);
    //         checkrate = 1;
    //         while(tmp[++i]==' ');
    //         tmp.erase(tmp.begin(), tmp.begin()+i);
    //         i = -1;
    //         continue;        
    //     }
    //     if(tmp[i]!=' ' && tmp[i+1]==' ' && tmp[i+2]==' ' && checkbill == 0){
    //         sbill = tmp.substr(0, i+1);
    //         bill = 0;
    //         int mu = 0;
    //         for(int i=sbill.length()-1; i >= 0; i--){ // Chuyen string sang so
    //             if(tmp[i] >= '0' && tmp[i] <= '9')
    //                 bill += (tmp[i] - '0') * Pow(10, mu++);
    //         }
    //         // x.setBill(bill);
    //         checkbill = 1;
    //         while(tmp[++i]==' ');
    //         tmp.erase(tmp.begin(), tmp.begin()+i);
    //         i = -1;
    //         continue;        
    //     }
        
    // }
    // // Lay string service
    // cat = 0;
    // for(int i=0; i<tmp.length(); i++){
    //     if(tmp[i] != ' ') break;
    //     cat++;
    // }
    // service = tmp.substr(cat, tmp.length()-cat);
    // // x.setService(service);
    x = Customer(id, name, address, email, phone, rate, bill, service); // Goi constructor cua class Customer
}

void ThemCustomerVaoList(ifstream &FileIn, LIST &l){
    while(! FileIn.eof()){ // Doc file cho toi khi den cuoi dong
        Customer x;
        DocInfoTuFile(FileIn, x);
        NODE *p = new NODE(x); // Khoi tao 1 node moi co data la Customer
        l.ThemCuoi(p); // Them node vua khoi tao vao cuoi danh sach
    }
}

void Customer::XuatInfo(){
    cout<<"\nID: "<<this->getID();
    cout<<"\nNAME: "<<this->getName();
    cout<<"\nADDRESS: "<<this->getAddress();
    cout<<"\nEMAIL: "<<this->getEmail();
    cout<<"\nPHONE: "<<this->getPhone();
    cout<<"\nFEEDBACK: "<<this->getRate()<<"*";
    cout<<"\nBILL: "<<TachDonVi(this->getBill());
    cout<<"\nSERVICE: "<<this->getService();
}


void LIST::XuatDS(){
    for(NODE *k = this->pHead; k != NULL; k = k->pNext){
        k->data.XuatInfo(); // Goi phuong thuc cua Customer (k->data = Customer)
        cout<<endl;
    }
}

//-------------THEM THONG TIN KHACH HANG--------------------
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
void Customer::NhapThongtin(){
    ll bill;
    string name, address, email, phone, service;
    int rate;
    cout<<"\t\tNhap ten(25 ky tu): ";
    do{
        getline(cin, name);
        if(name.length() > 25 || name.length() == 0) cout<<"\t\tTen qua dai hoac khong hop le, vui long nhap lai(25 ky tu): ";
    } while(name.length() > 25 || name.length() == 0);
    this->setName(name);
    cout<<"\t\tNhap dia chi(18 ky tu): ";
    do{
        getline(cin, address);
        if(address.length() > 18 || address.length() == 0) cout<<"\t\tDia chi qua dai hoac khong hop le, vui long nhap lai(18 ky tu): ";
    } while(address.length() > 18 || address.length() == 0);
    this->setAddress(address);
    cout<<"\t\tNhap email(30 ky tu): ";
    do{
        getline(cin, email);
        if(email.length() > 30 || email.length() == 0) cout<<"\t\tEmail qua dai hoac khong hop le, vui long nhap lai(30 ky tu): ";
    } while(email.length() > 30 || email.length() == 0);
    this->setEmail(email);
    cout<<"\t\tNhap so dien thoai(12 so): ";
    do{
        getline(cin, phone);
        if(phone.length() > 12 || phone.length() == 0) cout<<"\t\tSo dien thoai khong hop le, vui long nhap lai(12 so): ";
    } while(phone.length() > 12 || phone.length() == 0);
    this->setPhone(phone);
    do{
        cout<<"\t\tNhap ten cac dich vu da su dung: ";
        getline(cin, service);
        if(service.length() == 0) cout<<"\n";
    } while(service.length() == 0);
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

//Ham them thong tin 1 Khach hang ra FILE
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
// Ham them DS thong tin khach hang ra FILE
void XuatDSInFoRaFile(ofstream &FileOut, LIST l, int update){
    XuatCacTruong(FileOut);
    int id=0;
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(update == 1) // Chi cap nhat lai ID sau khi xoa, nguoc lai thi khong can cap nhat vi so luong khach hang khong bi mat di
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
//--------------XOA THONG TIN CUA KHACH HANG RA KHOI DANH SACH--------------------------

// Xoa Info, Chi can tim Dia chi, email,... la ta co the truy cao vao ten cua Khach hang, nen chi can tim den Truong cot EMAAIL de tim roi xoa, vi EMAIL la dinh danh duy nhat, cho co 1 doi voi moi khach hang
void XoaInfo(LIST &l, NODE *q){
    // Neu DS rong, tra ve list
    if(l.IsEmpty()){
        return;
    }
    // Neu DS co nhieu hon 1 phan tu va node q nam o vi tri dau tien
    while(strcmp(l.pHead->data.getEmail().c_str(), q->data.getEmail().c_str())==0 && l.pHead->pNext != NULL){ // Phong truong hop phan tu tiep theo se thanh pHead lai chinh bang node q
            l.XoaDau(); 
    }
    // Neu DS chi co dung 1 phan tu, phan tu do chinh la node q
    if(strcmp(l.pHead->data.getEmail().c_str(), q->data.getEmail().c_str())==0 && l.pHead->pNext == NULL){
        l.XoaDau();
        return;
    }

    NODE *g = new NODE(); // Khai bao 1 node de tro lien ket toi cac node truoc q
    NODE *k = l.pHead;
    while(k != NULL){
        bool check = false; // Khai bao bien check kiem tra xem tim duoc node q de xoa khong
        NODE *tmp = k; // Khai bao node tmp tro den node k, de sau khi tim duoc node q, ta tro node k den node 
                       // node sau truoc khi xoa node k(tmp), bai toan se khong bi loi
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0 && k->pNext == NULL){ // Neu phan tu node q can xoa o vi tri cuoi cung
            g->pNext = k->pNext;
            l.pTail = g;
            delete k;
            return;
        }
        if(strcmp(k->data.getEmail().c_str(), q->data.getEmail().c_str())==0){
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
            cout<<"\t\t\tNhap ten thay the(25 ky tu): ";
            cin.ignore();
            do{
                getline(cin, name);
            if(name.length() > 25 || name.length() == 0) cout<<"\t\t\tTen qua dai hoac khong hop le, vui long nhap lai(25 ky tu): ";
            } while(name.length() >  25 || name.length() == 0);
            NODE *q = tmp.pHead; // Cho node q tro toi dau LIST de check tim cac phan tu khac trong danh sach co trung thong tin de sua hay khong
            while(q != NULL){
                SuaName(l, q, name);
                q->data.setName(name); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l, 0);
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
            cout<<"\t\t\tNhap dia chi thay the(18 ky tu): ";
            cin.ignore();
            do{
                getline(cin, address);
                if(address.length() > 18 || address.length() == 0) cout<<"\t\t\tDia chi qua dai hoac khong hop le, vui long nhap lai(18 ky tu): ";
            } while(address.length() >  18 || address.length() == 0);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaAddress(l, q, address);
                q->data.setAddress(address);  // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l, 0);
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
            cout<<"\t\t\tNhap email thay the(30 ky tu): ";
            cin.ignore();
            do{
                getline(cin, email);
                if(email.length() > 30 || email.length() == 0) cout<<"\t\t\tEmail qua dai hoac khong hop le, vui long nhap lai(30 ky tu): ";
            } while(email.length() >  30 || email.length() == 0);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaEmail(l, q, email);
                q->data.setEmail(email);  // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l, 0);
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
            cout<<"\t\t\tNhap so dien thoai thay the(12 so): ";
            cin.ignore();
            do{
                getline(cin, phone);
                if(phone.length() > 12 || phone.length() == 0) cout<<"\t\t\tSo dien thoai khong hop le, vui long nhap lai(12 so): ";
            } while(phone.length() >  12 || phone.length() == 0);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaPhone(l, q, phone);
                q->data.setPhone(phone); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l, 0);
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
            do{
                getline(cin, service);
                if(service.length() == 0) cout<<"\t\t\tNhap ten dich vu thay the: ";
            } while(service.length() == 0);
            NODE *q = tmp.pHead;
            while(q != NULL){
                SuaService(l, q, service);
                q->data.setService(service); // Cap nhat lai thong tin da sua
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l, 0);
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
            XuatDSInFoRaFile(FileOut, l, 0);
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
            XuatDSInFoRaFile(FileOut, l, 0);
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
//--------------THAO TAC QUAN LY THONG TIN KHACH HANG--------------
void ManageCustomer(LIST &l, LIST &tmp){
    while(1){
        system("cls");
        cout<<"\n\t\t=================TUY CHON===================";
        cout<<"\n\t\t|  1. In thong tin Khach hang ra man hinh  |";
        cout<<"\n\t\t|  2. In thong tin Khach hang ra FILE      |";
        cout<<"\n\t\t|  3. Xoa thong tin Khach hang trong FILE  |";
        cout<<"\n\t\t|  4. Sua thong tin Khach hang trong FILE  |";
        cout<<"\n\t\t|  0. Thoat chuong trinh                   |";
        cout<<"\n\t\t============================================";
        cout<<"\n\t\tNhap lua chon: ";
        string choice1;
        cin>>choice1;
        if(choice1 == "0"){
            ofstream FileOut;
            FileOut.open("data.txt", ios::in);
            XuatDSInFoRaFile(FileOut, l, 0); // Xuat, backup lai danh sach phong truong hop nguoi dung an phim tuy chon so 2 se lam mat danh sach
            FileOut.close();
            return;
        }
        else if(choice1 == "1"){
            tmp.XuatDS();
            system("pause");
        }
        else if(choice1 == "2"){
            ofstream FileOut;
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, tmp, 0);
            FileOut.close();
            cout<<"\t\tIn FILE thanh cong\n\t\t";
            system("pause");
        }
        else if(choice1 == "3"){
            ofstream FileOut;
            NODE *q = tmp.pHead;
            while(q != NULL){
                XoaInfo(l, q);
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l, 1); // Xoa xong cap nhat lai ID => update = 1
            FileOut.close();
            cout<<"\t\tDa xoa thong tin Khach hang\n\t\t";
            system("pause");
            return;
        }
        else if(choice1 == "4"){
            SuaInfo(l, tmp);
        }
        else{
            cout<<"\t\tBan da nhap sai cu phap\n\t\t";
            system("pause");
        }
    }
}

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

//---------------SAP XEP THONG TIN KHACH HANG--------------------

//---------------SAP XEP THONG TIN KHACH HANG--------------------

void Swap(Customer &a, Customer &b){
    Customer tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int Lay_gia_tri_de_CatTen(string a){
    int cat = 0;
    int len = a.length();
    for(int i=len-1; i>=0; i--){
        if(a.at(i) == ' ') break;
        else cat++;
    }
    return cat;
}

bool SapxepString_tangdan(string a, string b){
    int lena = a.length();
    int lenb = b.length();
    int min = (lena <= lenb)?lena:lenb;
    for(int i = 0; i < min; i++){
        if((a[i] - '0') < (b[i] - '0'))
            return true;
        else if((a[i]-'0') > (b[i]-'0'))
            return false;
        else continue;
    }
    return true;
}

bool SapxepString_giamdan(string a, string b){
    int lena = a.length();
    int lenb = b.length();
    int min = (lena <= lenb)?lena:lenb;
    for(int i = 0; i < min; i++){
        if((a[i] - '0') < (b[i] - '0'))
            return false;
        else if((a[i]-'0') > (b[i]-'0'))
            return true;
        else continue;
    }
    return false;
}

int Lay_gia_tri_de_CatHo(string a){
    int cat = 0;
    int len = a.length();
    for(int i=len-1; i>=0; i--){
        if(a.at(i) == ' ') break;
        else cat++;
    }
    return len-cat;
}

void SortName_A_to_Z(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            int lenK = 0, lenG = 0;
            string TenK, TenG, HoK, HoG;
            int DoDaiTenK = Lay_gia_tri_de_CatTen(k->data.getName());
            lenK = k->data.getName().length();
            TenK = k->data.getName().substr(lenK - DoDaiTenK, DoDaiTenK);
            HoK = k->data.getName().substr(0, lenK - DoDaiTenK);
            int DoDaiTenG = Lay_gia_tri_de_CatTen(g->data.getName());
            lenG = g->data.getName().length();
            TenG = g->data.getName().substr(lenG - DoDaiTenG, DoDaiTenG);
            HoG = k->data.getName().substr(0, lenG - DoDaiTenG);
            if(strcmp(TenK.c_str(), TenG.c_str()) == 0){
                if(SapxepString_tangdan(HoK, HoG) == false){
                    Swap(k->data, g->data);
                }
            }
            else if(SapxepString_tangdan(TenK, TenG) == false){
                Swap(k->data, g->data);
            }
            else continue;
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();
}

void SortName_Z_to_A(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            int lenK = 0, lenG = 0;
            string TenK, TenG, HoK, HoG;
            int DoDaiTenK = Lay_gia_tri_de_CatTen(k->data.getName());
            lenK = k->data.getName().length();
            TenK = k->data.getName().substr(lenK - DoDaiTenK, DoDaiTenK);
            HoK = k->data.getName().substr(0, lenK - DoDaiTenK);
            int DoDaiTenG = Lay_gia_tri_de_CatTen(g->data.getName());
            lenG = g->data.getName().length();
            TenG = g->data.getName().substr(lenG - DoDaiTenG, DoDaiTenG);
            HoG = k->data.getName().substr(0, lenG - DoDaiTenG);
            // Sap xep theo ten truoc roi trung nhau moi xet den ho
            if(strcmp(TenK.c_str(), TenG.c_str()) == 0){
                if(SapxepString_giamdan(HoK, HoG) == false){
                    Swap(k->data, g->data);
                }
            }
            else if(SapxepString_giamdan(TenK, TenG) == false){
                Swap(k->data, g->data);
            }
            else continue;
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();
}

void SortAddress_A_to_Z(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(SapxepString_tangdan(k->data.getAddress(), g->data.getAddress()) == false)
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortAddress_Z_to_A(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(SapxepString_giamdan(k->data.getAddress(), g->data.getAddress()) == false)
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortBill_0_to_9(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getBill() > g->data.getBill())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortBill_9_to_0(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getBill() < g->data.getBill())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}
void SortRate_0_to_9(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getRate() > g->data.getRate())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortRate_9_to_0(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getRate() < g->data.getRate())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

//============THONG KE==============
// Ham tinh tong so lon
void swap(string &n1, string &n2){
    string tmp = n1;
    n1 = n2;
    n2 = tmp;
}
string SUM(string n1, string n2){
    if(n1.length()<n2.length()){
        swap(n1, n2);
    }
    string tmp(n1.size()+1, 0); // Khai bao chuoi ket qua co do dai max, gia tri 0
    int l1=n1.length();
    int l2=n2.length();
    int dis=l1-l2; // n1 dài hơn n2 bao số
    int sum=0;
    int nho=0; // lưu biến nhớ
    int k=tmp.size();; // lưu biến độ dài trong SUM
    for(int i = l2-1;i>=0;i--){
        sum = (n1[i+dis]-'0')+(n2[i]-'0')+nho;
        int donvi = sum%10; // tìm giá trị đơn vị
        nho = sum/10;
        tmp[--k] = donvi;
    }
    for(int i = dis-1;i>=0;i--){
        sum=(n1[i]-'0') + nho;
        int donvi = sum%10;
        nho = sum/10;
        tmp[--k] = donvi;
    }
    if(nho>0){
        tmp[--k] = nho;
    }
    for(int i=0;i<tmp.size();i++){
        tmp[i]+='0';
    }
    if(tmp[0]=='0'){
        return tmp.substr(1); //Cat chuoi neu ky tu dau bang 0
    }
    return tmp;
}
// Ham thong ke tong so tien cua tat ca khach hang
string TotalBill(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    string sum = "0";
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        sum = SUM(sum, to_string(k->data.getBill()));
    }
    FileIn.close();
    return sum;
}
// Ham thong ke tong so khach hang
ll TotalCustomer(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    FileIn.close();
    return l.SoPhanTu();
}
// Ham thong ke so luot danh gia
void TotalRate(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    ll rate0 = 0, rate1 = 0, rate2 =0, rate3 = 0, rate4 = 0, rate5 = 0;
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data.getRate() == 0) rate0++;
        else if(k->data.getRate() == 1) rate1++;
        else if(k->data.getRate() == 2) rate2++;
        else if(k->data.getRate() == 3) rate3++;
        else if(k->data.getRate() == 4) rate4++;
        else rate5++;
    }
    cout<<"\t\tCo tong "<<l.SoPhanTu()<<" luot danh gia";
    cout<<"\n\t\tSo luot danh gia 0*: "<<rate0<<" danh gia";
    cout<<"\n\t\tSo luot danh gia 1*: "<<rate1<<" danh gia";
    cout<<"\n\t\tSo luot danh gia 2*: "<<rate2<<" danh gia";
    cout<<"\n\t\tSo luot danh gia 3*: "<<rate3<<" danh gia";
    cout<<"\n\t\tSo luot danh gia 4*: "<<rate4<<" danh gia";
    cout<<"\n\t\tSo luot danh gia 5*: "<<rate5<<" danh gia\n\t\t";
}

//===============MENU==================
void MENU(LIST l){
    string choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t===========================MENU=============================";
        cout<<"\n\t\t|                MOI BAN NHAP TUY CHON                     |";
        cout<<"\n\t\t| 1. Xuat Danh Sach Khach hang tu FILE ra man hinh         |";
        cout<<"\n\t\t| 2. Them Thong tin Khach hang vao FILE                    |";
        cout<<"\n\t\t| 3. Tim kiem Thong tin Khach hang tu FILE va Chinh sua    |";
        cout<<"\n\t\t| 4. Sap xep lai thong tin Khach hang                      |";
        cout<<"\n\t\t| 5. Thong ke cac chi so trong danh sach                   |";
        cout<<"\n\t\t| 0. Thoat Menu va Xoa bo nho danh sach                    |";
        cout<<"\n\t\t============================================================";

        cout<<"\n\t\tNhap lua chon: ";
        cin>>choice;
        if(choice == "0"){
            cout<<"\t\tNhan ENTER de thoat: ";
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        if(choice == "1"){
            l.ClearList(); 
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            string xuongdong;
            getline(FileIn, xuongdong); // doc hang ten cac truong, xong xuong dong bat dau doc thong tin khach hang 
            ThemCustomerVaoList(FileIn, l);
            if(l.IsEmpty()){
                cout<<"\t\tDanh sach dang rong!\n\t\t";
                system("pause");
                continue;
            }
            else{
                l.XuatDS();
                system("pause");
                FileIn.close();
            }
        }
        else if(choice == "2"){
            l.ClearList();
            cin.ignore();
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            string xuongdong;
            getline(FileIn, xuongdong); // Bo qua truong ten
            ThemCustomerVaoList(FileIn, l);
            FileIn.close();
            ofstream FileOut;
            FileOut.open("data.txt", ios::app);
            // Kiem tra file rong hay khong, neu rong thi them hang ten cac truong vao
            if(xuongdong.length() == 0){
                XuatCacTruong(FileOut);
            }
            Customer x;
            int check = 0;
            do{
                if(check != 0){
                    cout<<"\t\tVui long nhap lai!\n";
                    cin.ignore();
                }
                x.NhapThongtin();
                check++; 
                }while(! KiemTraDauVao(l, x));
            NODE *p = new NODE(x);
            l.ThemCuoi(p);
            AddInfoRaFile(FileOut, l);
            cout<<"\t\tThem thong tin Khach hang thanh cong";
            FileOut.close();
            Sleep(1000);
        }
        else if(choice == "3"){
            while(1){
                l.ClearList();
                ifstream FileIn;
                FileIn.open("data.txt", ios::in);
                string choice1;
                system("cls");
                cout<<"\n\t\t===================TIM KIEM=======================";
                cout<<"\n\t\t|  1. Tim kiem theo ID                           |";
                cout<<"\n\t\t|  2. Tim kiem theo ten                          |";
                cout<<"\n\t\t|  3. Tim kiem theo dia chi                      |";
                cout<<"\n\t\t|  4. Tim kiem theo email                        |";
                cout<<"\n\t\t|  5. Tim kiem theo so dien thoai                |";
                cout<<"\n\t\t|  6. Tim kiem theo dich vu da su dung           |";
                cout<<"\n\t\t|  7. Tim kiem theo hoa don                      |";
                cout<<"\n\t\t|  8. Tim kiem theo chat luong danh gia dich vu  |";
                cout<<"\n\t\t|  0. Thoat tim kiem                             |";
                cout<<"\n\t\t==================================================";
                cout<<"\n\t\tNhap lua chon: ";

                cin>>choice1;
                if(choice1 == "0"){
                    FileIn.close();
                    break; 
                }
                else if(choice1 == "1"){
                    int id;
                    cout<<"\t\tNhap ID can tim kiem: ";
                    cin>>id;
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchID(FileIn, l, id);
                }
                else if(choice1 == "2"){
                    string name;
                    cout<<"\t\tNhap ten can tim kiem: ";
                    cin.ignore();
                    getline(cin, name);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchName(FileIn, l, name);
                }
                else if(choice1 == "3"){
                    string address;
                    cout<<"\t\tNhap dia chi can tim kiem: ";
                    cin.ignore();
                    getline(cin, address);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchAddress(FileIn, l, address);                 
                }
                else if(choice1 == "4"){
                    string email;
                    cout<<"\t\tNhap email can tim kiem: ";
                    cin.ignore();
                    getline(cin, email);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchEmail(FileIn, l, email);                 
                }
                else if(choice1 == "5"){
                    string phone;
                    cout<<"\t\tNhap so dien thoai can tim kiem: ";
                    cin.ignore();
                    getline(cin, phone);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchPhone(FileIn, l, phone);                 
                }
                else if(choice1 == "6"){
                    string service;
                    cout<<"\t\tNhap ten dich vu can tim kiem: ";
                    cin.ignore();
                    getline(cin, service);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchService(FileIn, l, service);                 
                }
                else if(choice1 == "7"){
                    ll bill;
                    cout<<"\t\tNhap so tien hoa don can tim: ";
                    cin>>bill;
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchBill(FileIn, l, bill);                 
                }
                else if(choice1 == "8"){
                    int rate;
                    cout<<"\t\tNhap chat luong danh gia can tim (0-5): ";
                    cin>>rate;
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchRate(FileIn, l, rate);                 
                }
                else{
                    cout<<"\t\tBan da nhap sai cu phap!!!";
                    cout<<"\n\t\t";
                    system("pause");
                }
            }
        }
        else if(choice == "4"){
            while(1){
                l.ClearList();
                ifstream FileIn;
                FileIn.open("data.txt", ios::in);
                string choice1;
                
                system("cls");
                cout<<"\n\t\t====================SAP XEP========================";
                cout<<"\n\t\t|  1. Sap xep theo ten                            |";
                cout<<"\n\t\t|  2. Sap xep theo dia chi                        |";
                cout<<"\n\t\t|  3. Sap xep theo tong so tien hoa don           |";
                cout<<"\n\t\t|  4. Sap xep theo chat luong danh gia san pham   |";
                cout<<"\n\t\t|  0. Thoat tinh nang                             |";
                cout<<"\n\t\t===================================================";
                cout<<"\n\t\tNhap lua chon: ";
                cin>>choice1;
                if(choice1 == "0"){
                    FileIn.close();
                    break; 
                }
                else if(choice1 == "1"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortName_A_to_Z(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortName_Z_to_A(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }

                }
                else if(choice1 == "2"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortAddress_A_to_Z(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortAddress_Z_to_A(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }

                }
                else if(choice1 == "3"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortBill_0_to_9(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortBill_9_to_0(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }
                }
                else if(choice1 == "4"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortRate_0_to_9(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortRate_9_to_0(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }
                }
                else{
                    cout<<"\t\tBan da nhap sai cu phap!!!";
                    cout<<"\n\t\t";
                    system("pause");
                }

            }
        }
        else if(choice == "5"){
            while(1){
                l.ClearList();
                ifstream FileIn;
                FileIn.open("data.txt", ios::in);
                string choice1;
                system("cls");
                cout<<"\n\t\t|========================THONG KE=======================|";
                cout<<"\n\t\t|  1. Thong ke tong so khach hang                       |";
                cout<<"\n\t\t|  2. Thong ke tong so tien cua tat ca cac khach hang   |";
                cout<<"\n\t\t|  3. Thong ke luot danh gia cua khach hang             |";
                cout<<"\n\t\t|  0. Thoat tinh nang                                   |";
                cout<<"\n\t\t|=======================================================|";
                cout<<"\n\t\tNhap lua chon: ";
                cin>>choice1;
                if(choice1 == "0"){
                    FileIn.close();
                    break; 
                }
                else if(choice1 == "1"){
                    cin.ignore();
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    cout<<"\t\tTong so khach hang: "<<TotalCustomer(FileIn, l)<<"\n\t\t";
                    system("pause");
                }
                else if(choice1 == "2"){
                    cin.ignore();
                    string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                    getline(FileIn, xuongdong);
                    cout<<"\t\tTong so tien trong danh sach da thong ke la: "<<TachDonVi(TotalBill(FileIn, l))<<"\n\t\t";
                    system("pause");
                }
                else if(choice1 == "3"){
                    cin.ignore();
                    string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                    getline(FileIn, xuongdong);
                    TotalRate(FileIn, l);
                    system("pause");
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
    Login();
    TimDoDai(lenid, lenname, lenaddress, lenemail, lenphone, lenrate, lenbill);
    LIST l = LIST();
    system("Color 70");
    MENU(l);
    l.ClearList();
    system("data.txt");
}