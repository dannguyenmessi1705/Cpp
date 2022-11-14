#include "Object.h"
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
