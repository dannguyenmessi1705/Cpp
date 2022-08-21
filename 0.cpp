#include <iostream>
using namespace std;
int kiemtraNT(int so)
{
int dem=0;
for(int i=1;i<=so;i++)
{
if(so%i==0)
{
dem++;
}
if(dem==2)
{
return 1;
}
else
{
 return 0;
 }
}
}
     int main()
     {
      for(int i=1;i<=100;i++)
      {

   if(kiemtraNT(i)==1);  
   cout<<i<<" "; 
 }
  return 0;
  }