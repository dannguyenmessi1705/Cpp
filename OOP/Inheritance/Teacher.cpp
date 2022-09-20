#include "Person.cpp"
using namespace std;
class Teacher : public Person{
private:
    int salary;
public:
    Teacher(string name, int age, string address, int salary):Person(name, age, address){
        this->salary=salary;
    }
    void setSalary(int salary){
        this->salary=salary;
    }
    double getSalary(){
        return salary;
    }
    void display(){
        Person::display();
        cout<<"Salary: "<<salary<<endl;
    }
};