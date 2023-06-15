#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int size = nums.size();
    vector<int>::iterator i;
    i = nums.begin();
    int k = 0;
    while (i != nums.end() && k < size)
    {

        if (*i == 0)
        {
            nums.erase(i);
            nums.push_back(0);

            k++;
            continue;
        }
        i++;
        k++;
    }

    for (int j = 0; j < size; j++)
    {
        cout << nums[j] << " ";
    }
}

int main()
{

    vector<int> nums = {11, 0, 2, 4, 0, 0, 6, 7, 0, 9};
    moveZeroes(nums);
}