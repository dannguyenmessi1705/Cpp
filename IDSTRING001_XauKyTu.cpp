#include <bits/stdc++.h>
using namespace std;
string chu,dau,sc,sp;
int main(){
    int test;
    cin>>test;
    cin.ignore();
    while(test--){
        cin>>chu>>dau>>sc>>chu>>dau>>sp; // eg: child = “ell”, parent = “hello”
        sc.pop_back(); // xoa dau "," o cuoi cua string children
        sc.pop_back(); // Xoa tiep dau " o cuoi string sc
        sc.erase(sc.begin()); // Xoa dau " o dau string sc
        // Tuong tu nhu string sc, ta co sp
        sp.pop_back(); 
        sp.erase(sp.begin());
        int lenC = sc.length();
        int lenP = sp.length();
        bool check = false;
        if(lenC == 0 || lenP == 0){
            cout<<"0"<<endl; // Xau rong in KQ la 0
            continue;;
        }
        for(int i=0;i<lenP-lenC;i++){ // Xet i chay tu 0 den do dai cua string pa - string chil
            if(sc[0]==sp[i]){ // bat vi tri ma co phan tu dau tien cua string con = string cha
                int pos = i;
                for(int j=1;j<lenC;j++){ // xet cac vi tri tiep theo cua string con, neu khac string cha thi pos ko co gia tri
                    if(sc[j]!=sp[i+j]){
                        pos=-1;
                        break;
                    }
                }
                if(pos>=0){ // Neu pos co gia tri >= 0 chung to string con co trong stirng cha
                    cout<<pos<<endl;
                    check=true;
                    break;
                }
            }
        }
        if(!check){ // Neu check false chung to string con khong ton tai trong string cha
            cout<<"-1"<<endl;
        }
    }
}