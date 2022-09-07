#include <iostream>
int main(){
    int x, n;
    std::cin>>x>>n;
    int result=1;
    for(int i=1;i<=n;i++){
        result*=x;
    }
    std::cout<<result;
}