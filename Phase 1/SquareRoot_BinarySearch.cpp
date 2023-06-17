#include <iostream>
using namespace std;

int squareRoot(int key)
{

    int start = 0;
    int end = key;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (mid * mid == key)
        {
            return mid;
        }
        else if (mid * mid > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return mid;
}

int main()
{

    int a;
    cin >> a;
    int ans = squareRoot(a);
    cout << ans << endl;
}