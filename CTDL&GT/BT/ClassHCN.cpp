#include <iostream>
using namespace std;
class Rectangle{
    private:
        int width;
        int height;
    public:
        Rectangle(){};
        void set_values(int width, int height){
            this->width = width;
            this->height = height;
        }
        int area(){
            return width*height;
        }
};
int main(){
    Rectangle h1;
    int a, b;
    cin>>a>>b;
    h1.set_values(a, b);
    cout<<h1.area();
}