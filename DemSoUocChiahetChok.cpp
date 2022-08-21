// C++ program to count number of divisors
// of N which are divisible by K
#include <bits/stdc++.h>
using namespace std;
 
// Function to count number of divisors
// of N which are divisible by K
int countDivisors(int n, int k)
{
    // integer to count the divisors
    int count = 0, i;
 
    // Traverse from 1 to sqrt(N)
    for (i = 1; i <= sqrt(n); i++)
    {
 
        // Check if i is a factor
        if (n % i == 0)
        {
            // increase the count if i
            // is divisible by k
            if (i % k == 0)
            {
                count++;
            }
 
            // (n/i) is also a factor
            // check whether it is divisible by k
            if ((n / i) % k == 0)
            {
                count++;
            }
        }
    }
     
    i--;
 
    // If the number is a perfect square
    // and it is divisible by k
    if ((i * i == n) && (i % k == 0))
    {
        count--;
    }
 
    return count;
}
 
// Driver code
int main()
{
    int n, k=2;
    cin >> n;
 
    // Function Call
    cout << countDivisors(n, k);
    return 0;
}