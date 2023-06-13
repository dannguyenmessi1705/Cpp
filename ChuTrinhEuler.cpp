/* Chu trinh Euler: Duong di se quay ve lai diem ban dau ma khong lap lai canh
   Duong di Euler: Duong di se ko quay lai diem ban dau, nhung di xong het cac dinh trong do thi
   Voi do thi vo huong: Chu trinh Euler(Ko co dinh nao bac 0 va tat ca cac dinh phai co bac chan)
                        Duong di Euler(Co 2 dinh la bac le, duong di se xuat phat tu 1 trong 2 dinh va ket thuc o dinh con lai)
   Voi do thi co huong: Chu trinh Euler(Tat ca cac dinh co so bac ra = so bac vao(deg+ == deg-))
                        Duong di Euler(Co 2 dinh co su chenh lech deg+ - deg- = 1(xuat phat) va nguoc lai(ket thuc))
*/
// VOI CHU TRINH EULER CHO DO THI VO HUONG
#include <bits/stdc++.h>
using namespace std;
int n, m, start;    // Khoi tao so dinh va so canh
set<int> adj[1001]; // Khoi tao danh sach ke
void In()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout << "Nhap canh bat dau chu trinh Euler: ";
    cin >> start;
}
void Euler(int V)
{
    stack<int> check; // Stack ktra dinh
    vector<int> EC;   // Vector luu chu trinh Euler
    check.push(V);    // Bat dau cho dinh V vao stack de tim chu trinh
    while (!check.empty())
    {
        int x = check.top(); // Lan luot cho cac dinh vao trong stack
        if (adj[x].size() != 0)
        {                            // Neu dinh X con ke voi dinh khac
            int y = *adj[x].begin(); // Chon dinh ke dau tien voi x
            check.push(y);           // Cho dinh ke dau tien voi X vao stack
            adj[x].erase(y);         // Dong thoi xoa canh ke voi x sau khi tim duoc
            adj[y].erase(x);         // Vi la do thi vo huong nen cung phai xoa huong nguoc lai
        }
        else
        {
            check.pop(); // Neu ko con ke voi dinh nao, thi ta tim duoc 1 dinh tu chu trinh Euler
            EC.push_back(x);
        }
    }
    reverse(EC.begin(), EC.end());
    for (int i : EC)
    {
        cout << i << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << "Nhap danh sach canh: " << endl;
    In();
    cout << "Chu trinh Euler la: ";
    Euler(start);
}