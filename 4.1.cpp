#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

/**
 * \brief ��������� �������� ����� �� �������.
 * \param message ����������� ��������� ��� ������������.
 * \return �����.
 */
size_t get_size(const string& message);

int* FillRandomArray(const size_t size);

void PrintArray(int* array, const size_t size);

int OutEvenNumbers(int* array, const size_t size);

int DoubleElements(int* array, const size_t size);

int LastNegativeIndex(int* array, const size_t size);

int* ChangeElements(int* array, const size_t size, const int last_negative_index);
/**
 * \brief ����� �������� ���������� �������.
 * \param USER_INPUT ������������ ��������� ������.
 * \param RANDOM_INPUT ������ ����������� ���������� �������.
 */
enum class userInput
{
    USER_INPUT,
    RANDOM_INPUT
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int size = get_size("�������� ����������� ��������� ������� ");
    cout << "������� �����, ��������������� ������ ������� ���������� �������:\n" << "\n"
        << static_cast<int>(userInput::USER_INPUT) << " - �� ���������� ������ �������.\n"
        << static_cast<int>(userInput::RANDOM_INPUT) << " - ��������� ������ ���������� �������.\n\n";

    int input = 0;
    cout << "���� ����� ������ �������� ���������� �������: ";
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    int* array = nullptr;

    switch (choice)
    {
    case userInput::USER_INPUT:
    {

        break;
    }

    case userInput::RANDOM_INPUT:
    {
        array = FillRandomArray(size);
        break;
    }

    default:
    {
        cerr << "������� �������� ��������\n";
    }
    }
    cout << "Your array is here:\n";
    PrintArray(array, size);
    cout << "\n";
    cout << "����� ������ �����:\n";
    int even_numbers = OutEvenNumbers(array, size);
    cout << even_numbers;
    cout << "\n";
    cout << "���������� ���������, ��������� �� ���� ����:\n";
    int double_elements = DoubleElements(array, size);
    cout << double_elements << "\n";
    int last_negative_index = LastNegativeIndex(array, size);
    array = ChangeElements(array, size, last_negative_index);
    cout << "���������� ������:\n";
    PrintArray(array, size);
}


int* FillRandomArray(const size_t size)
    {
    const int minValue = -1000;
    const int maxValue = 1000;

    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    auto* array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        array[index] = uniformIntDistribution(gen);
    }

    return array;
}

size_t get_size(const string& message)
{
    int size = -1;
    cout << message;
    cin >> size;

    if (size < 0)
    {
        throw out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }

    return static_cast<size_t>(size);
}

void PrintArray(int* array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout.width(3);
        cout << array[i] << "\t";
    }
}

int OutEvenNumbers(int* array, const size_t size)
{
    int e = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            e += array[i];
        }
    }
    return e;
}

int DoubleElements(int* array, const size_t size)
{
    int e = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] <= 99 && array[i] >= 10 || array[i] <= -10 && array[i] >= -99)
        {
            e += 1;
        }
    }
    return e;
}

int LastNegativeIndex(int* array, const size_t size)
{
    int e = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            e = i;
        }
    }
    return e;
}

int* ChangeElements(int* array, const size_t size, const int last_negative_index)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i == last_negative_index)
        {
            array[i] = abs(array[0]);
        }
    }
    return array;
}