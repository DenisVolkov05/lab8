#include <iostream>
using namespace std;
double f(double x, double y)
{
    return pow(x + y, 2);
}
double y_toch(double x)
{
    return tan(x) - x;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    double x[11], y[11], k[11][5], h = 0.1, dy[11], eps[11];
    y[0] = 0;
    for (int i = 0; i <= 10; i++)
    {
        x[i] = h * i;
    }
    for (int i = 0; i <= 2; i++)
    {
        k[i][0] = h * f(x[i], y[i]);
        k[i][1] = h * f(x[i] + h / 2, y[i] + k[i][0] / 2);
        k[i][2] = h * f(x[i] + h / 2, y[i] + k[i][1] / 2);
        k[i][3] = h * f(x[i] + h, y[i] + k[i][2]);
        dy[i] = (k[i][0] + 2 * k[i][1] + 2 * k[i][2] + k[i][3])/6;
        y[i + 1] = y[i] + dy[i];
    }
    for (int i = 4; i <= 10; i++)
    {
        y[i] = y[i - 1] + h * (55 * f(x[i - 1], y[i - 1]) - 59 * f(x[i - 2], y[i - 2]) + 37 * f(x[i - 3], y[i - 3]) - 9 * f(x[i - 4], y[i - 4]))/24;
    }
    for (int i = 0; i <= 10; i++)
    {
        eps[i] = abs(y[i] - y_toch(x[i]));
        cout << "x" << i << ": " << x[i] << "    y" << i << ": " << y[i] << "    Погрешность eps: " << eps[i] << endl;
    }
}
