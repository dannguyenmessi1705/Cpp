#ifndef _ADDDATA_H
#define _ADDDATA_H
#include "AddData.cpp"
//-------------THEM THONG TIN KHACH HANG--------------------
bool KiemTraDauVao(LIST l, Customer x);

void XuatCacTruong(ofstream &FileOut);

//Ham them thong tin 1 Khach hang ra FILE
void AddInfoRaFile(ofstream &FileOut, LIST l);

// Ham them DS thong tin khach hang ra FILE
void XuatDSInFoRaFile(ofstream &FileOut, LIST l);

#endif