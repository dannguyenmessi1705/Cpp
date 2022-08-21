#include <iostream>
#include <math.h>
int main(){
    long n;
    std::cin>>n;
    if(n<2) std::cout<<("NO");
    else{
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0){
                std::cout<<"NO";
                return 0;
    }
        std::cout<<"YES";
}
    return 0;
}