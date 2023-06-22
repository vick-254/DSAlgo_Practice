#include <iostream>
using namespace std;

int stairClimb(int n)
{

    if (n < 2)
    {
        return 1;
    }

    return stairClimb(n - 1) + stairClimb(n - 2);
}

int main()
{
    int n;
    cin >> n;
    int ans = stairClimb(n);
    cout << ans;
}