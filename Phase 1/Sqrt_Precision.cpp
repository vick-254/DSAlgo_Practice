#include <iostream>
using namespace std;

int Sqrt(int key)
{

    int start = 0;
    int end = key;
    int mid = (start + end) / 2;
    int ans = -1;

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
        else if (mid * mid < key)
        {
            ans = mid;
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

double precisionSqrt(int temp, int key, int precision)
{

    double factor = 1;
    double ans = temp;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = temp; j * j < key; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{

    int a;
    cin >> a;
    int sqrt = Sqrt(a);

    double ans = precisionSqrt(sqrt, a, 3);
    cout << ans;
}