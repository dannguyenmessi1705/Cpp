/*
Cho mot so nguyen N, nhiem vu la tao ra tat ca cac chuoi nhi phan co the co do dai N co chua "01" lam chuoi con chinh xoc hai lan.
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> genBin(int N)
{
    vector<string> res;
    for (int i = 0; i < (1 << N); i++)
    {
        string binstr = bitset<32>(i).to_string().substr(32 - N);
        int count = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (binstr[j] == '0' && binstr[j + 1] == '1')
            {
                count++;
            }
        }
        if (count == 2)
        {
            res.push_back(binstr);
        }
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> res = genBin(n);
    sort(res.rbegin(), res.rend());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
}