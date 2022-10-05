#include <bits/stdc++.h>
using namespace std;
string IP;
bool CheckIP(int x, int y){
    int sum = 0;
    if(y-x+1 > 3) return false; // Check tach doan neu lon hon 3
    if(IP[x]=='0'){ // Check neu co so 0 thi chi xet do dai cua no bang 1 tao thanh 1 doan moi thoa man, neu do dai >= 1 thi xet TH khac, vi du 012. == 12.
        if(y-x+1==1) return true;
        return false;
    }
    if(y-x+1 == 1 || y-x+1 == 2) return true; // Check tach doan neu co do dai la 1 hoac 2 thi coi nhu <=255
    sum = 100*(IP[x]-'0') + 10*(IP[x+1]-'0') + IP[x+2]-'0';
    if(sum>=0 && sum<=255) return true; // Check tach doan neu co do dai == 3, check xem tong doan co <= 255
    return false;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        int count = 0;
        cin>>IP;
        int len=IP.length();
        // tach thanh 4 doan roi check
        for(int i=0; i<len; i++){ 
            for(int j=i+1; j<len; j++){
                for(int k=j+1; k<len; k++){
                    // Tach doan dau toi i
                    // Tach doan i+1 toi j
                    // Tach doan j+1 toi k
                    // Tach doan k toi len-1
                    // Thanh A.B.C.D
                    if(CheckIP(0,i) && CheckIP(i+1,j) && CheckIP(j+1,k) && CheckIP(k+1,len-1))
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}