#include <iostream>
#include <vector>
using namespace std;

void sayDigits(int n, vector<string> arr)
{
    if (n == 0)
    {
        return;
    }
    int num = n % 10;
    sayDigits(n / 10, arr);
    cout << arr[num] << " ";
}

int main()
{
    vector<string> arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin >> n;
    sayDigits(n, arr);
}