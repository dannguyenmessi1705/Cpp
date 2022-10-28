#include <iostream>
using namespace std;
typedef struct phanso{
    float tu;
    float mau;
} PS;
typedef struct node{
    PS data;
    struct node *pNext;
} NODE;
NODE *KhoiTaoNode(PS x){
    NODE *p = new NODE();
    if(p == NULL){
        cout<<"Khong du bo nho";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
void Push(NODE *&pHead, NODE *p){
    if(pHead == NULL){
        pHead = p;
    }
    else{
        p->pNext = pHead;
        pHead = p;
    }
}
void Push_Back(NODE *&pHead, NODE *p){
    if(pHead == NULL){
        pHead = p;
    }
    else{
        for(NODE *k = pHead; ; k = k->pNext){
            if(k->pNext == NULL){
                k->pNext = p;
                break;
            }
        }
    }
}
void NhapPhanSo(PS &x){
    cin>>x.tu;
    cin.ignore(1, '/');
    cin>>x.mau;
}
void XuatPhanSo(PS x){
    cout<<x.tu<<"/"<<x.mau;
}
void XuatDS(NODE *pHead){
    for(NODE *k = pHead; k != NULL; k = k->pNext){
        cout<<"\t\t";
        XuatPhanSo(k->data);
        cout<<endl;
    }
}
void Delete(NODE *&pHead){
    NODE *k = new NODE();
    while(pHead != NULL){
        k = pHead;
        pHead = pHead->pNext;
        delete k;
    }
}
void Menu(NODE *pHead){
    int choice;
    while(1){
        system("cls");
        cout<<"---------------------MENU---------------------";
        cout<<"\n\t\t1. Them Phan So vao Dau Danh Sach";
        cout<<"\n\t\t2. Them Phan So vao Cuoi Danh Sach";
        cout<<"\n\t\t3. Xuat Danh Sach cac Phan So";
        cout<<"\n\t\t0. Thoat Menu";
        cout<<"\n----------------------------------------------";
        cout<<"\n\t\tMoi ban nhap lua chon: ";
        cin>>choice;

        if(choice<0 || choice>3){
            cout<<"\n\t\tBan da nhap sai cu phap, vui long nhap lai: ";
            cout<<"\n\t\t";
            system("pause");
        }

        if(choice == 1){   
            PS phanso;
            cout<<"\t\tMoi ban nhap phan so: ";
            NhapPhanSo(phanso);
            NODE *p = KhoiTaoNode(phanso);
            Push(pHead, p);
        }
        if(choice == 2){
            PS phanso;
            cout<<"\t\tMoi ban nhap phan so: ";
            NhapPhanSo(phanso);
            NODE *p = KhoiTaoNode(phanso);
            Push_Back(pHead, p);
        }
        else if(choice == 3){
            cout<<"\t\tDanh sach cac Phan So la: \n";
            XuatDS(pHead);
            cout<<"\t\t";
            system("pause");
        }
        else{
            cout<<"\n\t\tNhan ENTER de thoat";
            cout<<"\n\t\t";
            system("pause");
            break;
        }

    }
}
int main(){
    NODE *pHead = NULL;
    Menu(pHead);
    Delete(pHead);
    return 0;
}