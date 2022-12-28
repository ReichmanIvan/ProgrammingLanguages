#include <iostream>
#include <random>
#include <ctime>

using namespace std;

/**
 * \brief Считывает значение числа из консоли
 * \param message Побуждающее сообщение для пользователя
 * \return Число
 */
size_t get_size(const string& message);

/*
*\brief Фукция которая заполняет массив случайными элементами
*\return Возвращает указатель на заполненный массив
*/
int* FillRandomArray(const size_t size);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size);

/**
 * \brief Выводит массив в консоли
 * \param array Указатель на массив
 */
void PrintArray(int* array, const size_t size);

/**
 * \brief Находит первый отрицательный элемент массива
 * \param array Указатель на массив
 */
int FirstNegativeIndex(int* array, const size_t size);

/**
 * \brief Находит первый положительный элемент массива
 * \param array Указатель на массив
 */
int FirstPositiveIndex(int* array, const size_t size);

/**
 * \brief Меняет первый отрицательный элемент массива на первый положительный элемент массива
 * \param array Указатель на массив
 * \param first_negative_index Последний отрицательный элемент массива
 */
int* ChangeElements(int* array, const size_t size, const int first_negative_index, const int first_positive_index);

/**
 * \brief Выбор варианта заполнения массива
 * \param USER_INPUT Пользователь заполняет массив
 * \param RANDOM_INPUT Массив заполняется случайными числами
 */
enum class userInput
{
    USER_INPUT,
    RANDOM_INPUT
};

/**
 * \brief Удаляет неподходящие элементы массива
 * \param array Указатель на массив
 * \param a 1 Граница промежутка
 * \param b 2 Граница промежутка
 * \param newsize Новый размер массива
 */
int* DeleteOddElements(int* array, size_t size, int newsize, int a, int b);

/**
 * \brief Находит неподходящие элементы массива
 * \param array Указатель на массив
 * \param a 1 Граница промежутка
 * \param b 2 Граница промежутка
 */
int WrongElements(int* array, size_t size, const int a, const int b);

/**
 * \brief Новый массив
 * \param array Указатель на массив
 */
int* NewArray(int* array, int size);

/*
*\brief Точка входа в программу
*\return возвращает 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    int size = get_size("Введиите колличество элементов массива ");
    cout << "Введите число, соответствующее вашему желанию заполнения массива:\n" << "\n"
        << static_cast<int>(userInput::USER_INPUT) << " - вы заполняете массив вручную.\n"
        << static_cast<int>(userInput::RANDOM_INPUT) << " - заполняет массив случайными числами.\n\n";

    int input = 0;
    cout << "Ваше число выбора варианта заполнения массива: ";
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    int* array = nullptr;

    switch (choice)
    {
    case userInput::USER_INPUT:
    {
        array = FillUserArray(size);
        break;
    }

    case userInput::RANDOM_INPUT:
    {
        array = FillRandomArray(size);
        break;
    }

    default:
    {
        cerr << "Введено неверное значение\n";
    }
    }
    cout << "Ваш массив:\n";
    PrintArray(array, size);
    cout << "\n";
    int first_positive_index = FirstPositiveIndex(array, size);
    int first_negative_index = FirstNegativeIndex(array, size);
    array = ChangeElements(array, size, first_negative_index, first_positive_index);
    cout << "измененный массив:\n";
    PrintArray(array, size);
    cout << "\nВведите границы промежутка (a и b)" << "\n";
    cin >> a;
    cin >> b;
    cout << "\n";
    int newsize = size - WrongElements(array, size, a, b);
    cout << "измененный массив 2:\n";
    array = DeleteOddElements(array, size, newsize, a, b);
    PrintArray(array, newsize);
    array = NewArray(array, size);
    cout << "\nизмененный массив 3:\n";
    PrintArray(array, newsize);
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

int* FillUserArray(const size_t size)
{
    int* array = new int[size];
    cout << "Введите элементы массива" << "\n";
    for (size_t i = 0; i < size; i++)
    {
        cin >> array[i];
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

int FirstNegativeIndex(int* array, const size_t size)
{
    int e = 0;
    int i = size - 1;
    while (i >= 0)
    {
        if (array[i] < 0)
        {
            e = i;
        }
        i = i - 1;
    }
    return e;
}

int FirstPositiveIndex(int* array, const size_t size)
{
    int e = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (array[i] > 0)
        {
            e = i;
        }
    }
    return e;
}

int* ChangeElements(int* array, const size_t size, const int first_negative_index, const int first_positive_index)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i == first_negative_index)
        {
            array[i] = array[first_positive_index];
        }
    }
    return array;
}

int* DeleteOddElements(int* array, size_t size, int newsize, int a, int b)
{
    int d = 0;
    int* arrayB = new int[newsize];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < a || array[i] > b )
        {
            arrayB[d] = array[i];
            d++;
        }
        
        else
        {
            if (array[i] % 7 != 0)
            {
                arrayB[d] = array[i];
                d++;
            }
        }
    }
    return arrayB;
}
 int WrongElements(int* array, size_t size, const int a, const int b)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
         if (array[i] % 7 == 0 && array[i] >= a && array[i] <= b)
         {
             c++;
         }
    }
    return c;
}

 int* NewArray(int* array, int size)
 {
     int* arrayB = new int[size];
     for (int i = 0; i < size; i++)
     {
         if ((i + 1) % 2 == 0)
         {
             arrayB[i] = array[i] * array[i] + i;
         }

         else
         {
             arrayB[i] = array[i] * i;
         }
     }
     return arrayB;
 }
