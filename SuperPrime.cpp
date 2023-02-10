#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int n, k;
    queue<int> q;
    cin>>n;
    // Số siêu nguyên tố là số nguyên tố và khi nó bị xóa các số phía sau đi, nó vẫn là 1 snt
    // Để tìm số siêu nguyên tố theo thứ tự tăng dần đến n
    // Ta xét từ 2 -> 9, xét số nào là số nguyên tố rồi thêm lần lượt 1 -> 9 vào sau số đó để xét isPrime() tiếp
    for(int i=2; (i<=n) && (i<10); i++){
        if(isPrime(i)){
            q.push(i);
        }
    }
    while(!q.empty()){
        for(int i=1; i<10; i++){
            k = (q.front()*10) + i;
            if(k<=n && isPrime(k)){
                q.push(k);
            }
        }
        cout<<q.front()<<" ";
        q.pop();
    }
}