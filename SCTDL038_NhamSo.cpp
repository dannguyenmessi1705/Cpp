#include <bits/stdc++.h>
using namespace std;
string A, B;
int test;
int Convert_Min()
{
    int max;
    A.length() > B.length() ? max = A.length() : max = B.length();
    for (int i = 0; i < max; i++)
    {
        if (A[i] == '5')
            A[i] = '3';
        if (B[i] == '5')
            B[i] = '3';
    }
    return stoi(A) + stoi(B);
}
int Convert_Max()
{
    int max;
    A.length() > B.length() ? max = A.length() : max = B.length();
    for (int i = 0; i < max; i++)
    {
        if (A[i] == '3')
            A[i] = '5';
        if (B[i] == '3')
            B[i] = '5';
    }
    return stoi(A) + stoi(B);
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> A >> B;
        cout << Convert_Min() << " " << Convert_Max();
        cout << endl;
    }
}