// tao list gia tri chay tu 1 den n
#include <iostream>
#include <list>
#include <vector>
using namespace std;
list<int> CreatList(int n){
    list<int> a;
    for(int i=1;i<=n;i++){
        a.push_back(i);
    }
    return a;
}
vector<int> XuatList(int n){
    list<int> i = CreatList(n);
    vector<int> out(i.begin(), i.end());
    return out;
}
int main(){
    int n;
    cout<<"Nhap gia tri n: ";
    cin>>n;
    cout<<"List duoc tao: ";
    for(int i=0; i<XuatList(n).size(); i++){
        cout<<XuatList(n)[i]<<" ";
    }
    cout<<endl;
    system("pause");
}