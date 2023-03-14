/*
Bàn cờ quốc tế có kích thước n⨯n.Quân hậu có khả năng kiểm soát tất cả các ô nằm trên cùng hàng, cột, hoặc trên hai đường chéo đi qua ô đặt nó. Hãy cho biết có bao nhiêu giải pháp đặt n quân hậu trên cùng một bàn cờ sao cho không có quân nào nằm trong ô bị kiểm soát bởi quân hậu khác.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int n, x[MAX], cnt = 0;
bool col[MAX], cross1[MAX], cross2[MAX];
void Find(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!col[j] && !cross1[i - j + n] && !cross2[i + j - 1])
        {
            x[i] = j;
            col[j] = true;
            cross1[i - j + n] = true;
            cross2[i + j - 1] = true;
            if (i == n)
            {
                cnt++;
            }
            else
            {
                Find(i + 1);
            }
            col[j] = false;
            cross1[i - j + n] = false;
            cross2[i + j - 1] = false;
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        Find(1);
        cout << cnt << endl;
    }
}