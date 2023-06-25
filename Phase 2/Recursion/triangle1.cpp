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

        pattern1(m, n + 1);
        cout << "* ";
    }
    else
    {

        pattern1(m - 1, 0);
        cout << endl;
    }
}

int main()
{

    int a = 5;
    int b = 5;
    pattern1(a, b);
}