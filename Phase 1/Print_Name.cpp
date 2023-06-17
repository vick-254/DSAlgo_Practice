#include <iostream>
using namespace std;

int height = 5;

int width = (2 * height) - 1;

int abs(int d)
{
    return d < 0 ? -1 * d : d;
}

void printV()
{
    int i, j, counter = 0;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j <= width; j++)
        {
            if (j == counter || j == width - counter - 1)
                cout << "*";
            else
                cout << " ";
        }
        counter++;
        cout << "\n";
    }
    cout << "\n";
}

void printE()
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        cout << "*";
        for (j = 0; j < height; j++)
        {
            if ((i == 0 || i == height - 1) || (i == height / 2 && j <= height / 2))
                cout << "*";
            else
                continue;
        }
        cout << "\n";
    }
    cout << "\n";
}

void printG()
{
    int i, j;
    width--;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if ((i == 0 || i == height - 1) && (j == 0 || j == width - 1))
                cout << " ";
            else if (j == 0)
                cout << "*";
            else if (i == 0 && j <= height)
                cout << "*";
            else if (i == height / 2 && j > height / 2)
                cout << "*";
            else if (i > height / 2 && j == width - 1)
                cout << "*";
            else if (i == height - 1 && j < width)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printH()
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        cout << "*";
        for (j = 0; j < height; j++)
        {
            if ((j == height - 1) || (i == height / 2))
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printI()
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height; j++)
        {
            if (i == 0 || i == height - 1)
                cout << "*";
            else if (j == height / 2)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printN()
{
    int i, j, counter = 0;
    for (i = 0; i < height; i++)
    {
        cout << "*";
        for (j = 0; j <= height; j++)
        {
            if (j == height)
                cout << "*";
            else if (j == counter)
                cout << "*";
            else
                cout << " ";
        }
        counter++;
        cout << "\n";
    }
    cout << "\n";
}

void printS()
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height; j++)
        {
            if ((i == 0 || i == height / 2 || i == height - 1))
                cout << "*";
            else if (i < height / 2 && j == 0)
                cout << "*";
            else if (i > height / 2 && j == height - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    printV();
    printI();
    printG();
    printN();
    printE();
    printS();
    printH();

    return 0;
}
