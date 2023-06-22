#include <iostream>
using namespace std;

int pow(int a, int b)
{

    if (b == 0)
        return 1;

    if (b % 2 == 0)
        return pow(a, b / 2) * pow(a, b / 2);

    if (b % 2 != 0)
        return a * pow(a, b / 2);
}

int main()
{
    int a = pow(3, 2);
    cout << a;
}