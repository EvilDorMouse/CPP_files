#include <iostream>
#include "point.h"

using namespace std;

int Ex_point()
{
    int x(0), y(0);
    bool a(false), b(false);

    cout << "Enter the coordinates A(x, y):\n";
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    point(x, y, a, &b);

    cout << "\n1 - true. 0 - false.\n\n";
    cout << "The point lies in the shaded area: " << a << endl;
    cout << "The point lies on the border: " << b << endl;

    return 0;
}
