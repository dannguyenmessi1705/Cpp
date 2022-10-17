// Tao Queue - Tao day so nguyen vao hang doi Vao Danh Sach lien ket theo co che FIFO(First In Fisrt Out)
// Them gia tri vao sau roi lay ra o dau;
#include <iostream>
using namespace std;
// Khai bao cau truc NODE
struct Node{
    int data;
    struct Node *pNext;
} typedef NODE;

// Khai bao cau truc hang doi Queue
struct Queue{
    NODE *pHead;
    NODE *pTail;
} typedef QUEUE;

// Khoi tao Hang doi Queue, can khoi tao hang doi rong
void KhoiTaoHangDoi(Queue &q){
    q.pHead = NULL; 
    q.pTail = NULL;
}

// Khoi tao Node dau
NODE *KhoiTaoNODE(int x){
    NODE *p = new NODE();
    // Neu khong cap phat duoc bo nho cho p
    if(p == NULL){
        cout<<"\t\tKhong the cap phat bo nho cho p\n\t\t";
        system("pause");
        return NULL;
    }
    p->data = x;
    p->pNext = NULL; // Node p moi tao chua co tri den Node nao
    return p;
}

// -------------HAM KIEM TRA HANG DOI CO DANG RONG HAY KHONG------------------
bool IsEmpty(QUEUE s){
    if(s.pHead == NULL)
        return true;
    else
        return false;
}

// HAM PUSH - Them Node vao Queue <=> Them vao cuoi
bool Push(QUEUE &q, NODE *p){
    // Neu Khoi tao Node p loi
    if(p == NULL){
        return false;
    }
    // Neu hang doi dang rong
    if(IsEmpty(q)){
        q.pHead = q.pTail = p;
    }
    else{
        q.pTail->pNext = p;
        q.pTail = p;
    }
    return true;
}

//-----------HAM POP, Lay gia tri dau tien cua Queue dong thoi xoa no di, theo co che FIFO
bool Pop(QUEUE &q, int &value){
    // Neu danh sach rong tra ve false
    if(IsEmpty(q))
        return false;
    // lay gia tri cua pHead dau danh sach gan cho value
    value = q.pHead->data;
    NODE *tmp = q.pHead;
    q.pHead = q.pHead->pNext;
    delete tmp;
    return true;
}

//-----------HAM TOP, Doc gia tri dau tien cua Hang doi Queue, theo co che FIFO
bool Top(QUEUE q, int &value){
    // Neu hang doi rong, tra ve false
    if(IsEmpty(q))
        return false;
    value = q.pHead->data;
    return true;
}

//----------XUAT GIA TRI TRONG HANG DOI------------
void XuatHangDoi(QUEUE q){
    if(!IsEmpty(q)){
        for(NODE *k = q.pHead; k != NULL; k = k->pNext){
            cout<<k->data<<" ";
        }
    }
    else cout<<"Danh sach dang rong\n\t\t";
}

//--------HAM XOA BO NHO QUEUE--------------
void ClearQueue(QUEUE &q){
    while(q.pHead != NULL){
        NODE *tmp = q.pHead;
        q.pHead = q.pHead->pNext;
        delete tmp;
    }
}

//--------HAM MENU thuc hien chuc nang bai toan--------
void Menu(QUEUE q){
    int choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t------------MENU------------";
        cout<<"\n\t\tMOI BAN NHAP TUY CHON";
        cout<<"\n\t\t1. Them Node vao QUEUE";
        cout<<"\n\t\t2. Xuat QUEUE ra man hinh";
        cout<<"\n\t\t3. Lay Phan tu dau tien cua QUEUE va xoa phan tu do";
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
            NODE *p = KhoiTaoNODE(x);
            if(Push(q, p)==false){ // Vua thuc hien ham Push vua thuc hien kiem tra
                cout<<"\t\tGia tri dua vao khong hop le"; 
            }
        }
        else if(choice == 2){
            cout<<"\t\tDanh sach trong QUEUE: ";
            XuatHangDoi(q);
            system("pause");
        }
        else if(choice == 3){
            int value;
            cout<<"\t\tPhan tu dau tien: ";
            if(Pop(q, value) == true) // Vua thuc hien ham Pop vua kiem tra bool
                cout<<value<<"\n\t\t";
            else cout<<"Khong co phan tu nao\n\t\t";
            system("pause");
        }
        else if(choice == 4){
            int value;
            cout<<"\t\tPhan tu dau tien: ";
            if(Top(q, value) == true) // Vua Thuc hien ham Top vua kiem tra bool
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
    QUEUE q;
    KhoiTaoHangDoi(q);
    Menu(q);
    ClearQueue(q);
    return 0;
}

