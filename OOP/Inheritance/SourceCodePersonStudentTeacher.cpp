#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
using namespace std;
int main(){
    Student s("Dan", 20, "Hung Yen", 3.6);
    s.display();
    Teacher t("Ha", 25, "Thanh Hoa", 20000);
    t.display();
    Student s1;
    s1.setName("Hai");
    s1.setAddress("Hai Phong");
    s1.setAge(30);
    s1.setGpa(4.0);
    s1.display();
}