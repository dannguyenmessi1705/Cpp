#include <iostream>
using namespace std;
class Student{
private:
    string name;
    int age;
public:
    static int count; // khai báo biến tĩnh, có giá trị thay đổi theo cả bài, ko phụ thuộc vào đối tượng nào
    Student(string name, int age){
        this->name=name;
        this->age=age;
        count++;
    }
    static int getCount(){ // Phương thức static chỉ gọi được đến biến static trong cùng 1 lớp
        return count;
    }
};
int Student::count=0; // gán biến tĩnh trong class 
int main(){
    Student s1("Dan", 20); //Student::count=1
    Student s2("Dat", 21); //Student::count=2
    Student s3("Diep", 22); //Student::count=3
    cout<<Student::count<<endl; //3
    cout<<s1.count<<endl; //3
    cout<<s2.count<<endl; //3
    cout<<s3.count<<endl; //3 
    cout<<Student::getCount() //3;
}