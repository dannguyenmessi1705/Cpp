#include "Object.h"
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