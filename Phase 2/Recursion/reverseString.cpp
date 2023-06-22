#include <iostream>
using namespace std;

void reverseString(string &str, int i, int j)
{
    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;
    reverseString(str, i, j);
}

int main()
{
    string str = "hello";
    reverseString(str, 0, 4);
    cout << str;
}