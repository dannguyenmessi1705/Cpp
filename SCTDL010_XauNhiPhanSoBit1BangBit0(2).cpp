// Bai nay phai de cac bit bat dau tu 1 truoc moi dung :))
#include <iostream>
using namespace std;

void print(string &s, int n)
{ // đây là hàm in các chuỗi binary đã tạo
    int cnt1 = 0, cnt2 = 0;
    for (char c : s)
    {
        if (c == '0')
            cnt1++;
        else
            cnt2++;
    }
    if (cnt1 != cnt2)
        return; // nếu không bằng nhau thì không đáp ứng yêu cầu đề bài
    cout << s << ' ';
}

void solve(string &s, int n, int cnt)
{ // hàm đệ quy sinh các chuỗi binary
    if (n == s.size())
    {
        print(s, n);
        return;
    }
    s.push_back('1');
    solve(s, n, cnt + 1);
    s.pop_back();
    s.push_back('0');
    solve(s, n, cnt);
    s.pop_back();
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {

        int n;
        cin >> n;
        if (n & 1)
            cout << "-1\n"; // kiểm tra số bit phải bằng nhau nên n chắn
        else
        {
            string s;
            solve(s, n, 0);
            cout << endl;
        }
    }
    return 0;
}
