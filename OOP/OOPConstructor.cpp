#include <iostream>
using namespace std;
class Student{
private:
    string name;
    int age;
public:
    Student(string name, int age){ //Student(string n, int a){ 
        this->name = name; // name ở thuộc tính = name trong hàm name=n;
        this->age = age; // age ở thuộc tính = age trong hàm age = a;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
int main(){
    Student *s1 = new Student("Dan", 20); //Student s1("Dan", 20);
    s1->display(); //s1.display();

}