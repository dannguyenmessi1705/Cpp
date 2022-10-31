#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
class Customer{
private:
    string name;
    string address;
    string email;
    string phone;
    string service;
    ll bill;
public:
    Customer(){};
    Customer(string name, string address, string email, string phone, string service, ll bill){
        this->name = name;
        this->address = address;
        this->email = email;
        this->phone = phone;
        this->service = service;
        this->bill = bill;
    }
    void setName(string name);
    string getName();
    void setAddress(string adddress);
    string getAddress();
    void setEmail(string email);
    string getEmail();
    void setPhone(string phone);
    string getPhone();
    void setService(string service);
    string getService();
    void setBill(ll bill);
    ll getBill();

};
void Customer::setName(string name){
    this->name = name;
}
string Customer::getName(){
    return name;
}
void Customer::setAddress(string address){
    this->address = address;
}
string Customer::getAddress(){
    return address;
}
void Customer::setEmail(string email){
    this->email = email;
}
string Customer::getEmail(){
    return email;
}
void Customer::setPhone(string phone){
    this->phone = phone;
}
string Customer::getPhone(){
    return phone;
}
void Customer::setService(string service){
    this->service = service;
}
string Customer::getService(){
    return service;
}
void Customer::setBill(ll bill){
    this->bill = bill;
}
ll Customer::getBill(){
    return bill;
}
void Nhap(Customer &x){
    cin.ignore();
    string name;
    getline(cin, name);
    x.setName(name);
}
void Them(ofstream &FileOut, Customer &x){
        int id=0;

    // Customer x("Di Dan", "Hung Yen", "messipro", "034655", "FPT", 30000);

    FileOut<<setw(4)<<left<<"ID";
    FileOut<<setw(30)<<left<<"NAME";
    FileOut<<setw(30)<<left<<"ADDRESS";
    FileOut<<setw(30)<<left<<"EMAIL";
    FileOut<<setw(14)<<left<<"PHONE";
    FileOut<<setw(60)<<left<<"SERVICE";
    FileOut<<setw(12)<<left<<"BILL";
    FileOut<<" "<<endl;
        FileOut<<setw(4)<<left<<++id;
        FileOut<<setw(30)<<left<<x.getName();
        // FileOut<<setw(30)<<left<<x.getAddress();
        // FileOut<<setw(30)<<left<<x.getEmail();
        // FileOut<<setw(14)<<left<<x.getPhone();
        // FileOut<<setw(60)<<left<<x.getService();
        // FileOut<<setw(12)<<left<<x.getBill();
}
ifstream FileIn;
ofstream FileOut;
Menu(){
            FileOut.open("0.txt", ios::out);
    Customer x;
    Nhap(x);
    Them(FileOut, x);
}
int main(){

        Menu();
}