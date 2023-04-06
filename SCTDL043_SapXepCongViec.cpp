#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int, int>> vp(n);
        for(int i = 0; i < n; ++i) cin >> vp[i].first;
        for(int i = 0; i < n; ++i) cin >> vp[i].second;
        sort(vp.begin(), vp.end(), cmp);
        int cnt = 1, cur = vp[0].second;
        for(int i = 1; i < n; ++i)
        {
            if(vp[i].first >= cur)
            {
                ++cnt;
                cur = vp[i].second;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}