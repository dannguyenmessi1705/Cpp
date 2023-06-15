#include <bits/stdc++.h>
using namespace std;
void comb(int N, int K)
{
    string bitmask(K, 1); // K leading 1's K = 3// "111"
    bitmask.resize(N, 0); // N-K trailing 0's // "1110"

    // print integers and permute bitmask
    do
    {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
                cout << i + 1;
        }
        cout << " ";
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}
int main()
{
    int test;
    cin>>test;
    while(test--){
        int n, k;
        cin>>n>>k;
        comb(n, k);
        cout<<endl;
    }

}