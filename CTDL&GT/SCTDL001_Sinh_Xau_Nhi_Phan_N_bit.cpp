#include <bits/stdc++.h>
using namespace std;
#define MAX 40
int X[MAX];
bool check = true;
int n;
// Ham khoi tao xau nhi phan ban dau (0 0 0 ...)
void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        X[i] = 0;
    }
}
// Ham xuat xau nhi phan
void Out()
{
    for (int i = 0; i < n; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}
// Ham sinh xau ke tiep
void Do()
{
    int i = n - 1;              // Duyet i tu cuoi mang
    while (i >= 0 && X[i] != 0) // Xet chi so i tu phai sang trai, cho den khi tim duoc X[i]=0 thi tat ca X[j] (j>i) o phia sau se bang 0
    {
        X[i] = 0;
        i--;
    }
    if (i >= 0) // Neu i van con >= 0, gia tri X[i] = 0 se doi X[i] = 1
    {
        X[i] = 1;
    }
    else // Neu duyet het tu phai sang trai ma khong gap truong hop nao X[i] = 0, VD: 1111 thi day xau nay chinh la day cuoi => Ket thuc
        check = false;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        check = true; // Khoi tao lai bien check = true sau moi test
        Init();
        while (check) //  Neu check = true, tiep tuc sinh xau
        {
            Out();
            Do();
        }
    }
}