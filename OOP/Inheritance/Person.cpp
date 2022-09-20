#pragma once // Tránh việc hàm cha được include nhiều lần gây ra lỗi
#include <iostream>
using namespace std;
class Person{
private:
    string name;
    int age;
    string address;
public:
    Person(){};
    Person(string name, int age, string address){
        this->address=address;
        this->age=age;
        this->name=name;
    }
    void setName(string name){
        this->name=name;
    }
    void setAge(int age){
        this->age=age;
    }
    void setAddress(string address){
        this->address=address;
    }
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    int getAge(){
        return age;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Address: "<<address<<endl;
    }
};

