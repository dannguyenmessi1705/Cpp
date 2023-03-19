#include <bits/stdc++.h>
using namespace std;
int main()
{
    fstream F;
    F.open("./main.cpp", ios::in);
    string s;
    int count = 0;
    while (cin >> s)
    {
        count += s.length();
    }
    F.close();
    F.open("./output.txt", ios::out);
    F << count;
    F.close();
}