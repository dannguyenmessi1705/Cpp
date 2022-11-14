#ifndef _SEARCHDATA_H
#define _SEARCHDATA_H
#include "SearchData.cpp"
//-------------TIM KIEM THONG TIN KHACH HANG----------------
// Ham kiem tra ky tu nhap vao co phai la chuoi con cua 1 chuoi cha lon hon hay khong
bool CompareStringParentWithChild(string a, string b);

void SearchID(ifstream &FileIn, LIST l, int id);

void SearchName(ifstream &FileIn, LIST l, string name);

void SearchAddress(ifstream &FileIn, LIST l, string address);

void SearchEmail(ifstream &FileIn, LIST l, string email);

void SearchPhone(ifstream &FileIn, LIST l, string phone);

void SearchService(ifstream &FileIn, LIST l, string service);

void SearchBill(ifstream &FileIn, LIST l, ll bill);

void SearchRate(ifstream &FileIn, LIST l, int rate);
#endif