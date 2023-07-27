#include <bits/stdc++.h>
using namespace std;
// Khai báo hàm exam
void exam(int i, int *p, int &r)
{
    p = &r; // p = địa chỉ của r (phần xám đó :)) )
    r++;    // tăng r lên 1
    *p = i; // gán giá trị của p = i (phần xanh đó), mà p = địa chỉ của r nên giá trị của r (phần xanh) cũng bị thay đổi theo p
}
main()
{
    int arr[3]{20, 22}; // khai báo mảng arr có 3 phần tử, nhưng chỉ chuyền vào 2 số {20, 22} nên 2 phần tử đầu có giá trị là 20, 22, phần tử thứ 3 có giá trị là 0
    // => arr[0] = 20, arr[1] = 22, arr[2] = 0
    int *q{arr};             // khai báo con trỏ q trỏ đến địa chỉ của phần tử đầu tiên của mảng arr (p = &arr[0], phần xám của arr[0] đó)
    exam(arr[2], q, arr[1]); // gọi hàm exam(int i, int *p, int &r) với i = arr[2] = 0, p = q = &arr[0] (phần xám) , r = arr[1] = 22
    // => Gọi hàm exam(0, &arr[0], 22)
    // p = &r === q = &arr[1] (q trỏ tới địa chỉ của arr[1], phần xám)
    // r++ === arr[1]++ === 23
    // *p = i === *q = arr[2] = 0, mà q lại đang trỏ tới địa chỉ của arr[1], dòng 17 đó, nên arr[1] = q = 0
    cout << *q << " " << arr[0] << " " << arr[1] << " " << arr[2];
    // *q = arr[0] = 20 (do q trỏ tới địa chỉ của arr[0], dòng thứ 14 đó),
    // arr[0] = 20 (ban đầu khai báo rồi, và nó không thay đổi),
    // arr[1] = 0 (sau khi thực hiện hàm exam thì nó tăng lên 1 đơn vị ở dòng số 18, nhưng đến dòng 19 lại đổi theo q về 0 đó),
    // arr[2] = 0 (không thay đổi)
}