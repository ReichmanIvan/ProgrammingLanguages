#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

/**
 * \brief Функция расчета по заданной формуле.
 * \param x Параметр функции.
 * \return Возвращает значение функции.
*/
double Calculation(const double x);

/**
 * \brief Проверка y при заданном x.
 * \param x Параметр функции.
 * \return true Если y существует при заданном x.
*/
bool IsExists(const double x);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    const double xStart = 1.0;
    const double xFinish = 3.0;
    const double step = 0.2;
    double x = xStart;

    while(x < xFinish + step)
    {
        if (IsExists(x))
        {
            const double y = Calculation(x);
            cout << "x = " << setw(10) << left << setprecision(4) << x << " y = " << y << "\n";
        }
        else
        {
            cout << x << " " << "Нет значения \n";
        }
        x += step;
    }

    return 0;
}

double Calculation(const double x)
{
    return sin(log(x)) - cos(log(x)) + 2.0 * (log(x));
}

bool IsExists(const double x)
{
    return (abs(x)) > numeric_limits<double>::min();
}
