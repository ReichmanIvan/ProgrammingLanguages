#include <iostream>
#include <cmath>
using namespace std;

/**
* \brief функция определения текущего элемента ряда.
* \param k - переменная для вычисления элемента ряда.
* \return значение текущего элемент ряда.
*/
double GetCurrent(const size_t k);

/**
* \brief функция вычисления суммы первых n элементов ряда.
* \param n - количество элементов ряда.
* \param k - переменная для вычисления элемента ряда.
* \return сумма первых n элементов ряда.
*/
double GetSumm(const int n);

/**
* \brief функция вычисления суммы членов ряда не меньших числа e.
* \param e - константа по условию.
* \param k - переменная для вычисление элемента ряда.
* \return сумма членов ряда не меньших числа e.
*/
double GetSumm(const double e,  size_t k);

/**
* \brief точка входа в программу.
* \return возвращает 0 в случае успеха.
*/
int main()
{
    int n;
    double e = 0.0;
    size_t k = 1;
    cout << "Введите количество членов последовательности" << endl;
    cin >> n;
    cout << "Введите e" << endl;
    cin >> e;
    cout << GetSumm(n) << endl;
    cout << GetSumm(e, k);
    return 0;
}

double GetCurrent(const size_t k)
{
    return -1 * (1.0 / pow((k + 1),2));
}

double GetSumm(const int n)
{
    double sum = 0.0;
    for (int i = 1; i <=  n; i++)
    {
        size_t k=k+1;
        sum = sum + GetCurrent(k);
    }
return sum;
}

double GetSumm(const double e, size_t k)
{
    double sum = 0.0;
    double current = GetCurrent(k);
    while (abs(current) > e)
    {
        sum = sum + current;
        k++;
        current = GetCurrent(k);
    }
    return sum;
}
