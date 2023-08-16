#include <iostream>
#include <cmath>

using namespace std;

void point(int x, int y, bool& a, bool* b)
{
    if ((pow(x, 2) + pow(y, 2) < 9) && (y < x * (-1)) && (y > -3 - x))
    {
        a = true;
    }
    else if ((pow(x, 2) + pow(y, 2) == 9) || (y == x * (-1)) || (y == -3 - x))
    {
        *b = true;
    }
    else
    {
        a = false;
        *b = false;
    }
}
