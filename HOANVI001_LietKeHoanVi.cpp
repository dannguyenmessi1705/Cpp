#include <iostream>
using namespace std;
#define MAX 20
int a[MAX];
int test, n;
void swap(int &a, int&b){
    int tmp = a;
    a = b;
    b = tmp;
}
// Ham Xuat hoan vi dau tien
// VD n=3; => 1 2 3 4
void KhoiTaoHoanViDau(int a[], int n){
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
}
// Ham Sap xep tang dan tai vi tri thu i
void SapXepTang(int a[], int n, int pos){
    for(int i=pos;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

// Ham Xuatmang
void Xuat(int a[], int n){
    for(int i=1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cin>>test;
    while(test--){      
        cin>>n;
        KhoiTaoHoanViDau(a, n);
        Xuat(a, n);
        while(1){
            int pos; // Bien xac dinh vi tri la diem dung tang
            int check = 0; // Bien xac dinh da liet ke xong het chua
            for(int i=n; i>=1; i--){ 
                // Neu i=1 thi thoat vong lap, vi da liet ke het hoan vi, VD 3 2 1 thi do dung mang nen a[0] = 0 => nen phai dat cau lenh if nay truoc cau lenh if so sanh o duoi
                // VD n=4; => Hoan vi cuoi cung 1 2 3 4 lap lai hoan vi dau, khong thoa man dieu kien o tren
                // => thoat vong lap
                if(i == 1){
                    check = 1;
                    break;
                }
                // Xet tu vi tri cuoi tro ve de xac dinh diem dung tang
                // VD 1 2 4 3 thi diem dung tang se la vi tri co gia tri la 4 => pos = i = 3
                // VD2 1 2 3 thi diem dung tang la 3, vi tu 3->2 no bat dau giam
                if(a[i-1] < a[i]){
                    pos = i;
                    break;
                }
            }
            if(check == 1) break;
            for(int j=n; j>=pos; j--){
                // Tim gia tri min tu vi tri pos tro di so sanh voi gia tri o pos-1
                // VD: 1 2 4 3, tu vi tri pos(3) = 4 tro di thi so cuoi la 3 da la min, so sanh voi pos-1(3) co gia tri la 2
                // 3 > 2 => swap => 1 3 4 2
                if(a[j] > a[pos-1]){
                    swap(a[j], a[pos-1]);
                    SapXepTang(a, n, pos); // Tu vi tri pos(3) = 4, ta sap xep tang duoc hoan vi 1 3 2 4
                    Xuat(a, n);
                    break; // bat dau tim 1 cau hinh moi
                }
            }
 
        }

    }
}