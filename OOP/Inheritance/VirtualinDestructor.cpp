#include <iostream>
using namespace std;
class SupClass{
public:
    virtual ~SupClass(){ // dùng từ khóa virtual ở destructor để sau khi giảI phóng bộ nhớ từ class cha, có thể kế thừa giải phónh cho class con
        cout<<"I'm SupClass\n";
    }
};
class BaseClass : public SupClass{
public:
    ~BaseClass(){
        cout<<"I'm BaseClass\n";
    }
};
int main(){
    SupClass* a = new BaseClass();
    delete a;
    return 0;
}
