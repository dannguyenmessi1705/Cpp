/*
Cho so nguyen duong N. Moi buoc, ban se bien doi N thanh [N/2], N mod 2, [N/2].
Sau khi thuc hien mot cach triet de, ta thu duoc mot day so chu toan so 0 v 1.
Nhiem vu cua ban la hay dem cac so bang 1 trong doan [L, R] cua day so cuoi cng.
*/
/*
SOLVE:
N:                       10
cen1:           5         0           5
cen2:      2    1    2    0     2     1      2
cen3:    1 0 1  1  1 0 1  0  1  0  1  0  1   0   1
-------------------------------------------------------
pos :    1 2 3  4  5 6 7  8  9 10 11  12 13  14  15
cen.size = log2(N)
pos[cen(i)] = 2^i (i=1 -> cen.size)
pos[N%2] == 1 [(N>1) / 2 == 1], vi tri le tra ve 1
L=3, R=10 => 5 bit 1

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> cen;

// Ham tim vi tri trung tam sau khi thuc hien het cac phep chia de ra day 10..1001
void CenterValue(ll N)
{
    ll numCen = log2(N); // So lan can thuc hien phep toan (N/2 Nmod2 N/2) de ra day 10
    int mu = 0;
    while (numCen--)
    {
        mu++;
        cen.push_back(pow(2, mu)); // vi tri trung tam chinh la 2^mu (mu: 1->numCen)
    }
}
// Tim kiem xem vi tri dang xet la bit 1 hay 0
ll FindBit1(ll i, ll N, ll pos)
{
    if (i % 2 == 1) // Neu xet o vi tri le => tra ve 1 (Vi khi N>1 / 2 luon bang 1
                    // Neu N<=1 thi bai toan da ngung viec chia cho 2)
        return 1;
    else if (i < cen[pos]) // Neu vi tri can xet < vi tri trung tam, ta can giam vi tri trung tam di 1 don vi
                           // Dong thoi cap nhat lai gia tri cua vi tri trung tam
                           // Muc dich de lam sao ma vi tri trung tam o truoc vi tri can tim
        FindBit1(i, N / 2, pos - 1);
    else if (i == cen[pos]) // Neu vi tri can tim o dung vi tri trung tam, tra ve kq N%2
        return N % 2;
    else if (i > cen[pos]) // Neu vi tri can tim > vi tri trung tam, ta lai lay doi xung cua vi tri do qua vi tri trung tam
                           // roi lai thuc hien tim vi tri trung tam sao cho < vi tri dang xet
                           // Vi gia tri cua cac vi tri doi xung la bang nhau
        FindBit1(2 * cen[pos] - i, N / 2, pos - 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        ll N, L, R, count = 0;
        cin >> N >> L >> R;
        cen.clear();
        CenterValue(N);
        for (ll i = L; i <= R; i++)
        {
            count += FindBit1(i, N, cen.size() - 1);
        }
        cout << count << endl;
    }
}