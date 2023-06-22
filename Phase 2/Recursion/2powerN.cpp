#include <iostream>
using namespace std;

int power2(int n)
{

    if (n == 0)
        return 1;

    return 2 * power2(n - 1);
}

int main()
{
    int ans = power2(5);
    cout << ans;
}