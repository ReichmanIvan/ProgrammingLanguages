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
double GetSumm(const int n, size_t k);

/**
* \brief функция вычисления суммы членов ряда не меньших числа e.
* \param e - константа по условию.
* \param k - переменная для вычисление элемента ряда.
* \return сумма членов ряда не меньших числа e.
*/
double GetSummE(const double e,  size_t k);

/**
* \brief точка входа в программу.
* \return возвращает 0 в случае успеха.
*/
int main()
{
    int n;
    double e = 0.0;
    size_t k = 1;
    cout << "Введите количество членов ряда" << endl;
    cin >> n;
    cout << "Введите e" << endl;
    cin >> e;
    cout << GetSumm(n, k) << endl;
    cout << GetSummE(e, k);
    return 0;
}

double GetCurrent(const size_t k)
{
    return pow((-1.0),k) * (1.0 / pow((k + 1),2));
}

double GetSumm(const int n, size_t k)
{
    double sum;
    for (int i = 1; i <=  n; i++)
    {
        sum = sum + GetCurrent(k);
        k=k+1;
    }
return sum;
}

double GetSummE(const double e, size_t k)
{
    double cur, sum;
    cur = GetCurrent(k);
    while (cur > e){
        sum = sum + cur;
        k++;
        cur = GetCurrent(k);
    }
    return sum;
}