#include "Object.h"
#include "ReadData.h"
#include "ManagerData.h"
//---------------SAP XEP THONG TIN KHACH HANG--------------------

void Swap(Customer &a, Customer &b){
    Customer tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int Lay_gia_tri_de_CatTen(string a){
    int cat = 0;
    int len = a.length();
    for(int i=len-1; i>=0; i--){
        if(a.at(i) == ' ') break;
        else cat++;
    }
    return cat;
}

bool SapxepString_tangdan(string a, string b){
    int lena = a.length();
    int lenb = b.length();
    int min = (lena <= lenb)?lena:lenb;
    for(int i = 0; i < min; i++){
        if((a[i] - '0') < (b[i] - '0'))
            return true;
        else if((a[i]-'0') > (b[i]-'0'))
            return false;
        else continue;
    }
    return true;
}

bool SapxepString_giamdan(string a, string b){
    int lena = a.length();
    int lenb = b.length();
    int min = (lena <= lenb)?lena:lenb;
    for(int i = 0; i < min; i++){
        if((a[i] - '0') < (b[i] - '0'))
            return false;
        else if((a[i]-'0') > (b[i]-'0'))
            return true;
        else continue;
    }
    return false;
}

int Lay_gia_tri_de_CatHo(string a){
    int cat = 0;
    int len = a.length();
    for(int i=len-1; i>=0; i--){
        if(a.at(i) == ' ') break;
        else cat++;
    }
    return len-cat;
}

void SortName_A_to_Z(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            int lenK = 0, lenG = 0;
            string TenK, TenG, HoK, HoG;
            int DoDaiTenK = Lay_gia_tri_de_CatTen(k->data.getName());
            lenK = k->data.getName().length();
            TenK = k->data.getName().substr(lenK - DoDaiTenK, DoDaiTenK);
            HoK = k->data.getName().substr(0, lenK - DoDaiTenK);
            int DoDaiTenG = Lay_gia_tri_de_CatTen(g->data.getName());
            lenG = g->data.getName().length();
            TenG = g->data.getName().substr(lenG - DoDaiTenG, DoDaiTenG);
            HoG = k->data.getName().substr(0, lenG - DoDaiTenG);
            if(strcmp(TenK.c_str(), TenG.c_str()) == 0){
                if(SapxepString_tangdan(HoK, HoG) == false){
                    Swap(k->data, g->data);
                }
            }
            else if(SapxepString_tangdan(TenK, TenG) == false){
                Swap(k->data, g->data);
            }
            else continue;
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();
}

void SortName_Z_to_A(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            int lenK = 0, lenG = 0;
            string TenK, TenG, HoK, HoG;
            int DoDaiTenK = Lay_gia_tri_de_CatTen(k->data.getName());
            lenK = k->data.getName().length();
            TenK = k->data.getName().substr(lenK - DoDaiTenK, DoDaiTenK);
            HoK = k->data.getName().substr(0, lenK - DoDaiTenK);
            int DoDaiTenG = Lay_gia_tri_de_CatTen(g->data.getName());
            lenG = g->data.getName().length();
            TenG = g->data.getName().substr(lenG - DoDaiTenG, DoDaiTenG);
            HoG = k->data.getName().substr(0, lenG - DoDaiTenG);
            // Sap xep theo ten truoc roi trung nhau moi xet den ho
            if(strcmp(TenK.c_str(), TenG.c_str()) == 0){
                if(SapxepString_giamdan(HoK, HoG) == false){
                    Swap(k->data, g->data);
                }
            }
            else if(SapxepString_giamdan(TenK, TenG) == false){
                Swap(k->data, g->data);
            }
            else continue;
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();
}

void SortAddress_A_to_Z(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(SapxepString_tangdan(k->data.getAddress(), g->data.getAddress()) == false)
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortAddress_Z_to_A(ifstream &FileIn, LIST &l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(SapxepString_giamdan(k->data.getAddress(), g->data.getAddress()) == false)
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortBill_0_to_9(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getBill() > g->data.getBill())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortBill_9_to_0(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getBill() < g->data.getBill())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}
void SortRate_0_to_9(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getRate() > g->data.getRate())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}

void SortRate_9_to_0(ifstream &FileIn, LIST l){
    ThemCustomerVaoList(FileIn, l);
    for(NODE *k = l.pHead; k->pNext != NULL; k = k->pNext){
        for(NODE *g = k->pNext; g != NULL; g = g->pNext){
            if(k->data.getRate() < g->data.getRate())
                Swap(k->data, g->data);
        }
    }
    FileIn.close();
    ofstream FileOut;
    FileOut.open("data.txt", ios::out);
    XuatDSInFoRaFile(FileOut, l, 1);
    FileOut.close();    
}