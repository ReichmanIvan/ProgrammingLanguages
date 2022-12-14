#include <iostream>
#include <cmath>
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
    const double p = 1.34;
    const double k = 1.4;
    double x = 0.0;
    const double a = 1.65;
    double n;
    cout << "Введите x\n";
    cin >> x;
    cout << "\n";
    if (x >= p && x < k )
    {
        cout << "Невзможно посчитать функцию.";
    }
    
    if (x < p)
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
    return M_PI * x * x - 7 / x * x;
}

double GetFunction(const double a, const double x)
{
    return log(x + 7 * sqrt(x + a));
}
