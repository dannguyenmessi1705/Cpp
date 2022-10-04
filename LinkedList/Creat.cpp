#include <iostream>
using namespace std;
// Khai bao cau truc 1 node
struct node{
    int data; // Du lieu chua trong 1 node
    struct node *pNext; // Con tro dung de lien ket giua cac node voi nhau
};
typedef struct node NODE;
// Khai bao cau truc cua 1 danh sach lien ket don
struct list{ 
    NODE *pHead; // node quan ly dau danh sach
    NODE *pTail; // node quan ly cuoi danh sach
};
typedef struct list LIST;
// Khoi tao danh sach lien ket don
void KhoiTao(LIST &l){
    // Cho 2 node tro den NULL, vi danh sach chua co cac phan tu
    l.pHead=NULL;
    l.pTail=NULL;
}
// Khoi tao 1 node
NODE *KhoiTaoNode(int x){
    NODE *p = new NODE; // Cap phat vung nho cho node p
    if(p==NULL){
        cout<<"Khong du bo nho de cap phat";
        return NULL;
    }
    p->data = x; // truyen gia tri x vao data
    p->pNext = NULL; // Dau tien khai bao node thi node do chua lien ket den 1 node nao ca => con tro se tro den NULL
    return p;
}
// Ham them node vao dau danh sach lien ket
void ThemVaoDau(LIST &l, NODE *p){
    // danh sach dang rong
    if(l.pHead == NULL){
        l.pHead = l.pTail = p; // node dau cung chinh la node cuoi
    }
    else{
        p->pNext = l.pHead; // Cho con tro cua node can them la node p lien ket voi node dau => pHead
        l.pHead = p; // Cap nhap lai pHead chinh la node p
    }
}
// Ham them node vao cuoi danh sach lien ket don
void ThemVaoCuoi(LIST &l, NODE *p){
    // danh sach dang rong
    if(l.pHead == NULL){
        l.pHead = l.pTail = p; // node dau cung chinh la node cuoi
    }
    else{
        l.pTail->pNext = p; // Cho con tro cua pTail lien ket voi node p
        l.pTail = p; // Cap nhat lai node p chinh la pTail
    }
}
void XuatDS(LIST l){
    // for(int i=0;i<n;i++)
    for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
        cout<<k->data<<" ";
    }
}
// Ham tim max
int Max(LIST l){
    int max = l.pHead->data; // Cho phan tu dau cua node la max
    for(NODE *k=l.pHead->pNext; k!=NULL; k=k->pNext){ // Bat dau duyet tu node thu 2 de kiem tra
        if(max <= k->data) max=k->data;   
    }
    return max;
}
int main(){
    LIST l;
    KhoiTao(l); //Khoi tao danh sach lien ket don
    int n;
    cout<<"Nhap so luong node can them: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cout<<"Nhap gia tri nguyen: ";
        cin>>x;
        NODE *p = KhoiTaoNode(x); // Khoi tao 1 node so nguyen
        ThemVaoDau(l, p); // Them node p vao cuoi danh sach lien ket don
    }
    cout<<"Xuat danh sach lien ket don: ";
    XuatDS(l);
    cout<<"\nGia tri lon nhat trong danh sach la: "<<Max(l);

}
