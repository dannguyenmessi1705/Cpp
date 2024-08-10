#include <bits/stdc++.h>
using namespace std;
vector<string> a;

void GenBit(int n, int count, string str)
{
    if (count == n)
    {
        a.push_back(str);
        return;
    }

    GenBit(n, count + 1, str + "0");
    GenBit(n, count + 1, str + "1");
}

int main()
{
    int N, K;
    cin >> N >> K;
    GenBit(N, 0, "");
    for (int i = 0; i < a.size(); i = i + K)
    {
        cout << a[i] << endl;
    }
    return 0;
}
