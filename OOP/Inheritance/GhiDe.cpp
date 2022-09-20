#include<iostream>

using namespace std;

class Person {
private:
	string name;
	string gender;

public:
	Person(string name, string gender) {
		this->name = name;
		this->gender = gender;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getGender() {
		return gender;
	}

	void setGender(string gender) {
		this->gender = gender;
	}

	void display() {
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
	}
};

class Student : Person { // Kế thừa
private: 
    int salary;
public:
    Student(string name, string gender, int salary):Person(name, gender){ //kế thừa constructor từ class Person
        this->salary=salary;
    }
    void display(){ // đặt phương thức trùng với class cha thì class cha sẽ bị thay thế
        Person::display(); // Gọi phương thức từ lớp cha
        cout<<"Salary: "<<salary;
    }

};

int main() {
	Student s("Trung", "Male", 1700);
	s.display();
	return 0;
}