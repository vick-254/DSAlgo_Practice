#include <iostream>
using namespace std;

void pattern1(int m, int n)
{

    if (m == 1)
    {
        cout << "*"
             << " ";
        return;
    }

    if (n < m)
    {
        cout << "* ";
        pattern1(m, n + 1);
    }
    else
    {
        cout << endl;
        pattern1(m - 1, 0);
    }
}

int main()
{

    int a = 5;
    int b = 5;
    pattern1(a, b);
}