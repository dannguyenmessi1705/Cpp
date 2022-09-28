#include "statistics.h"
using namespace std;
int main(){
    float a, b, c, d;
    int n;
    cout<<"So chu so can nhap: ";
    cin>>n;
    switch (n){
    case 1:
        cout<<"a = ";
        cin>>a;
        cout<<"TB: "<<mean(a)<<"\n";
        cout<<"PS: "<<variance(a);
        break;
    case 2:
        cout<<"a = ";
        cin>>a;
        cout<<"b = ";
        cin>>b;
        cout<<"TB: "<<mean(a, b)<<"\n";
        cout<<"PS: "<<variance(a, b);
        break;
    case 3:
        cout<<"a = ";
        cin>>a;
        cout<<"b = ";
        cin>>b;
        cout<<"c = ";
        cin>>c;
        cout<<"TB: "<<mean(a, b, c)<<"\n";
        cout<<"PS: "<<variance(a, b, c);
        break;
    case 4:
        cout<<"a = ";
        cin>>a;
        cout<<"b = ";
        cin>>b;
        cout<<"c = ";
        cin>>c;
        cout<<"d = ";
        cin>>d;
        cout<<"TB: "<<mean(a, b, c, d)<<"\n";
        cout<<"PS: "<<variance(a, b, c, d);
        break;
    
    default:
        cout<<"Nhap n nho hon hoac bang 4";
        break;
    }

}