/*
Gia su ban là mot nguoi ngheo trong dia phuong cua ban. Dia phuong cua ban cu duy nhat mot cua hang ban luong thuc. Cua hàng cua ban mo cua tat ca coc ngày trong tuan ngoai tru chu nhat. Cho bo ba so N, S, M thoa mon ràng buoc sau:
N : so don vi luong thuc nhieu nhat ban cu the mua trong ngày.
S : so luong ngày ban can duoc su dung luong thuc de ton tai.
M : so don vi luong thuc can cu moi ngay de ban ton tai.Gia su ban dang o ngày thu 2 trong tuan và can ton tai trong S ngày toi. Hoy cho biet so luong ngày ot nhat ban can phai mua luong thuc tu cua hang de ton tai hoac ban se bi chet doi trong S ngay toi.
Dua ra so ngày ot nhat ban cu the mua luong thuc de ton tai hoac dua ra -1 neu ban bi chet doi.
*/
#include <bits/stdc++.h>
using namespace std;
int CountMinDay(int N, int S, int M)
{
    int so_ngay_can_mua_luong_thuc = 1;
    int tong_so_luong_thuc_can = S * M;
    // Vi CN khong duoc mua luong thuc (1 tuan chi duoc mua tu T2->T7) nen ta co
    // so ngay duoc mua luong thuc trong S ngay
    int so_ngay_duoc_mua_luong_thuc = S - S / 7;
    if (tong_so_luong_thuc_can > N * so_ngay_duoc_mua_luong_thuc)
    {
        return -1; // chet doi
    }
    for (so_ngay_can_mua_luong_thuc; so_ngay_can_mua_luong_thuc <= so_ngay_duoc_mua_luong_thuc; so_ngay_can_mua_luong_thuc++)
    {
        if (so_ngay_can_mua_luong_thuc * N >= tong_so_luong_thuc_can)
            return so_ngay_can_mua_luong_thuc;
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int N, S, M;
        cin >> N >> S >> M;
        cout << CountMinDay(N, S, M) << endl;
    }
}