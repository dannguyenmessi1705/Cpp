/*
Cho so tu nhiên K và xâu ký tu các chu so S.
Nhiem vu cua ban là dua ra so lon nhat bang cách thuc hien
nhieu nhat K lan doi cho các ký tu trong S.
Ví du K =3 và S = “1234567” ta duoc “7654321”
*/
/*
Y tuong: Tao 1 xau co thu tu giam dan, roi dem swap tu phan tu dau tien
o xau goc voi gia tri phan tu dau tien cau xau moi, cu the tang chi so phan tu
cung nhu bien dem den khi so lan swap = K
VD: 1034, K=2
xau moi: 4310
swap(1, 4) => 4031, count = 1
swap(0, 3) => 4301, count = 2 => dung

*/
#include <bits/stdc++.h>
using namespace std;

string Init(string num)
{
    {
        string rnum = "";
        rnum += num;
        sort(rnum.rbegin(), rnum.rend());
        return rnum;
    }
}

string SwapMax(string num, int K)
{
    string cmpNum = Init(num);
    int count = 0;
    for (int i = 0; i < num.length() && count != K; i++)
    {
        for (int j = i; j < num.length(); j++)
        {
            if (cmpNum[i] == num[j])
            {
                swap(num[i], num[j]);
                count++;
                break;
            }
        }
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int K;
        cin >> K;
        string num = "";
        cin >> num;
        cout << SwapMax(num, K) << endl;
    }
}