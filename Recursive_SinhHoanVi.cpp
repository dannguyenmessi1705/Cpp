#include <iostream>
#include <vector>

using namespace std;

void generate_permutations(vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        // In ra dãy hoán vị hiện tại
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        generate_permutations(nums, index + 1);
        swap(nums[index], nums[i]);
    }
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    // Tao ra vector chua cac so tu 1 den n
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    generate_permutations(nums, 0);

    return 0;
}
