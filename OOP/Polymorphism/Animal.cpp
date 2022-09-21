#include <iostream>
using namespace std;
class Animal{
public:
    virtual void display(){
        cout<<"some sounds\n";
    }
};
class Dog : public Animal {
public:
    void display(){
        cout<<"bow gow\n";
    }
};
class Cat : public Animal {
public:
    void display(){
        cout<<"meow meow\n";
    }
};
class Duck : public Animal {
public:
    void display(){
        cout<<"quack quack\n";
    }
};
int main(){
    Animal* a[4];
    a[0] = new Animal();
    a[1] = new Dog();
    a[2] = new Cat();
    a[3] = new Duck();
    for(int i=0;i<4;i++){
        a[i]->display();
    }
}