#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int rem, t;
    long long dec;
    char bin[1000];
    cin>>t;
    while(t--){
        cin>>dec;
        long long i=0;
        while(dec>0){
            rem=dec%2;
            bin[i]=rem+48;
            dec/=2;
            i++;
        }
        int len=i;
        for(int i=len-1;i>=0;i--){
            if(bin[i]=='0'){
                bin[i]=0;
                len--;
            }
            else break;
        }
        for(int i=len-1;i>=0;i--) cout<<bin[i];
        cout<<"\n";
    }
}