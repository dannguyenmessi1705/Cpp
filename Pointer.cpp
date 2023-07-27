#include <bits/stdc++.h>
using namespace std;
void exam(int i, int *p, int &r)
{
    *p = r + i;
}
void exam(int *r, int &i, int *p)
{
    *p = *r + i;
}
int main()
{
    int i(20), p{22}; // Gán i = 20, p = 22
    int *r = {&p};    // (r->p) Gán con trỏ r trỏ tới địa chỉ biến p
    // r = address(p), *r = 22
    exam(p, r, i);
    /*
        exam(22, r, i) {
            *r = i + p = 20 + 22 = 42
        }
    */
    exam(r, i, r);
    /*
        exam(r, 20, r){
            *r = *r + 20 == 42 + 20 = 62
        }
    */
    cout << p << " " << i << " " << *r;
    // do r được trỏ tới địa chỉ của p -> r thay đổi p cũng đổi
    // => p = 62, i = 20, *r = 62
}
