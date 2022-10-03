#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> b1;
    for(int i=0;i<=5;i++){
        b1.push_back(i);
    }
    vector<int>::iterator it; //Khai bao iterator
    for(it = b1.begin(); it != b1.end(); it++){ //duyet vi tri cua iterator tu dau toi cuoi
        cout<<*it<<" "; 
    }
    cout<<endl;
    vector<int>::reverse_iterator rit; //Khai bao 1 iterator dao
    for(rit = b1.rbegin(); rit != b1.rend(); rit++){ //duyet vi tri cua iterator dao nguoc tu cuoi ve dau, phai dung voi iterator dao
        cout<<*rit<<" "; 
    }
    cout<<endl;
    vector<string> b2;
    string s;
    vector<string>::iterator si;
    for(int i=0;i<3;i++){
        cin>>s;
        b2.push_back(s);
    }
    for(int i=0; i < b2.size(); i++){
        cout<<b2[i].size(); // in size tung phan tu trong vector string
    }
    cout<<endl;
}