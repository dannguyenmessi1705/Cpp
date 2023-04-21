#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t = 1, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> cv(n);
        for (int i = 0; i < n; ++i)
            cin >> cv[i].first;
        for (int i = 0; i < n; ++i)
            cin >> cv[i].second;
        sort(cv.begin(), cv.end(), cmp);
        int cnt = 1, cur = cv[0].second;
        for (int i = 1; i < n; ++i)
        {
            if (cv[i].first >= cur)
            {
                ++cnt;
                cur = cv[i].second;
            }
        }
        cout << cnt << endl;
    }
}