#ifndef _STATITIC_H
#define _STATITIC_H
#include "Statitic.cpp"
//============THONG KE==============
// Ham tinh tong so lon
void swap(string &n1, string &n2);
string SUM(string n1, string n2);

// Ham thong ke tong so tien cua tat ca khach hang
string TotalBill(ifstream &FileIn, LIST l);

// Ham thong ke tong so khach hang
ll TotalCustomer(ifstream &FileIn, LIST l);

// Ham thong ke so luot danh gia
void TotalRate(ifstream &FileIn, LIST l);
#endif