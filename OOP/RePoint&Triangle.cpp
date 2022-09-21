#include <iostream>
#include <math.h>
using namespace std;
class Point{
private:
    int x;
    int y;
public:
    Point(){};
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
    void setX(int x){
        this->x=x;
    }
    void setY(int y){
        this->y=y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};
class Triangle{
private:
    Point point1;
    Point point2;
    Point point3;
public:
    Triangle(Point point1, Point point2, Point point3){
        this->point1=point1;
        this->point2=point2;
        this->point3=point3;
    }
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
        this->point1=Point(x1, y1);
        this->point2=Point(x2, y2);
        this->point3=Point(x3, y3);
    }
    void setPoint1(Point point1){
        this->point1=point1;
    }
    void setPoint2(Point point2){
        this->point2=point2;
    }
    void setPoint3(Point point3){
        this->point3=point3;
    }
    Point getPoint1(){
        return point1;
    }
    Point getPoint2(){
        return point2;
    }
    Point getPoint3(){
        return point3;
    }
    double getPerimeter(){
        double l12 = sqrt(pow(point1.getX()-point2.getX(), 2) + pow(point1.getY()-point2.getY(), 2));
        double l23 = sqrt(pow(point2.getX()-point3.getX(), 2) + pow(point2.getY()-point3.getY(), 2));
        double l31 = sqrt(pow(point3.getX()-point1.getX(), 2) + pow(point3.getY()-point1.getY(), 2));
        return l12+l23+l31;
    }
};
int main(){
    Point point1(1,3);
    Point point2(2,3);
    Point point3(4,2);
    Triangle t1(point1, point2, point3);
    cout<<t1.getPerimeter()<<endl;
}