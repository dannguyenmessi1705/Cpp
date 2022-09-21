#include <iostream>
using namespace std;
const float PI = 3.14;
class Shape{
public:
    virtual double getArea()=0; // Phương thức trừu tượng, không thể 
                                // gọi từ class cha, class con kế thừa bắt buộc phải có
    virtual double getPerimeter()=0;
};
class Rectangle : public Shape{
private:
    double length;
    double width;
public:
    Rectangle(double length, double width){
        this->length=length;
        this->width=width;
    }
    double getArea(){ // Bắt buộc phải có phương thức này từ class con để giống class cha
        return length*width;
    }
    double getPerimeter(){ // Bắt buộc phải có phương thức này từ class con để giống class cha
        return (length+width)*2;
    }
};
class Circle : public Shape{
private:
    double radius;
public:
    Circle(double radius){
        this->radius=radius;
    }
    double getArea(){ // Bắt buộc phải có phương thức này từ class con để giống class cha
        return PI * radius * radius;
    }
    double getPerimeter(){ // Bắt buộc phải có phương thức này từ class con để giống class cha
        return radius * 2 * PI;
    }
};
int main(){
    Shape* shape[3];
    shape[0] = new Rectangle(4, 6);
    shape[1] = new Circle(5);
    shape[2] = new Rectangle(1, 2);
    for(int i=0;i<3;i++){
        cout<<"Area: "<<shape[i]->getArea()<<endl;
        cout<<"Perimeter: "<<shape[i]->getPerimeter()<<endl;
    }
}