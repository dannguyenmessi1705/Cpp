#include <iostream>
using namespace std;
class Animal{
public:
    virtual void display(){ // thêm từ khóa virtual để gọi vào hàm con
        cout<<"Some sounds";
    }
};
class Dog : public Animal{
public:
    void display(){
        cout<<"Bow gow";
    }
};
class Cat : public Animal{
public:
    void display(){
        cout<<"Meow Meow";
    }
};
int main(){
    Dog dog1;
    Animal* animal1 = &dog1; //Up-casting
    animal1->display(); // Bow gow, nếu ko có từ khóa virtual ở class cha thì sẽ gọi đến Some Sounds
    Animal animal2;
    Cat* cat1 = (Cat*)&animal2; // Down casting
    cat1->display(); // Some Sounds, nếu ko có từ khóa virtual ở class cha thì sẽ gọi đến Meow Meow
    
}