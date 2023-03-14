#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a1;  // Khai bao vector a1 co kieu int
    a1.assign(3, 3); // Gan va thay the gia tri vao phan tu, gan 3 gia tri = 3 => a1 = 333

    for (int i = 0; i <= 5; i++)
    {
        a1.push_back(i); // Them phan tu vao cuoi vector a1 = 333012345
    }

    a1.pop_back(); // Xoa phan tu cuoi cung cua vector a1 = 33301234

    a1.insert(a1.begin(), 1); // Chen phan tu vao truoc iterator insert(pos iterator, value), chen 1 vao truoc a1[0] => a1 = 133301234

    a1.erase(a1.end() - 1); // Xoa phan tu o vi tri iterator erase(pos iterator), xoa a1[len-1] => a1 = 13330123

    a1.erase(a1.begin() + 1, a1.begin() + 3 + 1); // Xoa phan tu o vi tri iterator den iterator + 3,, luu ys phai + them 1, xoa a[1]->a[3] => a1 = 101234

    // delete vector a1.clear()
    // swap vector a1.swap(a2)
    vector<int> a2 = a1;  // Khai bao vector a2 = a1;
    int len2 = a2.size(); // ham tra ve do dai cua vector s2;
    for (int i = 0; i < len2; i++)
    {
        cout << a2[i];
    }
    cout << endl
         << a2.front() + a2.back(); // ==a2[0]+a2[a2.size()-1];
}