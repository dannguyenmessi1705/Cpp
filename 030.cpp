#include <bits/stdc++.h>
// duyet tu cuoi ve
// gap ptu lon nhat va phai xa nhat
// thi doi cho
// se tao dc so lon nhat
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        // k la so la dc doi cho con lai
        int k;
        cin >> k >> s;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            // khoi tao max = gia tri so cuoi cung
            char max = s[n - 1];
            // vi tri cua so day la cuoi
            int vt = n - 1;
            // duyet tu ptu tiep theo
            // tim so lon nhat va xa nhat
            for (int j = i + 1; j < n && k > 0; j++)
            {
                if (max <= s[j])
                {
                    max = s[j];
                    vt = j;
                }
            }
            // neu tim dc va con doi dc thi doi
            if (max > s[i] && k > 0)
            {
                swap(s[i], s[vt]);
                k--;
            }
        }
        cout << s << endl;
    }
}