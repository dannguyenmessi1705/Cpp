/*Huyền có một cái điện thoại, màn hình điện thoại của Huyền chỉ hiển thị được tối đa k tin nhắn. Màn hình của Huyền hiện thị như sau:

Không hiện thị 2 tin nhắn của cùng một số điện thoại (SĐT) trên cùng một khung hình, nếu SĐT a gửi tin nhắn đến mà trên màn hình đã có tin nhắn của SĐT a thì màn hình không thay đổi gì.
Khi SĐT a gửi tin nhắn đến mà trên màn hình chưa có tin nhắn của SĐT a thì:
Nếu màn hình chưa đủ k tin nhắn thì tin nhắn của SĐT a sẽ được chèn vào cuối màn hình.
Nếu màn hình đã có đủ k tin nhắn thì thì màn hình sẽ đẩy tin nhắn trên cùng ra và sau đó chèn tin nhắn của SĐT a vào cuối màn hình.
Cho dãy a là các SĐT sẽ gửi tin nhắn cho Huyền. Hỏi sau khi nhận được tin nhắn cuối cùng thì màn hình của Huyền đang hiển thì tin nhắn của các SĐT nào, đưa ra theo thứ tự từ trên xuống dưới của màn hình.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number, limit;
    queue<int> q;
    cin >> number;
    int mess[number];
    bool check[999];
    for (int i = 0; i < 1000; i++)
    {
        check[i] = false;
    }
    for (int i = 0; i < number; i++)
    {
        cin >> mess[i];
    }
    cin >> limit;
    for (int i = 0; i < number; i++)
    {
        if (!check[mess[i]])
        {
            if (q.size() < limit)
            {
                check[mess[i]] = true;
                q.push(mess[i]);
            }
            else
            {
                check[q.front()] = false;
                check[mess[i]] = true;
                q.push(mess[i]);
                q.pop();
            }
        }
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}