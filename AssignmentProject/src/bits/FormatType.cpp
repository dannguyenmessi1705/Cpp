#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef unsigned long long ll;

void TextColor(int x){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

int lenid, lenname, lenaddress, lenemail, lenphone, lenbill, lenrate;
void TimDoDai(int &lenid, int &lenname, int &lenaddress, int &lenemail, int &lenphone, int &lenrate, int &lenbill){
    ifstream FileIn; 
    FileIn.open("data.txt", ios::in);
    string line;
    getline(FileIn, line);
    if(line.length() == 0){ // File data rong
        lenid = 6;
        lenname = 25;
        lenaddress = 18;
        lenemail = 30;
        lenphone = 13;
        lenrate = 10;
        lenbill = 24;
    }
    else{
        lenid = 2; // Bang chieu dai "ID"
        for(int i=2;i<=line.length();i++) { // Bat dau tu sau tu "ID" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenid++;
        }
        lenname = 4; // Bang do dai "NAME"
        for(int i=lenid+lenname;i<=line.length();i++) { // Bat dau tu sau tu "NAME" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenname++;
        }
        lenaddress = 7; // Bang do dai "ADDRESS"
        for(int i=lenid + lenname + lenaddress;i<=line.length();i++) { // Bat dau tu sau tu "ADDRESS" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenaddress++;
        }
        lenemail = 5; // Bang do dai "EMAIL"
        for(int i=lenid + lenname + lenemail + lenaddress;i<=line.length();i++) { // Bat dau tu sau tu "EMAIL" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenemail++;
        }
        lenphone = 5; // Bang do dai "PHONE"
        for(int i=lenid + lenname + lenemail + lenphone + lenaddress;i<=line.length();i++) { // Bat dau tu sau tu "PHONE" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenphone++;
        }
        lenrate = 8; // Bang do dai "FEEDBACK"
        for(int i=lenid + lenname + lenemail + lenphone + lenaddress + lenrate;i<=line.length();i++) { // Bat dau tu sau tu "RATE" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenrate++;
        }
        lenbill = 4; // Bang do dai "BILL"
        for(int i=lenid + lenname + lenemail + lenphone + lenaddress + lenrate + lenbill;i<=line.length();i++) { // Bat dau tu sau tu "BILL" de tim khoang trong do dai
            if(line[i] != ' ') break;
            else lenbill++;
        }
    }
    FileIn.close();
}
ll Pow(int a, int b){
    ll kq = 1;
    for(int i=1; i<=b; i++){
        kq *= a;
    }
    return kq;
}

string TachDonVi(ll bill){
	string tmp = "";
	string num = to_string(bill);
	int count = 0;
    int dem = 0;
	for (int i = num.length() - 1; i >= 0; i--) {
		count++;
		tmp.push_back(num[i]);
		if (count == 3 && dem < 3) {
			tmp.push_back('.');
			count = 0;
            dem++;
		}
	}
	reverse(tmp.begin(), tmp.end());
	if (tmp.size() % 4 == 0) {
		tmp.erase(tmp.begin());
	}
	return tmp + " VND";
}
string TachDonVi(string money){
    string tmp = "";
	int count = 0; // dem do dai string de ngan cach
    int dem = 0; // dung de dem so cham ".", phong truong hop khi len den hang ty thi khong can cham nua
	for (int i = money.length() - 1; i >= 0; i--) {
		count++;
		tmp.push_back(money[i]);
		if (count == 3 && dem < 3) {
			tmp.push_back('.');
			count = 0;
            dem++;
		}
	}
	reverse(tmp.begin(), tmp.end());
	if (tmp.size() % 4 == 0) {
		tmp.erase(tmp.begin());
	}
	return tmp + " VND";
}