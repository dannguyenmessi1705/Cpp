#include <iostream>
#include <algorithm>

using namespace std;

int findDivisors(long long n) 
{
    int c=0;
    for(int j=1;j*j<=n;j++)
    {
        if(n%j==0)
        {
            c++;
            if(j!=(n/j))
            {
                c++;
            }
        }
    }
    return c;
}

long long compute(long long n)
{
    long long sum=0;
    for(int i=1; i<=n; i++)
    {
        sum += (findDivisors(i));
    }
    return sum;
}

int main()
{
    int n, divisors;
    cin >> n;

    cout << compute(n);
}