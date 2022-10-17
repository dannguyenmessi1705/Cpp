#include <iostream>
using namespace std;
// STACK lam viec theo co che LIFO - Last In First Out

// Khai bao cau truc cua Node
struct Node{    
    int data; // Kieu du lieu chua trong Node
    struct Node *pNext; // Con tro cua Node
} typedef NODE;

// Khai bao cau truc cua Stack  
struct Stack{
    NODE *pTop; // node quan ly dau Ngan xep
} typedef STACK;

// Khoi tao STACK
void KhoiTaoNganXep(STACK &s){
    s.pTop = NULL; // Stack ban dau dang rong
}

// Khoi tao Node
NODE *KhoiTaoNode(int x){
    NODE *p = new NODE();
    // Neu khong cap duoc bo nho cho p
    if(p == NULL){
        cout<<"\t\tKhoi tao that bai";
        return NULL;
    }
    p->data = x; // Truyen gia tri cua x vao Node p
    p->pNext = NULL; // Cho con tro tro den Node tiep theo, vi chua co Node tiep theo nen pNext = NULL 
}

// HAM IsEmpty - Kiem Tra xem Stack co dang rong hay khong
bool IsEmpty(STACK s){
    // Neu Stack rong tra ve true
    if(s.pTop == NULL) return true;
    else return false;
}

// HAM PUSH - Them Node vao dau Stack - LIFO 
// Dung ham bool de kiem tra dieu kien(tranh sai sot) vua thuc hien lenh

bool Push(STACK &s, NODE *p){
    // Neu Node q khong ton tai, return false nguoi dung nhap lai
    if(p == NULL){
        return false;
    }
    // Neu Stack dang rong thi Node dau cung chinh la Node p
    if(IsEmpty(s)){
        s.pTop = p;
    }
    else{
        p->pNext = s.pTop; // Chen node p vao dau => Node pTop chinh la Node sau p => p-pNext se tro toi pTop
        s.pTop = p;
    }
    return true;
}

// HAM POP - Lay du lieu ra dong thoi Xoa luon Node trong Stack theo co che LIFO
// Dung ham bool de kiem tra dieu kien(tranh sai sot) vua thuc hien lenh
bool Pop(STACK &s, int &value){
    if(IsEmpty(s)){
        return false;
    }
    value = s.pTop->data; // Doc thong tin Node dau cua Stack
    NODE *tmp = s.pTop; // Khoi tao 1 Node tmp cho bang node s.sTop de lat delete di
    s.pTop = s.pTop->pNext; // Cho sTop tro den Node tiep theo 
    delete tmp;
    return true;
}

// HAM TOP - Doc gia tri o dau Stack, doc xong khong xoa
// Dung ham bool de kiem tra dieu kien(tranh sai sot) vua thuc hien lenh

bool Top(STACK s, int &value){
    if(IsEmpty(s)){
        return false;
    }
    value = s.pTop->data;
    return true;
}

// HAM XUAT STACK
void XuatXemDS(STACK s){
    if(!IsEmpty(s)){
        for(NODE *k = s.pTop; k != NULL; k = k->pNext){
            cout<<k->data<<" ";
        }
    }
    else cout<<"\t\tStack dang rong";
}

// HAM XOA STACK
void ClearStack(STACK &s){
    while(s.pTop != NULL){
        NODE *tmp = s.pTop;
        s.pTop = s.pTop->pNext;
        delete tmp;
    }
}

// HAM MENU
void Menu(STACK s){
    int choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t------------MENU------------";
        cout<<"\n\t\tMOI BAN NHAP TUY CHON";
        cout<<"\n\t\t1. Them Node vao STACK";
        cout<<"\n\t\t2. Xuat STACK ra man hinh";
        cout<<"\n\t\t3. Lay Phan tu dau tien cua STACK va xoa phan tu do";
        cout<<"\n\t\t4. Gia tri cua Phan tu dau tien";
        cout<<"\n\t\t0. Thoat Menu va Xoa bo nho danh sach";
        cout<<"\n\t\t----------------------------";

        cout<<"\n\t\tNhap lua chon: ";
        cin>>choice;
        if(choice<0 || choice>4){
            cout<<"\t\tBan da nhap sai cu phap!!!";
            cout<<"\n\t\t";
            system("pause");
            continue;
        }
        if(choice == 1){
            int x;
            cout<<"\t\tMoi ban nhap so nguyen: ";
            cin>>x;
            NODE *p = KhoiTaoNode(x);
            if(Push(s, p)==false){ // Vua thuc hien ham Push vua thuc hien kiem tra
                cout<<"\t\tGia tri dua vao khong hop le"; 
            }
        }
        else if(choice == 2){
            cout<<"\t\tDanh sach trong STACK: ";
            XuatXemDS(s);
            system("pause");
        }
        else if(choice == 3){
            int value;
            cout<<"\t\tPhan tu dau tien: ";
            if(Pop(s, value) == true) // Vua thuc hien ham Pop vua kiem tra bool
                cout<<value<<"\n\t\t";
            else cout<<"Khong co phan tu nao\n\t\t";
            system("pause");
        }
        else if(choice == 4){
            int value;
            cout<<"\t\tPhan tu dau tien: ";
            if(Top(s, value) == true) // Vua Thuc hien ham Top vua kiem tra bool
                cout<<value<<"\n\t\t";
            else cout<<"Khong co phan tu nao\n\t\t";
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
    STACK s;
    KhoiTaoNganXep(s);
    Menu(s);
    ClearStack(s);
    return 0;
}


