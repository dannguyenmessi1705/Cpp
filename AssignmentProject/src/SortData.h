#ifndef _SORTDATA_H
#define _SORTDATA_H
#include "SortData.cpp"
//---------------SAP XEP THONG TIN KHACH HANG--------------------

void Swap(Customer &a, Customer &b);

int Lay_gia_tri_de_CatTen(string a);

bool SapxepString_tangdan(string a, string b);

bool SapxepString_giamdan(string a, string b);

int Lay_gia_tri_de_CatHo(string a);

void SortName_A_to_Z(ifstream &FileIn, LIST &l);

void SortName_Z_to_A(ifstream &FileIn, LIST &l);

void SortAddress_A_to_Z(ifstream &FileIn, LIST &l);

void SortAddress_Z_to_A(ifstream &FileIn, LIST &l);

void SortBill_0_to_9(ifstream &FileIn, LIST l);

void SortBill_9_to_0(ifstream &FileIn, LIST l);

void SortRate_0_to_9(ifstream &FileIn, LIST l);

void SortRate_9_to_0(ifstream &FileIn, LIST l);
#endif