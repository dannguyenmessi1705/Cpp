#include <iostream>
using namespace std;
const float pi = 3.14;
class Circle{
    private:
    double radius;
    public:
    Circle(double radius){
        this->radius=radius;
    }
    double getArea(){
        return radius*radius*pi;
    }
    double getCircumference(){
        return radius*2*pi;
    }
};
int main(){
    Circle c(3);
    std::cout<<c.getArea()<<endl<<c.getCircumference();
}