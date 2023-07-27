#include <bits/stdc++.h>
using namespace std;
void swap(string &n1, string &n2)
{
    string tmp = n1;
    n1 = n2;
    n2 = tmp;
}
string SUM(string n1, string n2)
{
    if (n1.length() < n2.length())
    {
        swap(n1, n2);
    }
    string tmp(n1.size() + 1, 0); // Khai bao chuoi ket qua co do dai max, gia tri 0
    int l1 = n1.length();
    int l2 = n2.length();
    int dis = l1 - l2; // n1 dài hơn n2 bao số
    int sum = 0;
    int nho = 0;        // lưu biến nhớ
    int k = tmp.size(); // lưu biến độ dài trong SUM
    for (int i = l2 - 1; i >= 0; i--)
    {
        sum = (n1[i + dis] - '0') + (n2[i] - '0') + nho;
        int donvi = sum % 10; // tìm giá trị đơn vị
        nho = sum / 10;
        tmp[--k] = donvi;
    }
    for (int i = dis - 1; i >= 0; i--)
    {
        sum = (n1[i] - '0') + nho;
        int donvi = sum % 10;
        nho = sum / 10;
        tmp[--k] = donvi;
    }
    if (nho > 0)
    {
        tmp[--k] = nho;
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        tmp[i] += '0';
    }
    if (tmp[0] == '0')
    {
        return tmp.substr(1); // Cat chuoi neu ky tu dau bang 0
    }
    return tmp;
}
int main()
{
    ifstream FileIn;
    ofstream FileOut;
    FileIn.open("big.in", ios::in);
    FileOut.open("big.out", ios::out);
    if (FileIn.fail())
        return 0;
    int test;
    FileIn >> test;
    FileIn.ignore();
    while (test--)
    {
        string nhap = "";
        FileIn >> nhap;
        FileOut << SUM(nhap, "2022") << endl;
    }
    return 0;
}