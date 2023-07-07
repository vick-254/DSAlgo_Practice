#include <iostream>

using namespace std;

int happySquare(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans = ans + (n % 10) * (n % 10);
        n = n / 10;
    }
    return ans;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = n;

    do
    {
        slow = happySquare(slow);
        fast = happySquare(happySquare(fast));

    } while (fast != slow);

    if (slow == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int a = 89;
    bool aa = isHappy(a);
    cout << aa;
}