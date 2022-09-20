#include <iostream>
using namespace std;
class Employee{
private:
    int id;
    string firstName;
    string lastName;
    int salary;
public:
    Employee(){};
    Employee(int id, string firstName, string lastName, int salary){
        this->firstName=firstName;
        this->id=id;
        this->lastName=lastName;
        this->salary=salary;
    }
    void setId(int id){
        this->id=id;
    }
    void setFirstName(string firstName){
        this->firstName=firstName;
    }  
    void setSalary(int salary){
        this->salary=salary;
    }  
    void setLastName(string lastName){
        this->lastName=lastName;
    }  
    int getId(){
        return id;
    }
    int getSalary(){
        return salary;
    }  
    string getFirstName(){
        return firstName;
    }  
    string getLastName(){
        return lastName;
    }  
    string getFullName(){
       return firstName+" "+lastName;
    }  
};
int main() {
	Employee e(1, "Kien", "Hoang", 1000);
	cout << "Id: " << e.getId() << endl;
	cout << "Name: " << e.getFullName() << endl;
	cout << "Salary: " << e.getSalary() << endl;
	return 0;
}