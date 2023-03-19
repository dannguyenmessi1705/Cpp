#include <iostream>
#include <string>

using namespace std;

void GenBit(int n, int count, string str)
{
    // Neu so bit duoc them vao bang n
    if (count == n)
    {
        cout << str << endl;
        return;
    }

    // Them bit 0 va 1 vao
    GenBit(n, count + 1, str + "0");
    GenBit(n, count + 1, str + "1");
}

int main()
{
    int n;
    cout << "Nhap so luong bit: ";
    cin >> n;
    cout << "Xau duoc tao ra tu " << n << " bit:" << endl;
    GenBit(n, 0, "");
    return 0;
}
