#include <bits/stdc++.h>
using namespace std;
string GrayToBin(string gray)
{
    int len = gray.length();
    string bin = "";
    bin += gray[0];
    for (int i = 1; i < len; i++)
    {
        bin += (gray[i] != bin[i - 1]) ? "1" : "0";
    }
    return bin;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string gray;
        cin >> gray;
        cout << GrayToBin(gray) << endl;
    }
}