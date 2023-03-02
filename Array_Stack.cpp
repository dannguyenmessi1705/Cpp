#include <bits/stdc++.h>
using namespace std;
class STACK
{
private:
    int size;
    int top;
    int *Data;

public:
    STACK(){};
    void KhoiTao(int size);
    bool IsEmpty();
    bool IsFull();
    void Push(int &value);
    bool Pop(int &value);
    bool Top(int &value);
    void Output();
    void Delete();
};

void STACK::KhoiTao(int size)
{
    this->size = size;    // Khoi tao size cho STACK
    Data = new int[size]; // Cap phat mang
    this->top = -1;       // Khai bao chi so dau tien cua STACK dang rong la -1
}
bool STACK::IsEmpty()
{
    if (top == -1)
    {
        return true; // Neu chi so ngan xep dau tien cua STACK la -1 thi STACK rong
    }
    return false;
}

bool STACK::IsFull()
{
    if (top >= size - 1)
    {
        return true; // Neu chi so cua STACK bang size - 1 thi STACK da day
    }
    return false;
}
void STACK::Push(int &value)
{
    if (IsFull())
    {
        return; // Neu STACK da day thi khong the them
    }
    // Nguoc lai
    top++;             // Tang chi so STACK len
    Data[top] = value; // Gan vi tri tang len = value
}

bool STACK::Pop(int &value)
{
    if (IsEmpty())
    {
        return false; // Neu STACK rong thi ko the lay duoc gia tri
    }
    // Nguoc lai
    value = Data[top]; // Cho gia tri value bang gia tri cua Ngan xep o vi tri dinh top
    top--;             // Giam chi so cua STACK di
    return true;       // Tra ve kq true vi STACK ko rong, co the lay duoc gia tri o top
}
bool STACK::Top(int &value)
{
    if (IsEmpty())
    {
        return false; // Neu STACK rong thi ko the lay duoc gia tri
    }
    value = Data[top]; // Cho gia tri value bang gia tri cua Ngan xep o vi tri dinh top
    return true;       // Tra ve kq true vi STACK ko rong, co the lay duoc gia tri o top
}
void STACK::Output()
{
    if (IsEmpty())
    {
        return; // Neu STACK rong => thoat
    }
    while (!(IsEmpty()))
    {
        cout << Data[top] << " "; // In ra gia tri o dinh STACk
        top--;                    // Giam chi so cua dinh STACK
    }
}
void STACK::Delete()
{
    delete[] Data; // Xoa cap phat mang dong
}

void MENU(STACK s)
{
    string choice;
    while (1)
    {
        system("cls");
        cout << "\t\t===========================MENU=============================";
        cout << "\n\t\t|                MOI BAN NHAP TUY CHON                     |";
        cout << "\n\t\t|       1. Xuat STACK ra man hinh                          |";
        cout << "\n\t\t|       2. Them gia tri vao STACK                          |";
        cout << "\n\t\t|       3. Lay phan tu dau STACK dong thoi xoa di (Push)   |";
        cout << "\n\t\t|       4. Lay phan tu dau STACK va khong xoa (Top)        |";
        cout << "\n\t\t|       5. Kiem tra STACK co rong hay khong                |";
        cout << "\n\t\t|       6. Kiem tra STACK da day hay chua                  |";
        cout << "\n\t\t|       0. Thoat Menu va Xoa bo nho STACK                  |";
        cout << "\n\t\t============================================================";

        cout << "\n\t\tNhap lua chon: ";
        cin >> choice;
        if (choice == "0")
        {
            cout << "\t\tNhan ENTER de thoat\n\t\t";
            s.Delete();
            system("pause");
            return;
        }
        else if (choice == "1")
        {
            if (!s.IsEmpty())
            {
                cout << "\t\tCac phan tu trong STACK: ";
                s.Output();
                cout << "\n\t\t";
            }
            else
            {
                cout << "\t\tSTACK dang rong\n\t\t";
            }
            system("pause");
        }
        else if (choice == "2")
        {
            if (s.IsFull())
            {
                cout << "\t\tSTACK da day, khong the them!\n\t\t";
                system("pause");
                continue;
            }
            int value;
            cout << "\t\tNhap gia tri muon them vao STACK: ";
            cin >> value;
            s.Push(value);
        }
        else if (choice == "3")
        {
            int value;
            if (!s.Pop(value))
            {
                cout << "\t\tSTACK dang rong!\n\t\t";
                system("pause");
            }
            else
            {
                cout << "\t\tPhan tu o dinh STACK la: " << value << "\n\t\t";
                system("pause");
            }
        }
        else if (choice == "4")
        {
            int value;
            if (!s.Top(value))
            {
                cout << "\t\tSTACK dang rong!\n\t\t";
                system("pause");
            }
            else
            {
                cout << "\t\tPhan tu o dinh STACK la: " << value << "\n\t\t";
                system("pause");
            }
        }
        else if (choice == "5")
        {
            if (s.IsEmpty())
            {
                cout << "\t\tSTACK dang rong\n\t\t";
                system("pause");
            }
            else
            {
                cout << "\t\tSTACK dang chua phan tu\n\t\t";
                system("pause");
            }
        }
        else if (choice == "6")
        {
            if (s.IsFull())
            {
                cout << "\t\tSTACK da day\n\t\t";
                system("pause");
            }
            else
            {
                cout << "\t\tSTACK chua day\n\t\t";
                system("pause");
            }
        }
        else
        {
            cout << "\t\tBan da nhap sai cu phap\n\t\t";
            system("pause");
        }
    }
}

int main()
{
    STACK s;
    int size;
    cout << "\t\tNhap kich thuoc cho STACK: ";
    cin >> size;
    s.KhoiTao(size);
    MENU(s);
}