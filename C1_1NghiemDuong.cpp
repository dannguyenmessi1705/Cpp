/* Tìm nghiệm của HPT
X + Y + Z = 100
5X + 3Y + Z/3 = 100 */

#include <iostream>
using namespace std;
int He1(int x, int y, int z){
    if(x+y+z==100) return 1;
    return 0;
}
int He2(int x, int y, int z){
    if(5*x+3*y+z/3==100) return 1;
    return 0;
}
int main(){
    int x,y,z;
    for(int i=0;i<100;i++){
        x=i;
        for(int j=0;j<100;j++){
            y=j;
            for(int k=0;k<100;k++){
                z=k;
                if(He1(x,y,z) && He2(x,y,z)) cout<<"X = "<<x<<"\tY = "<<y<<"\tZ = "<<z<<endl;
            }
        }
    }
}
