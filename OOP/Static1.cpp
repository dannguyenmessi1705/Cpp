#include <iostream>
#include "Static.cpp" //nhap bien tu file Static.cpp cung duong dan
using namespace std;
class Math{
public:
    static int abs(int x){
        return x>=0?x:x*-1;
    }
    static int add(int x, int y){
        return x+y;
    }
    static int subtract(int x, int y){
        return x-y;
    }
    static int min(int x, int y){
        return x>=y?y:x;
    }    
    static int max(int x, int y){
        return x>=y?x:y;
    }
    static int pow(int x, int y){
        int kq=1;
        for(int i=1; i<=y; i++){
            kq*=x;
        }
        return kq;
    }
};
int main() {
	cout << Math::abs(-2) << endl;
	cout << Math::add(2, 3) << endl;
	cout << Math::subtract(2, 3) << endl;
	cout << Math::min(2, 3) << endl;
	cout << Math::max(2, 3) << endl;
	cout << Math::pow(2, 3) << endl;
    cout << Student::count; // nhap tu thu vien file static.cpp, ko dung int main() o doan sau nua thi chay duoc
	return 0;
}
