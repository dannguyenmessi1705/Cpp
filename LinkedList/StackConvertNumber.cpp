#include <iostream>
using namespace std;
// Khai bao cau truc Node
struct Node{
    int data;
    struct Node *pNext;
} typedef NODE;
// Khai bao cau truc Stack
struct Stack{
    NODE *pTop;
} typedef STACK;
// Khoi tao Stack
void KhoiTaoStack(STACK &s){
    s.pTop = NULL;
}
// Khoi tao Node
NODE *KhoiTaoNode(int x){
    NODE *p = new NODE();
    if(p == NULL) return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}
// Kiem tra Stack co rong khong
bool IsEmpty(STACK s){
    if(s.pTop == NULL) return true;
    else return false;
}
// Ham them vao dau 
bool Push(STACK &s, NODE *p){
    // Neu node p khong ton tai
    if(p == NULL) return false;
    // Neu Stack dang rong, Node dau chinh la p
    if(IsEmpty(s)){
        s.pTop = p;
    }
    else{
        p->pNext = s.pTop; // Tro node sau cua p den sTop
        s.pTop = p; // Cap nhat lai sTop chinh la p
    }
    return true;
}
// Ham Lay gia tri dau, dong thoi xoa gia tri do ra khoi Stack
bool Pop(STACK &s, int &value){
    // Neu Stack rong
    if(IsEmpty(s)) return false;
    value = s.pTop->data;
    NODE *tmp = s.pTop; // tao Node tam thoi gan bang sTop
    s.pTop = s.pTop->pNext; // Cho stop cho den node sau do
    delete tmp; // Xoa node tam thoi<=>s.pTop ban dau di
    return true;
}
// Ham chuyen doi co so
void Convert(STACK &s, int so_thap_phan, int co_so){
    while (so_thap_phan != 0){
        NODE *p = KhoiTaoNode(so_thap_phan%co_so);
        Push(s, p);
        so_thap_phan/=co_so;
    }
}
// Xuat tra kq
void XuatStack(STACK &s){
    while(!IsEmpty(s)){
        int value;
        Pop(s, value);
        if(value < 10) cout<<value;
        else if(value == 10) cout<<"A";
        else if(value == 11) cout<<"B";
        else if(value == 12) cout<<"C";
        else if(value == 13) cout<<"D";
        else if(value == 14) cout<<"E";
        else if(value == 15) cout<<"F";
    }
}
int main(){
    STACK s;
    KhoiTaoStack(s);
    int so_thap_phan, co_so;
    cout<<"Nhap so thap phan: ";
    cin>>so_thap_phan;
    cout<<"Nhap co so muon chuyen doi: ";
    cin>>co_so;
    Convert(s, so_thap_phan, co_so);
    cout<<"So "<<so_thap_phan<<" khi chuyen sang he co so "<<co_so<<" la: ";
    XuatStack(s);

}