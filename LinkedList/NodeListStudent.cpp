// Eg; Nguyễn Di Đan, B20DCVT086, 17/05/2002, 9.0
//     Co the thay ham FileIn.ignore(1, '/');// ((1) bo qua 1 ky tu, '/' ky tu can bo qua la dau xuoc)
                         // Nhu vay se bo qua 1 dau xuoc "/"
// Bang Ham FileIn.seekg(1, ios_base::cur); // ((+1) bo qua 1 ky tu ve ben phai, ios_base::cur - bat dau tu vi tri hien tai)

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
ifstream FileIn;
ofstream FileOut;

// Khai bao struct NgayThangNamSinh

struct DateBirth{
    int ngay;
    int thang;
    int nam;
} typedef DATE;

// Khai bao Struct Sinhvien
struct Sinhvine{
    string HovaTen;
    string MaSV;
    DATE birhtday;
    float TB;
} typedef SV;

// Khai bao struct NODE
struct Node{
    SV data;
    struct Node *pNext;
} typedef NODE;

//Khai bao struct List
struct List{
    NODE *pHead;
    NODE *PTail;
} typedef LIST;

// Khai bao List
void KhoiTaoList(LIST &l){
    // Danh sach dang rong, chua gan con tro voi node khac
    // nen tro toi NULL
    l.pHead = NULL;
    l.PTail = NULL;
}

// Khai bao Node
NODE *KhoiTaoNode(SV x){
    NODE *p = new NODE;
    // Neu khong khoi tao duoc tra kq ra man hinh
    if(p == NULL){ 
        cout<<"Khoi tao that bai";
        return NULL;
    }
    p->data = x; // Truyen gia tri data vao node
    p->pNext = NULL; // Khoi tao Node ban dau chua can tro toi Node khac
    return p;
}

// Ham them Node Sinhvien vao cuoi
void ThemCuoi(LIST &l, NODE *p){
    // Neu ham rong thi node dau cung bang node cuoi
    if(l.pHead == NULL){
        l.pHead = l.PTail = p;
    }
    else{
        l.PTail->pNext = p;
        l.PTail = p;
    }
}

// -------DOc DANH SACH SINH VIEN VAO LINKLIST ROI XUAT RA MAN HINH------------//


// Ham doc Ngay sinh tu file
void DocNgaySInh(ifstream &FileIn, DATE &d){
    FileIn>>d.ngay; // Doc ngay sinh
    FileIn.ignore(1, '/'); // ((1) bo qua 1 ky tu, '/' ky tu can bo qua la dau xuoc)
                         // Nhu vay se bo qua 1 dau xuoc "/"
    FileIn>>d.thang; // Doc thang sinh
    FileIn.ignore(1, '/');// ((1) bo qua 1 ky tu, '/' ky tu can bo qua la dau xuoc)
                         // Nhu vay se bo qua 1 dau xuoc "/"
    FileIn>>d.nam; // Doc nam sinh
}

// Ham doc SV tu file
void DocFileSV(ifstream &FileIn, SV &Sinh_Vien){
    // Doc ho va ten
    getline(FileIn, Sinh_Vien.HovaTen, ','); // Doc ten den dau "," thi dung
    FileIn.ignore(1, ' '); // ((1) bo qua 1 ky tu, ' ' ky tu can bo qua la khoang trang)
                         // Nhu vay se bo qua 1 dau khoang trang " "
    // Doc MaSV
    getline(FileIn, Sinh_Vien.MaSV, ','); // Doc den dau "," thi dung
    FileIn.ignore(1, ' '); // ((1) bo qua 1 ky tu, ' ' ky tu can bo qua la khoang trang)
                         // Nhu vay se bo qua 1 dau khoang trang " "
    // Doc NgaySinh
    DocNgaySInh(FileIn, Sinh_Vien.birhtday); 
    FileIn.ignore(1, ',');// ((1) bo qua 1 ky tu, ',' ky tu can bo qua la dau phay)
                         // Nhu vay se bo qua 1 dau phay ","
    FileIn.ignore(1, ' '); // ((1) bo qua 1 ky tu, ' ' ky tu can bo qua la khoang trang)
                         // Nhu vay se bo qua 1 dau khoang trang " "
    // Doc Diem Trung Binh
    FileIn>>Sinh_Vien.TB;
        // Tu SV thu 2 tro di se co loi hien thi ten o duoi Ho ten nhu nay
    /*  Ho ten:
        Tran Duc Bo
        Ma Sinh vien: B21DCKT112
        Ngay sinh: 23/12/2003
        Diem Trung binh: 8.5 */
    // Muon khac phuc ta tao 1 bien tam doc cai ky tu "\n" o cuoi dong Do Doc SinhVien.TB bang kieu cin nen la khi ket thuc se co "\n"
    string tmp;
    getline(FileIn, tmp); // tmp = "\n";
}

// HAM XUAT THONG TIN SV
void XuatInFo(SV sv){
    cout<<"\nHo ten: "<<sv.HovaTen;
    cout<<"\nMa Sinh vien: "<<sv.MaSV;
    cout<<"\nNgay sinh: "<<sv.birhtday.ngay<<"/"<<sv.birhtday.thang<<"/"<<sv.birhtday.nam;
    cout<<"\nDiem Trung binh: "<<sv.TB;

}
// HAM THEM DANH SACH SINH VIEN VAO DANH SACH LIEN KET
void ThemSinhVienVaoList(ifstream &FileIn, LIST &l){
    // Doc den cuoi file thi dung
    while (! FileIn.eof()){
        SV Sinh_Vien;
        // Khoi tao gia tri Sinh_Vien
        DocFileSV(FileIn, Sinh_Vien);
        // Truyen fia tri SV vao node
        NODE *p = KhoiTaoNode(Sinh_Vien);
        // Them Node SV vao cuoi danh sach
        ThemCuoi(l, p);
    }
    
}

// Ham Xuat Danh sach lien ket don
void XuatDS(LIST l){
    int dem=0;
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        cout<<"\t\tSinh vien thu "<<++dem;
        XuatInFo(k->data);
        cout<<endl;
    }
}


// -------THEM DANH SACH SINH VIEN DA SAP XEP DIEM TRUNG BINH VAO FILE ListSinhVienDiemTB.txt------------//

// Ham Hoan Vi 2 SV
void swap(SV &sv1, SV &sv2){
    SV tmp;
    tmp = sv1;
    sv1 = sv2;
    sv2 = tmp;
}

// Ham Them 1 SV vao FILE ListSinhVienDiemTB.txt
void ThemVaoFile(ofstream &FileOut, SV Sinh_vien){
    FileOut<<Sinh_vien.HovaTen<<", ";
    FileOut<<Sinh_vien.MaSV<<", ";
    FileOut<<Sinh_vien.birhtday.ngay<<"/"<<Sinh_vien.birhtday.thang<<"/"<<Sinh_vien.birhtday.nam<<", ";
    FileOut<<Sinh_vien.TB;
}

// Ham Sap Xep node va Them Danh sach lien ket vao File

void ThemVaoFileTuDanhSachLienKet(ofstream &FileOut, LIST l){
    // Sap xep NODE theo diem TB tang dan
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        for(NODE *h = k->pNext; h != NULL; h = h->pNext){
            if(k->data.TB > h->data.TB){ 
                swap(k->data, h->data); // Hoan doi 2 struct SV (Luu y: Struct khong co con tro thi moi hoan vi duoc) 
            }
        }
    }
    // Sau khi da sap xep, them vao FILE
    FileOut.open("ListSinhVienDiemTB.txt", ios::out);
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        ThemVaoFile(FileOut, k->data); // ThemVaoFile(FILE, SV ..) data chinh la kieu du lieu SV
        FileOut<<endl;
    }
    FileOut.close();
}

// Xoa Bo Nho Danh Sach
void ClearList(LIST &l){
    NODE *k = new NODE;
    while (l.pHead != NULL){
        k = l.pHead;
        l.pHead = l.pHead->pNext;
        delete k;
    }
}

// -------TIM KIEM SINH VIEN CO TEN NHAP TU BAN PHIM------------//

//Ham cat Ten tu Xau ho ten
string CatXauHoTen(string HoTen){
    // "Nguyen Di Dan"
    int len = HoTen.length();
    int pos = 0;
    for(int i = len-1; i>=0; i--){
        if(HoTen[i] == ' ') break;
        pos++;
    }
    return HoTen.substr(len-pos); // cat ten tu vi tri len-pos den cuoi chuoi
}

// Ham tim kiem SV theo ten da nhap tu ban phim
void TimKiemSV(LIST l, string ten){
    bool check = false; // Bien kiem tra co thong tin sinh vien hay khong
    bool in_1_lan = false; // Bien de kiem tra khi co thong tin thi cout ra man hinh kq dung 1 lan duy nhat
    FileIn.open("ListSinhVien.txt", ios::in);
    // Them sinh vien vao list de tim
    ThemSinhVienVaoList(FileIn, l);
    // Tim kiem Sinh Vien
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        string tmp = CatXauHoTen(k->data.HovaTen);
        if(stricmp(tmp.c_str(), ten.c_str()) == 0){ // So sanh 2 chuoi khong phan biet ky tu hoa va thuong
            if(in_1_lan == false) cout<<"\n\t\tThong tin Sinh vien can tim la";
            XuatInFo(k->data);
            cout<<endl;
            check = true;
            in_1_lan = true;
        }
    }
    FileIn.close();
    if(check == false) cout<<"\t\tKhong co Sinh vien nao can tim\n";
}


// HAM MENU
void Menu(LIST l){
    int choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t------------MENU------------";
        cout<<"\n\t\tMOI BAN NHAP TUY CHON";
        cout<<"\n\t\t1. Xuat Danh Sach Sinh Vien tu FILE ra man hinh";
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
            FileIn.open("ListSinhVien.txt", ios::in);
            if(FileIn.fail()){
                cout<<"\t\tFile khong ton tai";
                system("pause");
                return;
            }
            ThemSinhVienVaoList(FileIn, l);
            XuatDS(l);
            system("pause");
            FileIn.close();
        }
        else if(choice == 2){
            ClearList(l);
            ThemVaoFileTuDanhSachLienKet(FileOut, l);
            cout<<"\t\tDa them vao FILE\n\t\t";
            system("pause");
        }
        else if(choice == 3){
            ClearList(l);
            string ten;
            cout<<"\t\tNhap ten Sinh vien: ";
            cin>>ten;
          
            TimKiemSV(l, ten);
            cout<<"\t\t";
            system("pause");
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
    Menu(l);
    ClearList(l);
}