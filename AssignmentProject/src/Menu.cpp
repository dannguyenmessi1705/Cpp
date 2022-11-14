#include "Object.h"
#include "ManagerData.h"
#include "ReadData.h"
#include "SearchData.h"
#include "Statitic.h"
#include "SortData.h"
//===============MENU==================
void MENU(LIST l){
    string choice;
    while(1){ // Lap vo han
        system("cls"); // Xoa man hinh de khong hien thi lai Menu nua
        cout<<"\t\t===========================MENU=============================";
        cout<<"\n\t\t|                MOI BAN NHAP TUY CHON                     |";
        cout<<"\n\t\t| 1. Xuat Danh Sach Khach hang tu FILE ra man hinh         |";
        cout<<"\n\t\t| 2. Them Thong tin Khach hang vao FILE                    |";
        cout<<"\n\t\t| 3. Tim kiem Thong tin Khach hang tu FILE va Chinh sua    |";
        cout<<"\n\t\t| 4. Sap xep lai thong tin Khach hang                      |";
        cout<<"\n\t\t| 5. Thong ke cac chi so trong danh sach                   |";
        cout<<"\n\t\t| 0. Thoat Menu va Xoa bo nho danh sach                    |";
        cout<<"\n\t\t============================================================";

        cout<<"\n\t\tNhap lua chon: ";
        cin>>choice;
        if(choice == "0"){
            cout<<"\t\tNhan ENTER de thoat: ";
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        if(choice == "1"){
            l.ClearList(); 
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            string xuongdong;
            getline(FileIn, xuongdong); // doc hang ten cac truong, xong xuong dong bat dau doc thong tin khach hang 
            ThemCustomerVaoList(FileIn, l);
            if(l.IsEmpty()){
                cout<<"\t\tDanh sach dang rong!\n\t\t";
                system("pause");
                continue;
            }
            else{
                l.XuatDS();
                system("pause");
                FileIn.close();
            }
        }
        else if(choice == "2"){
            l.ClearList();
            cin.ignore();
            ifstream FileIn;
            FileIn.open("data.txt", ios::in);
            string xuongdong;
            getline(FileIn, xuongdong); // Bo qua truong ten
            ThemCustomerVaoList(FileIn, l);
            FileIn.close();
            ofstream FileOut;
            FileOut.open("data.txt", ios::app);
            // Kiem tra file rong hay khong, neu rong thi them hang ten cac truong vao
            if(xuongdong.length() == 0){
                XuatCacTruong(FileOut);
            }
            Customer x;
            int check = 0;
            do{
                if(check != 0){
                    cout<<"\t\tVui long nhap lai!\n";
                    cin.ignore();
                }
                x.NhapThongtin();
                check++; 
                }while(! KiemTraDauVao(l, x));
            NODE *p = new NODE(x);
            l.ThemCuoi(p);
            AddInfoRaFile(FileOut, l);
            cout<<"\t\tThem thong tin Khach hang thanh cong";
            FileOut.close();
            Sleep(1000);
        }
        else if(choice == "3"){
            while(1){
                l.ClearList();
                ifstream FileIn;
                FileIn.open("data.txt", ios::in);
                string choice1;
                system("cls");
                cout<<"\n\t\t===================TIM KIEM=======================";
                cout<<"\n\t\t|  1. Tim kiem theo ID                           |";
                cout<<"\n\t\t|  2. Tim kiem theo ten                          |";
                cout<<"\n\t\t|  3. Tim kiem theo dia chi                      |";
                cout<<"\n\t\t|  4. Tim kiem theo email                        |";
                cout<<"\n\t\t|  5. Tim kiem theo so dien thoai                |";
                cout<<"\n\t\t|  6. Tim kiem theo dich vu da su dung           |";
                cout<<"\n\t\t|  7. Tim kiem theo hoa don                      |";
                cout<<"\n\t\t|  8. Tim kiem theo chat luong danh gia dich vu  |";
                cout<<"\n\t\t|  0. Thoat tim kiem                             |";
                cout<<"\n\t\t==================================================";
                cout<<"\n\t\tNhap lua chon: ";

                cin>>choice1;
                if(choice1 == "0"){
                    FileIn.close();
                    break; 
                }
                else if(choice1 == "1"){
                    int id;
                    cout<<"\t\tNhap ID can tim kiem: ";
                    cin>>id;
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchID(FileIn, l, id);
                }
                else if(choice1 == "2"){
                    string name;
                    cout<<"\t\tNhap ten can tim kiem: ";
                    cin.ignore();
                    getline(cin, name);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchName(FileIn, l, name);
                }
                else if(choice1 == "3"){
                    string address;
                    cout<<"\t\tNhap dia chi can tim kiem: ";
                    cin.ignore();
                    getline(cin, address);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchAddress(FileIn, l, address);                 
                }
                else if(choice1 == "4"){
                    string email;
                    cout<<"\t\tNhap email can tim kiem: ";
                    cin.ignore();
                    getline(cin, email);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchEmail(FileIn, l, email);                 
                }
                else if(choice1 == "5"){
                    string phone;
                    cout<<"\t\tNhap so dien thoai can tim kiem: ";
                    cin.ignore();
                    getline(cin, phone);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchPhone(FileIn, l, phone);                 
                }
                else if(choice1 == "6"){
                    string service;
                    cout<<"\t\tNhap ten dich vu can tim kiem: ";
                    cin.ignore();
                    getline(cin, service);
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchService(FileIn, l, service);                 
                }
                else if(choice1 == "7"){
                    ll bill;
                    cout<<"\t\tNhap so tien hoa don can tim: ";
                    cin>>bill;
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchBill(FileIn, l, bill);                 
                }
                else if(choice1 == "8"){
                    int rate;
                    cout<<"\t\tNhap chat luong danh gia can tim (0-5): ";
                    cin>>rate;
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    SearchRate(FileIn, l, rate);                 
                }
                else{
                    cout<<"\t\tBan da nhap sai cu phap!!!";
                    cout<<"\n\t\t";
                    system("pause");
                }
            }
        }
        else if(choice == "4"){
            while(1){
                l.ClearList();
                ifstream FileIn;
                FileIn.open("data.txt", ios::in);
                string choice1;
                
                system("cls");
                cout<<"\n\t\t====================SAP XEP========================";
                cout<<"\n\t\t|  1. Sap xep theo ten                            |";
                cout<<"\n\t\t|  2. Sap xep theo dia chi                        |";
                cout<<"\n\t\t|  3. Sap xep theo tong so tien hoa don           |";
                cout<<"\n\t\t|  4. Sap xep theo chat luong danh gia san pham   |";
                cout<<"\n\t\t|  0. Thoat tinh nang                             |";
                cout<<"\n\t\t===================================================";
                cout<<"\n\t\tNhap lua chon: ";
                cin>>choice1;
                if(choice1 == "0"){
                    FileIn.close();
                    break; 
                }
                else if(choice1 == "1"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortName_A_to_Z(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortName_Z_to_A(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }

                }
                else if(choice1 == "2"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortAddress_A_to_Z(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortAddress_Z_to_A(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }

                }
                else if(choice1 == "3"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortBill_0_to_9(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortBill_9_to_0(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }
                }
                else if(choice1 == "4"){
                    cout<<"\t\t\t1. Sap xep tang dan";
                    cout<<"\n\t\t\t2. Sap xep giam dan";
                    cout<<"\n\t\t\tNhap lua chon: ";
                    string choice2;
                    cin>>choice2;
                    if(choice2 == "1"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortRate_0_to_9(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);
                    }
                    if(choice2 == "2"){
                        cin.ignore();
                        string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                        getline(FileIn, xuongdong);
                        SortRate_9_to_0(FileIn, l);
                        cout<<"\t\t\tSap xep thanh cong";
                        Sleep(1000);                        
                    }
                }
                else{
                    cout<<"\t\tBan da nhap sai cu phap!!!";
                    cout<<"\n\t\t";
                    system("pause");
                }

            }
        }
        else if(choice == "5"){
            while(1){
                l.ClearList();
                ifstream FileIn;
                FileIn.open("data.txt", ios::in);
                string choice1;
                system("cls");
                cout<<"\n\t\t|========================THONG KE=======================|";
                cout<<"\n\t\t|  1. Thong ke tong so khach hang                       |";
                cout<<"\n\t\t|  2. Thong ke tong so tien cua tat ca cac khach hang   |";
                cout<<"\n\t\t|  3. Thong ke luot danh gia cua khach hang             |";
                cout<<"\n\t\t|  0. Thoat tinh nang                                   |";
                cout<<"\n\t\t|=======================================================|";
                cout<<"\n\t\tNhap lua chon: ";
                cin>>choice1;
                if(choice1 == "0"){
                    FileIn.close();
                    break; 
                }
                else if(choice1 == "1"){
                    cin.ignore();
                    string xuongdong;
                    getline(FileIn, xuongdong);
                    cout<<"\t\tTong so khach hang: "<<TotalCustomer(FileIn, l)<<"\n\t\t";
                    system("pause");
                }
                else if(choice1 == "2"){
                    cin.ignore();
                    string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                    getline(FileIn, xuongdong);
                    cout<<"\t\tTong so tien trong danh sach da thong ke la: "<<TachDonVi(TotalBill(FileIn, l))<<"\n\t\t";
                    system("pause");
                }
                else if(choice1 == "3"){
                    cin.ignore();
                    string xuongdong; // tao bien tam \n de bo qua viec doc cac truong ID,... o dong dau tien
                    getline(FileIn, xuongdong);
                    TotalRate(FileIn, l);
                    system("pause");
                }
                else{
                    cout<<"\t\tBan da nhap sai cu phap!!!";
                    cout<<"\n\t\t";
                    system("pause");
                }
            }   
        }
        else{
            cout<<"\t\tBan da nhap sai cu phap!!!";
            cout<<"\n\t\t";
            system("pause");

        }
    }

}