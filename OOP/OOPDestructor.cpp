#include <iostream>
using namespace std;
class Student{
public:
    int *arr;
    int n;
public:
    ~Student(){
        cout<<"Lenh xoa bo nho da duoc goi\n";
        delete[] arr;
    }
};
    // SomeCode
    /* Phương thức hủy của đối tượng được gọi tới khi
    khi chương trình thoát khỏi phạm vi cuả nó, cụ thể:
    1, Khi kết thúc hàm chứa đối tượng đó
            void Ham(){
                Student s1;
                s1.n=3;
                s1.arr = new int[s1.n];
                }
    2, Khi kết thúc chương trình
    3, Khi gọi tới toán tử delete
    4, Khi thoát khỏi block code chứa oop đó { code } */

int main(){
    cout<<"Truoc khi goi lenh xoa bo nho\n";
    Student s1;
    cout<<"Sau khi goi lenh xoa bo nho\n";
}