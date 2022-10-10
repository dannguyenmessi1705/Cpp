#include <iostream>
using namespace std;
typedef unsigned long long lli;
// Ham check xem giai thua cua 1 so co chua it nhat 1 so 0 o cuoi hay khong
bool Check_Last_FacNumber(lli number, lli n){
    lli count=0;
    for(lli fac=5;number/fac >= 1;fac*=5){ // Ham dem so chu so 0 o cuoi cua 1 giai thua 
                                        // Bang cach chia lien tuc cho luy thua cua 5
        count+= number/fac;
    }
    return (count>=n); // Ket qua giai thua cua so co n chu so phai co so chu so 0 >= n thi moi thoa man
                       // ket qua giai thua cua so do co it nhat 1 chu so 0 o cuoi
                                    
}
// Ham tim giai thua nho nhat co n chu so, co it nhat 1 so 0 o cuoi
// Tim kiem nhi phan
lli FindNum(lli n){
    if(n==1){ // Neu n=1, return kq la 5
        return 5;
    }
    lli low=0, high=n*5; // KQ giai thua cua 1 so co n chu so se chi chua cac chu so <= 5*n
    while(low<high){
        lli mid = (low+high) >> 1; // (low + high) / 2^1; (Xet gia tri o mid truoc)
        if(Check_Last_FacNumber(mid, n)){ // Neu mid chinh la so co giai thua chua it nhat 1 so 0 o cuoi thi thu gon lai
                                          // viec tim kiem bang cach cho high = mid
            high=mid;
        }
        else{ // Nguoc lai tu low den mid se ko co so nao, thu hep lai ket qua bang cach cho low = mid+1;
            low=mid+1;
        }
    }
    return low; // Cuoi cung se tra ket giai thua be nhat chinh la low
}
int main(){
    lli test, n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<FindNum(n)<<endl;
    }
}