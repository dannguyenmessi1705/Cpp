#include <iostream>
using namespace std;
class Student{
private:
    int id;
    string name;
    int age;
    int score;
    string address;
public:
    Student(){};
    Student(int id, string name, int age, string address, int score){
        this->address=address;
        this->age=age;
        this->name=name;
        this->id=id;
        this->score=score;
    }
    void setId(int id){
        this->id=id;
    }
    void setAge(int age){
        this->age=age;
    }  
    void setScore(int score){
        if(score<0) this->score=0;
        else if(score>10) this->score=10;
        else this->score=score;
    }  
    void setName(string name){
        this->name=name;
    }  
    void setAddress(string address){
        this->address=address;
    }  
    int getId(){
        return id;
    }
    int getAge(){
        return age;
    }  
    int getScore(){
        return score;
    }  
    string getName(){
        return name;
    }  
    string getAddress(){
       return address;
    }  
};
int main() {
	Student s(1001, "Trung", 24, "Ha Noi", 5);
	cout << s.getId() << endl;;
	cout << s.getName() << endl;;
	cout << s.getAge() << endl;;
	cout << s.getAddress() << endl;;
	cout << s.getScore() << endl;;
	s.setScore(-7);
	cout << s.getScore() << endl;;
	s.setScore(15);
	cout << s.getScore() << endl;;
	return 0;
}