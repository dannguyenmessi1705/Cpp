#include <bits/stdc++.h>
using namespace std;

// Hàm để xuất ra tất cả các chuỗi nhị phân có thể
// có thể được hình thành bằng cách thay thế mỗi ký tự  '?' trong chuỗi đã cho bằng '0' hoặc '1'
void BinaryString(string str, int i, int n)
{
    if (i == n)
    {
        // In ra chuỗi nhị phân
        cout << str << endl;
        return;
    }

    // Neu khong phai la '?', ta se bo qua ky tu do
    if (str[i] != '?')
        BinaryString(str, i + 1, n);

    else
    {
        // Thanh phan thay the cho '?'
        str[i] = '0';
        BinaryString(str, i + 1, n);
        str[i] = '1';
        BinaryString(str, i + 1, n);

        // Quay lại giá trị ban đầu
        str[i] = '?';
    }
}
void DeleteSpace(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(str.begin() + i);
        }
    }
}

// Ham chinh
int main()
{
    int test;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        string str;
        getline(cin, str);
        DeleteSpace(str);
        int n = str.length();
        BinaryString(str, 0, n);
    }
    return 0;
}
