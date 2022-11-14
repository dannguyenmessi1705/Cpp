#ifndef _MODIFYDATA_H
#define _MODIFYDATA_H
#include "ModifyData.cpp"
//=================SUA THONG TIN KHACH HANG=========================
void SuaName(LIST &l, NODE *q, string name);

void SuaAddress(LIST &l, NODE *q, string address);

void SuaEmail(LIST &l, NODE *q, string email);

void SuaPhone(LIST &l, NODE *q, string phone);

void SuaService(LIST &l, NODE *q, string service);

void SuaBill(LIST &l, NODE *q, ll bill);

void SuaRate(LIST &l, NODE *q, int rate);

void SuaInfo(LIST &l, LIST &tmp);

#endif
