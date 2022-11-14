#include "Object.h"
#include "ReadData.h"
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