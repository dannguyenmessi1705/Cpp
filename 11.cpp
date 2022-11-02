#include <bits/stdc++.h>
using namespace std;
typedef struct HoTen{
  string name;
  int age;
} INFO;
int main(){
  INFO a;
  cout<<"Nhap ten: ";
  getline(cin, a.name);
  cout<<"Nhap tuoi: ";
  cin>>a.age;
  cout<<"Ten: "<<a.name<<"\nTuoi: "<<a.age;
}