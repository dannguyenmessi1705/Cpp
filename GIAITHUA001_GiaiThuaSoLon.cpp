#include <iostream>
using namespace std;
#define MAX 500000
string Giai_thua[MAX]; // Khai bao string co kich thuoc la Val_size, phan tu chua Val_size so 0, Phai khia bao size cho string va phan tu truoc moi co the tra ve string duoc
// Ham tim giai thua
void GT(int n){
    int Val[MAX]; // Khoi tao Mang luu gia tri
    Val[0]=1; // Cho gia tri dau =1. GT = 1*2*3*...*N
    int Val_size=1; // gan do dai mang = 1, roi tang dan
    int bien_nho=0; // Gan gia tri nho = 0
    // Tinh giai thua
    for(int i=2; i<=n; i++){
        for(int j=0; j<Val_size; j++){
            int gt = Val[j] * i + bien_nho;
            Val[j] = gt%10; // Luu gia tri vao Val[]
            bien_nho = gt/10; // Lay gia tri nho
        }
        // Ham tang do dai
        while(bien_nho>0){
            int gt = bien_nho % 10;
            Val[Val_size] = gt;
            Val_size++;
            bien_nho/=10;
        }

        for(int k=Val_size-1; k>=0; k--){ 
            Giai_thua[i] += char(Val[k]+'0');
        }
    }
}
int main(){
    int test;
    GT(10000);
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        if(n==0 || n==1) cout<<1<<endl;
        else{
            cout<<Giai_thua[n]<<endl;
        }
    }
}