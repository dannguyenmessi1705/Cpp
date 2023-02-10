#include <iostream>
using namespace std;
class Matrix{
private:
    int col;
    int row;
    int **data;
public:
    Matrix(){};
    Matrix(int row, int col){
        this->row = row;
        this->col = col;
        data = new int*[row];
        for(int i=0; i<row; i++){
            data[i] = new int[col];
        }
    }
    void setData(int row, int col, int value){
        data[row][col] = value;
    }
    int getData(int row, int col){
        return data[row][col];
    }
    void NhapMT(){
        int value;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>value;
                setData(i, j, value);
            }
        }
    }
    void XuatMT(){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<this->getData(i, j)<<" ";
            }
            cout<<"\n";
        }
    }
    ~Matrix(){
        for(int i=0; i<row; i++){
            delete[] data[i];
        }
        delete[] data;
    }
};

int main(){
    int row, col;
    cin>>row>>col;
    Matrix m(row, col);
    m.NhapMT();
    m.XuatMT();
}