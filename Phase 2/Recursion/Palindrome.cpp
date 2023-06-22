#include <iostream>
using namespace std;

bool palindrome(string str, int i)
{

    int n = str.length();

    if (i > n / 2)
        return 1;

    if (str[i] == str[n - i - 1])
        return palindrome(str, i + 1);
    if (str[i] != str[n - i - 1])
        return 0;
}

int main()
{

    string str = "maaam";
    bool a = palindrome(str, 0);
    cout << a;
}