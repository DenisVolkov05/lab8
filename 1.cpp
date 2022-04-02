#include <iostream>
using namespace std;
double y_toch(double x)
{
    double e = 2.718;
    return pow(x, 2) * pow(e, -1 * pow(x, 2)) / 2;
}
double y_pr(double x, double y)
{
    double e = 2.718;
    return -2 * x * y + x * pow(e, -1 * pow(x, 2));
}
int main()
{
    setlocale(LC_ALL, "Russian");
    double x[11], h = 0.1, y[11], eps[11];
    y[0] = 0;
    for (int i = 0; i <= 10; i ++)
    {
        x[i] = h * i;
    }
    for (int i = 1; i <= 10; i++)
    {
        y[i] = y[i - 1] + h * y_pr(x[i - 1], y[i - 1]);
    }
    for (int i = 0; i <= 10; i++)
    {
        eps[i] = abs(y_toch(x[i]) - y[i]);
    }
    for (int i = 0; i <= 10; i++)
    {
        cout << "x" << i << ": " << x[i] << "   y" << i << ": " << y[i] << "   Сравнение eps: " << eps[i] << endl;
    }
}
