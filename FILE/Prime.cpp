#include <iostream>
#include <fstream>
using namespace std;
int Check(int n){
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    ifstream FileIn; // Khai bao FileIn trong class ifstream để đọc file
    FileIn.open("INPUT.txt", ios_base::in); // Mở đường dẫn, chế độ đọc
    if(FileIn.fail()){ // check xem có tồn tại file ko
        cout<<"Khong co file nao";
        return 0;
    }
    int n;
    ofstream FileOut; // Khai báo FileOut trong class ofstream đề ghi file
    FileOut.open("OUTPUT.txt", ios_base::out); //Mở đường dẫn, chế độ ghi
    while(!FileIn.eof()){ //Kiểm tra xem đã đọc đến cuối dòng file chưa
        FileIn>>n; // Nhập DL từ file vào CT
        if(Check(n)==1) {
        FileOut<<n<<" la so nguyen to\n";
        }
        else FileOut<<n<<" khong phai la so nguyen to\n";
        }
    FileIn.close();
    FileOut.close();
}