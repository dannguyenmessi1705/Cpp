#include <bits/stdc++.h>
using namespace std;
bool Checklist(int n){
    if(n==7|| n==9|| n==14|| n==19|| n==25|| n==31|| n==44|| n==63) return true;
    return false;
}
int main(){
    int n;
    cout<<"PLEASE ENTER a TV channel number: ";
    int t=0;
    do{
        if(t!=0) cout<<"Chanel is invalid, PLEASE ENTER AGAIN: ";
        cin>>n;
        t++;
    } while(!(Checklist(n)));
    switch (n)
    {
    case 7:
        cout<<"The call letters for this channel is: VTV1";
        break;
    case 9:
        cout<<"The call letters for this channel is: VTV2";
        break;
    case 14:
        cout<<"The call letters for this channel is: VTV3";
        break;
    case 19:
        cout<<"The call letters for this channel is: ESPN";
        break;
    case 25:
        cout<<"The call letters for this channel is: VCTV1";
        break;
    case 31:
        cout<<"The call letters for this channel is: HANOI1";
        break;
    case 44:
        cout<<"The call letters for this channel is: HTV1";
        break;
    case 63:
        cout<<"The call letters for this channel is: HTV2";
        break;
    }
    return 0;
}