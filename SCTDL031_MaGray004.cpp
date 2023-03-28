#include <bits/stdc++.h>
using namespace std;
string Dec2Bin(int n)
{
    string result = "";
    stack<int> s;
    while (n > 0)
    {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty())
    {
        result += (char)(s.top() + '0');
        s.pop();
    }
    return result;
}

string Bin2Gray(int n)
{
    string bin = Dec2Bin(n);
    string result = "";
    result.push_back(bin[0]);
    for (int i = 1; i < bin.length(); i++)
    {
        (bin[i] ^ bin[i - 1]) ? result.push_back('1') : result.push_back('0');
    }
    return result;
}
int Gray2Dec(int n)
{
    string gray = Bin2Gray(n);
    int k = 0, result = 0;
    for (int i = gray.length() - 1; i >= 0; i--)
    {
        result += (int)(gray[i] - '0') * pow(2, k++);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        cout << Gray2Dec(n) << endl;
    }
}