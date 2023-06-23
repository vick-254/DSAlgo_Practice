#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }

    nums = temp;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    rotate(nums, 2);
    for (int i : nums)
    {
        cout << i << " ";
    }
}