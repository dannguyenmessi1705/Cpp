#include <iostream>
using namespace std;
class Rectangle{
private:
    double length;
    double width;
public:
    Rectangle(){};
    Rectangle(double length, double width){
        this->length=length;
        this->width=width;
    }
    void setLength(double length){
        this->length=length;
    }
    void setWidth(double width){
        this->width=width;
    }  
    double getLength(){
        return length;
    }
    double getWidth(){
        return width;
    }
    double getArea(){
        return length*width;
    }
    double getPerimeter(){
        return (length+width)*2;
    }
};
int main() {
	Rectangle r(4, 5);
	cout << "Area: " << r.getArea() << endl;
	cout << "Perimeter: " << r.getPerimeter() << endl;
	r.setLength(2);
	r.setWidth(3);
	cout << "Area: " << r.getArea() << endl;
	cout << "Perimeter: " << r.getPerimeter() << endl;
	return 0;
}