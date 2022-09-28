#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
using namespace std;

/**
*  \brief Функция расчета по заданной формуле.
*  \param x Первый параметр функции.
*  \param y Второй параметр функции.
*  \param z Третий параметр функции.
*  \return Значение функции.
*/ 
const double getA (double x, double y, double z);

/**
*  \brief Функция расчета по заданной формуле.
*  \param x Первый параметр функции.
*  \param y Второй параметр функции.
*  \param z Третий параметр функции.
*  \return Значение функции.
*/ 
const double getB (double x, double y, double z);
/**
*  \brief Точка входа в программу.
*  \return Возвращает 0 в случае успеха.
*/
int main()
{
const auto x = -0.5;
const auto y = 1.7;
const auto z = 0.44;
const auto a = getA (x, y, z);
const auto b = getB (x, y, z);

cout << " x = " << x << ", y = " << y << ", z = " << z << "\n";
cout << " a = " << a << ", b = " << b << endl;

return 0;
}

const double getA (const double x, const double y, const double z)
{
return exp(-y *z ) * sin(x * z - y) - pow(abs(y * z + x), 1.0/2);
}

const double getB (const double x, const double y, const double z)
{
return y * sin(x*z*z*cos(2 * z)) - 1;
}
