#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

/**
 * \brief Функция расчета по заданной формуле.
 * \param x Параметр функции, который вводит пользователь.
 * \param a Константа.
 * \return Возвращает значение функции.
*/
double GetFunction(const double x);

/**
 * \brief Функция расчета по заданной формуле.
 * \param x Параметр функции, который вводит пользователь.
 * \return Возвращает значение функции.
*/
double GetFunction(const double a, const double x);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    double x = 0.0;
    const double a = 1.65;
    double n;
    cout << "Введите x\n";
    cin >> x;
    cout << "\n";
    if (x >= 1.34 && x < 1.4 )
    {
        cout << "Невзможно посчитать фкнкцию.";
    }
    
    if (x < 1.34)
    {
        n = GetFunction(x);
    }
    
    else 
    {
      n = GetFunction(a, x);
    }
    
    cout << n;
    return 0;
    
}

double GetFunction(const double x)
{
    if (x < 1.34)
    {
        return M_PI * x * x - 7 / x * x;
    }
    return 0;
}

double GetFunction(const double a, const double x)
{
    if (x >= 1.4)
    {
        return log(x + 7*sqrt(x + a));
    }
    return 0;
}
