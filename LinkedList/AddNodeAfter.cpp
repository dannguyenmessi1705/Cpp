#include <iostream>
using namespace std;

// Khai bao cau truc 1 node
struct node{
    int data; // Du lieu chua trong 1 node
    struct node *pNext; // Con tro dung de lien ket cac node voi nhau
} typedef NODE;

// Khai bao cau truc danh sach lien ket don
struct list{
    NODE *pHead;  // Node quan ly dau danh sach
    NODE *pTail; // Node quan ly cuoi danh sach
} typedef LIST;

// Khoi tao 1 danh sach lien ket don
void KhoiTaoDS(LIST &l){
    // cho 2 node tro den NULL, vi danh sach chua co phan tu nao ca
    l.pHead = NULL; 
    l.pTail = NULL;
}

// Khoi tao 1 node
NODE *KhoiTaoNode(int x){
    NODE *p = new NODE;
    if(p==NULL){
        cout<<"\t\tKhong du bo nho!!";
        return NULL;
    }
    p->data=x; // Truyen gia tri x vao data
    p->pNext=NULL; // Dau tien khi chua co lien ket voi node nao ca, con tro se tro den NULL
    return p;
}

//Them Node vao dau danh sach
void ThemVaoDau(LIST &l, NODE *p){
    // Check danh sach co rong hay khong
    if(l.pHead==NULL){
        l.pHead = l.pTail = p; // Node dau cung la node cuoi
    }
    else{
        p->pNext = l.pHead; // Cho con tro cua node p->pNext lien ket voi node l.pHead
        l.pHead = p; // Cap nhap lai cho node dau l.pHead chinh la node p
    }
}

// Them Node vao sau danh sach
void ThemvaoCuoi(LIST &l, NODE *p){
    // Check danh sach co rong khong
    if(l.pHead==NULL){
        l.pHead = l.pTail = p; // node dau cung la node cuoi
    }
    else{
        l.pTail->pNext = p; // Cho con tro cua pTail->pNext lien ket voi node p
        l.pTail = p; // Cap nhat lai node p chinh la pTail 
    }
}
void XuatDS(LIST l){
    for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
        cout<<k->data<<" ";
    }
    cout<<endl;
}

// Them node p vao sau node q trong danh sach lien ket
void ThemNodePVaoSauNodeQ(LIST &l, NODE *p){
    int x;
    cout<<"\t\tNhap gia tri node q: ";
    cin>>x;
    NODE *q = KhoiTaoNode(x);
    // Neu danh sach chi co 1 phan tu, va phan tu do chinh la node q => bai toan tro thanh ThemVaoCuoi
    if(q->data == l.pHead->data && l.pHead->pNext == NULL){
        ThemvaoCuoi(l, p);
    }
    else{
        // Duyet tu dau toi cuoi danh sach de tim node q
        for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
            if(q->data == k->data){
                NODE *h = KhoiTaoNode(p->data); // Them node h moi vao sau node q, muc dich de moi lan kiem tra 1 node = node q thi
                                                // ta gan Khoi chay 1 node h moi de no co 1 dia chi moi, nhu vay luc them vao pointer vao se
                                                // khong bi lam mat lien ket giua cac node

                NODE *tmp = k->pNext; // cho node tmp tro den sau node q
                h->pNext = tmp; // B1: Tao moi lien ket tu node p den node tmp <=> cung chinh la tao moi lien ket tu node p den node nam sau node q
                k->pNext = h; // B2: Tao moi lien ket tu node q den node p <=> chinh la node k den node p


            }
        }
    }

}

//Them node p vao truoc node q <=> them node p vao sau node g (node g la node dung truoc node q ban dau)
void ThemNodePVaoTruocNodeQ(LIST &l, NODE *p){
    int x;
    cout<<"\t\tNhap gia tri node q: ";
    cin>>x; // Nhap gia tri de tim node q
    NODE *q = KhoiTaoNode(x); // Khoi tao node q voi data la int x
    NODE *g = new NODE; // node nay de giu lien ket voi cac node truoc q
    // Neu danh sach lien ket chi co 1 node, va node do dung = node q. bai toan tro thanh them vao dau
    if(q->data == l.pHead->data && l.pHead->pNext == NULL){
        ThemVaoDau(l, p);
    }
    else{
    // Neu danh sach lien ket co nhieu hon mot phan tu
        for(NODE *k = l.pHead; k != NULL; k=k->pNext){
            if(q->data == k->data){
                NODE *tmp = KhoiTaoNode(p->data); // Them node tmp moi vao sau node q, muc dich de moi lan kiem tra 1 node = node q thi
                                                    // ta gan Khoi chay 1 node tmp moi de no co 1 dia chi moi, nhu vay luc them vao pointer vao se
                                                    // khong bi lam mat lien ket giua cac node
                tmp->pNext = k; // B1: tro tmp->pNext den node sau cua no la node k de tao lien ket
                g->pNext = tmp; // B2: tro node g->pNext truoc node tmp de tao lien ket, => g -> tmp -> k
            }
            g = k; // Sau moi 1 vong lap gan node g = node k de giu lien ket cac node truoc q
                   // cung nhu de thuc hien baii toan them node p vao sau node g <=> them node p vao truoc node q
        }
    }
}
void Menu(LIST l){
    int choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t------------MENU------------";
        cout<<"\n\t\tMOI BAN NHAP TUY CHON";
        cout<<"\n\t\t1. Them node vao danh sach";
        cout<<"\n\t\t2. In danh sach lien ket don";
        cout<<"\n\t\t3. Chen node q vao sau node q";
        cout<<"\n\t\t4. Chen node q vao truoc node q";
        cout<<"\n\t\t0. Thoat Menu";
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
            cout<<"\t\tNhap gia tri so nguyen: ";
            cin>>x;
            NODE *p=KhoiTaoNode(x);
            ThemvaoCuoi(l, p);
        }
        else if(choice == 2){
            cout<<"\t\tDanh sach lien ket don: ";
            XuatDS(l);
            cout<<"\t\t";
            system("pause"); // dung man hinh
        }
        else if(choice == 3){
            int x;
            cout<<"\t\tNhap gia tri so nguyen can them: ";
            cin>>x;
            NODE *p = KhoiTaoNode(x);
            ThemNodePVaoSauNodeQ(l, p); // them node p vao sau node q


        }
        else if(choice == 4){
            int x;
            cout<<"\t\tNhap gia tri so nguyen can them: ";
            cin>>x;
            NODE *p = KhoiTaoNode(x);
            ThemNodePVaoTruocNodeQ(l, p); // them node p vao truoc node q


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
    KhoiTaoDS(l);
    Menu(l);
}
