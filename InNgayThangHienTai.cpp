#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char Time[10], Date[12];
    strcpy(Time,__TIME__);
    strcpy(Date,__DATE__);
    cout<<Time<<" "<<Date;
}