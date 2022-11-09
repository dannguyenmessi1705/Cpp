#include <bits/stdc++.h>
using namespace std;
int main() {
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    string pass = "";
    pass = to_string(now->tm_hour)+to_string(now->tm_min)+to_string(now->tm_mday)+to_string(now->tm_mon+1)+to_string(now->tm_year+1900);
    cout<<pass;
}