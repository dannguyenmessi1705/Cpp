/*
Giả sử X là phần tử đang xét trong biểu thức trung tổ, ta có các trường hợp sau:
1.	Nếu X là toán hạng (số hoặc biển) thì  Push X vào trong QUEUE
2.	Nếu X là dấu mở ngoặc ( thì PUSH X vào trong STACK
3.	Nếu X là dấu đóng ngoặc ) thì...ta lấy các phần tử trong STACK ra và Push vào trong QUEUE, cho đến khi gặp ký tự mở ngoặc “(" thì dừng. Sau đó loại bỏ luôn ký tự mở ngoặc ( đó khỏi STACK.
4.	Nếu X là toán tử thì... 
    A.  STACK đang rỗng thì...  Push X vào trong STACK
    B.   STACK đang có phần tử thì ...

        a.	 Phần tử đầu STACK không phải là toán từ thì... > Push X vào trong STACK    
        b.	 Phần tử đầu STACK là toán tử thì...kiểm tra độ ưu tiên toán tử như sau: (VD: Dấu “x, :” lớn hơn “+, -“ 
            +) Toán từ đầu STACK < X Push X vào trong STACK
            +) Toán từ đầu STACK >= X
                BƯỚC 1: Kiểm tra toán từ đầu STACK X
                        Lấy phần tử đầu STACK Push vào trong QUEUE 
                BƯỚC 2: Quay lên BƯỚC 1 cho đến khi ... 
                        STACK rỗng thì dừng 
                        Đến Khi gặp phần tử nhỏ hơn X thì dừng (VD: X là phép '*' gặp phần tử '+' nhỏ hơn sẽ dừng)
                        Phần từ đầu STACK hiện tại không phải là toán tử nữa thì dừng 
            	Sau đó Push X vào trong STACK

5.	Sau khi duyệt qua hết các phân tử trong biểu thức trung tổ, nếu STACK còn phần từ thì Push hết sang QUEUE và kết thúc.

*/
#include <iostream>
using namespace std;
#define ToanTu xau[i] == 42 || xau[i] == 43 || xau[i] == 45 || xau[i] == 47
#define NotToanTu s.pTop->data != 42 && s.pTop->data != 43 && s.pTop->data != 45 && s.pTop->data != 47

// Khai bao cau truc NODE
struct Node{
    char data; // bien luu ky tu Ba Lan sau khi nhap tu xau
    float KQ;   // Bien luu KQ sau khi tinh toan tu ky tu Ba Lan
    struct Node *pNext; // Con tro quan ly cac Node
}typedef NODE;

// Khai bao cau truc Queue, Dung de luu ky tu Ba Lan
struct Queue{
    NODE *pHead; // Con tro quan ly dau Queue
    NODE *pTail; // Con tro quan ly cuoi Queue
}typedef QUEUE;

// Khai bao cau truc Stack, Dung de luu ky tu Ba Lan va KQ cuoi cung cua phep tinh
struct Stack{
    NODE *pTop; // Con tro quan ly dau Stack
}typedef STACK;

// Khoi tao Stack, ban dau Stack rong
void KhoiTaoListStack(STACK &s){
    s.pTop = NULL; 
}

// Khoi tao Queue, ban dau Queue rong
void KhoiTaoListQueue(QUEUE &q){
    q.pHead = NULL;
    q.pTail = NULL;
}

// Khoi tao Node cho bien char
NODE *KhoiTaoNode(char x){
    NODE *p = new NODE();
    // Neu khong cap phat thanh cong
    if(p == NULL){ 
        return NULL;
    }
    p->data = x; // Truyen gia tri x vao data cua con tro p
    p->pNext = NULL; // Vi chua co lien ket nen con tro tiep theo cua p tro toi NULL
}
NODE *KhoiTaoNode(float x){
    NODE *p = new NODE();
    // Neu khong cap phat thanh cong
    if(p == NULL){ 
        return NULL;
    }
    p->KQ = x; // Truyen gia tri x vao KQ cua con tro p
    p->pNext = NULL; // Vi chua co lien ket nen con tro tiep theo cua p tro toi NULL
}

// Ham kiem tra DS co rong hay khong
bool IsEmpty(STACK &s){
    if(s.pTop == NULL) return true;
    else return false;
}

bool IsEmpty(QUEUE &q){
    if(q.pHead == NULL) return true;
    else return false;
}

// Ham Push vao dau Stack - theo co che LIFO (Last In First Out)
bool PUSH(STACK &s, char x){
    NODE *p = new NODE();
    if(p == NULL){
        return false;
    }
    p = KhoiTaoNode(x);
    if(IsEmpty(s)){
        s.pTop = p;
    }
    else{
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}
bool PUSH(STACK &s, float x){
    NODE *p = new NODE();
    if(p == NULL){
        return false;
    }
    p = KhoiTaoNode(x);
    if(IsEmpty(s)){
        s.pTop = p;
    }
    else{
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}

// Ham Push vao cuoi QUeue, theo co che FIFO (First In First Out)
bool PUSH(QUEUE &q, char x){
    NODE *p = new NODE();
    if(p == NULL){
        return false;
    }
    p = KhoiTaoNode(x);
    if(IsEmpty(q)){
        q.pHead = q.pTail = p;;
    }
    else{
        q.pTail->pNext = p;
        q.pTail = p;
    }
    return true;
}

// Ham lay gia tri dau tien cua Stack, dong thoi xoa no di(LIFO)
bool POP(STACK &s, char &value){
    if(IsEmpty(s)){
        return false;
    }
    value = s.pTop->data;
    NODE *tmp = s.pTop;
    s.pTop = s.pTop->pNext;
    delete tmp;
}
bool POP(STACK &s, float &value){
    if(IsEmpty(s)){
        return false;
    }
    value = s.pTop->KQ;
    NODE *tmp = s.pTop;
    s.pTop = s.pTop->pNext;
    delete tmp;
}

// Ham lay gia tri dau cua Queue, dong thoi xoa no di(FIFO)
bool POP(QUEUE &q, char &value){
    if(IsEmpty(q)){
        return false;
    }
    value = q.pHead->data;
    NODE *tmp = q.pHead;
    q.pHead = q.pHead->pNext;
    delete tmp;
}

// Ham lay gia tri dau cua Stack 
bool TOP(STACK s, char &value){
    if(IsEmpty(s)){
        return false;
    }
    value = s.pTop->data;
}
bool TOP(STACK s, float &value){
    if(IsEmpty(s)){
        return false;
    }
    value = s.pTop->KQ;
}

// Ham lay gia tri dau tien cua Queue
bool TOP(QUEUE q, char &value){
    if(IsEmpty(q)){
        return false;
    }
    value = q.pHead->data;
}
// -----------HAM CHUYEN BIEU THUC TRUNG TO SANG BIEU THUC HAU TO----------------
// BIEU THUC HAU TO SE LUU VAO QUEUE

// Ham kiem tra Toan Hang
bool ToanHang(char x){
    if(x >= '0' && x <= '9')
        return true;
    else return false;
}

// Ham Kiem tra toan tu cua xau
bool CheckToanTuChar(char x){
    if(x == 42 || x == 43 || x == 45 || x == 47) return true;
    else return false;
}

// Ham kiem tra toan tu dau Stack
bool CheckToanTuStack(STACK s){
    if(IsEmpty(s)) return false;
    else if(s.pTop->data == 42 || s.pTop->data == 43 || s.pTop->data == 45 || s.pTop->data == 47) return true;
    else return false;
}

// Ham kiem tra toan tu xau X co lon hon toan tu o dau Stack hay khong
bool CheckToanTuX_LonHonToanTuDauStack(STACK s, char x){
    if((x == '*' || x == '/') && (s.pTop->data == '+' || s.pTop->data == '-'))
        return true;
    else return false;
}

void ConvertTrungTo_HauTo(STACK &s, QUEUE &q, string xau){
    int len = xau.length();
    for(int i=0; i<len; i++){
        // Kiem tra Toan Hang 
        if(ToanHang(xau[i])){
            PUSH(q, xau[i]);
            continue;
        }
        // Kiem tra dau mo ngoac
        if(xau[i] == 40){ // Dau "("
            PUSH(s, xau[i]);
            continue;
        }
        // Kiem tra dau dong ngoac
        if(xau[i] == 41){ // Dau")"
            char value;
            while(s.pTop->data != 40){ // Gap ky tu "(" thi dung
                POP(s, value);
                PUSH(q, value);
            }
            POP(s, value);
            continue;
        }
        // Kiem tra Toan tu
        if(CheckToanTuChar(xau[i])){ // Dau"+, -, *, /"
            if(IsEmpty(s))  
                PUSH(s, xau[i]);
            else if(!CheckToanTuStack(s))
                PUSH(s, xau[i]);
            else{
                if(CheckToanTuX_LonHonToanTuDauStack(s, xau[i]))
                    PUSH(s, xau[i]);
                else{
                    char value;
                    while(POP(s, value) == true){
                        PUSH(q, value);
                        char tmp = value;
                        TOP(s, value);
                        if((ToanHang(value)) || value == 40 || value == 41 || ((tmp == '*' || tmp == '/') && (value == '+' || value == '-')))
                            break;
                    }
                    PUSH(s, xau[i]); 
                }
            }
            continue;
            
        }
    }
    // Neu Stack van con phan tu, Push het vao Queue
    while(IsEmpty(s) == false){
        char value;
        POP(s, value);
        PUSH(q, value);
    }
}

// Ham Xuat Bieu thuc Hau to
void Xuat(QUEUE q){
    for(NODE *k = q.pHead; k != NULL; k = k->pNext){
        cout<<k->data;
    }
}

// ----------HAM TINH TOAN BIEU THUC HAU TO (CO CHE TINH TOAN CUA MAY TINH)---------------
// KET QUA(SO CUOI CUNG) SE LA SO CUOI CUNG TRONG STACK
/* 
    Từ Queue, ta Push từng toán hạng vào Stack cho đến khi phần tử đầu tiên của Queue là toán tử thì dừng
    Lúc đó ta sẽ lấy 2 toán hạng đầu tiên của Stack ra rồi thực hiện phép tính với toán tử đó theo trật tự stack2 +-/* stack1
    KQ thu được ta lại Push tiếp vào Stack, cứ làm vậy cho đến Queue rỗng, trong Stack còn 1 phần tử duy nhất, ta thu được KQ 
*/

void Calculate(STACK &s, QUEUE &q){
    while(!IsEmpty(q)){
        char value;
        POP(q, value);
        if(ToanHang(value)){
            float x = (value - '0');
            PUSH(s, x);
            continue;
        }
        else{
            float a, b, c;
            POP(s, a);
            POP(s, b);
            if(value == '*')
                c = b * a;
            else if(value == '/')
                c = b / a;
            else if(value == '-')
                c = b - a;
            else
                c = b + a;
            PUSH(s, c);
            continue;
        }
    }
}

int main(){
    STACK s;
    KhoiTaoListStack(s);
    QUEUE q;
    KhoiTaoListQueue(q);
    string xau;
    cout<<"Nhap phep tinh trung to: ";
    cin>>xau;
    ConvertTrungTo_HauTo(s, q, xau);
    cout<<"Bieu thuc hau to: ";
    Xuat(q);
    Calculate(s, q);
    float KQ;
    TOP(s, KQ);
    if((int)KQ == KQ) KQ = (int)KQ;
    cout<<"\nKet qua cua phep tinh: "<<xau<<" = "<<KQ;
}
