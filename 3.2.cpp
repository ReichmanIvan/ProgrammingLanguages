#include <iostream>
#include <cmath>
using namespace std;

/*
*\brief функция определения текущего элемента ряда.
*\param k - переменная для вычисления элемента ряда.
*\return значение текущего элемент ряда.
*/
double GetCurrent(const size_t k);

/*
* \brief функция вычисления суммы первых n элементов ряда.
* \param n - количество элементов ряда.
* \return сумма первых n элементов ряда.
*/
double GetSumm(const int n);

/*
* \brief функция вычисления суммы членов ряда не меньших числа e.
* \param e - константа по условию.
* \return сумма членов ряда не меньших числа e.
*/
double GetSumm(const double e);

/*
 \brief функция вычисления факториала.
* \param N - число, факториал которого нужно вычислить.
* \return возвращает факториал.
**/
double GetFact(int N);

/*
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
    cout << GetSumm(e);
    return 0;
}

double GetFact(int N)
{
    if(N < 0) 
        return 0; 
    if (N == 0) 
        return 1;
    else 
        return N * GetFact(N - 1);
}

double GetCurrent(const size_t k)
{
    return (pow(-1,k))*(1.0 / pow(GetFact(k),2));
}

double GetSumm(const int n)
{
    double sum = 0.0;
    for (size_t k = 1; k <=  n; k++)
    {
       sum = sum + GetCurrent(k);
    }
return sum;
}

double GetSumm(const double e)
{
    int k = 1;
    double sum = 0.0;
    while (abs(GetCurrent(k)) >= e)
    
    {
        if (GetCurrent(k) >= e)
        {
        sum = sum + GetCurrent(k);
        }
        k += 1;
    }
    return sum;
}
