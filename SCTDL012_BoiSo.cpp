#include <bits/stdc++.h>
using namespace std;
int BCN[501];
bool check[501];
void Init()
{
    int count = 0;
    queue<int> q;
    q.push(9);
    while (count < 500)
    {
        int test = q.front();
        q.pop();
        for (int i = 1; i <= 500 && i <= test; i++)
        {
            if (test % i == 0 && !check[i])
            {
                check[i] = true;
                BCN[i] = test;
                count++;
            }
        }
        q.push(test * 10);
        q.push(test * 10 + 9);
    }
}
int main()
{
    int test;
    cin >> test;
    Init();
    while (test--)
    {
        int n;
        cin >> n;
        cout << BCN[n] << endl;
    }
}