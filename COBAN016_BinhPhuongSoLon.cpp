#include <iostream>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        for(int i=1;i<=(n-1)/9;i++){ //Lay thuan
                                    // Ke tu  n>9 quy luat se thay doi, khong co so 8 o ve dau va se co 2 so 0 o giua
            cout<<"123456790";
        }
        int k=(n-1)%9; // lay so du de biet so se nhay len chu so nao
        for(int i=1;i<=k;i++){ // Lay thuan tu 1->k
            cout<<(char)('0'+i);
        }
        for(int i=k+1;i>=2;i--){ // Lay nghich tu k->i
            cout<<(char)('0'+i);
        }
        for(int i=1;i<=(n-1)/9;i++){
            cout<<"098765432"; // Lay nghich, 2 so 0 o giua theo quy luat moi khi n>9
        }
        cout<<"1";
        cout<<endl;
    }
    
}
