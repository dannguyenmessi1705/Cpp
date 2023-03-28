#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int N;
        double check = 1, n = 0;
        vector<ll> gt;
        cin >> N;
        while (n < N)
        {
            n += log10(check);
            if (n > N - 1 && n < N)
            {
                gt.push_back(check);
            }
            check++;
        }
        if (gt.empty())
            cout << "NO";
        else
        {
            cout << gt.size() << " ";
            for (auto x : gt)
            {
                cout << x << " ";
            }
        }
        cout << endl;
    }
}