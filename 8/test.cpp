#include <iostream>


void RandomArr(int left, int right, int *arr, int size, int chislo);
int Random(int left, int right);

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	//определить максимальное и минимальное значение в массиве
	const int size = 50;
	int arr[size];
    for (int i = 0; i < size; i++)
    {
       arr[i] =1+ rand()%50;
    }
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    std::cout<< "Максимальное число массива: " << max << "  Минимальное число массива: " << min;

    // в заданом диапазоне найти сумму элемент меньше числа пользователя
    int left, right, chislo;
    std::cout << "Введите границы диапозона: ";
    std::cin >> left >> right;
    std::cout << "Введите ваше значение: ";
    std::cin >> chislo;
    const int size = 10;
    int arr[size];
    RandomArr(left, right, arr, size, chislo);

    //определить максимум и минимум прибыли за месяца
    int arr[12];
    int left, right;
    int maxmonth, minmonth;
    for (int i = 0; i < 12; i++)
    {
        std::cout << "Введите прибыль за " << i+1 << " месяц ";
        std::cin >> arr[i];
    }
    std::cout << "Введите границу диапазона ";
    std::cin >> left >> right;
    int min = arr[left - 1];
    int max = arr[left - 1];
    for (int i = left - 1; i <= right - 1; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxmonth = i+1;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minmonth = i+1;
        }
    }
    std::cout << "Максимальная прибыль была в " << maxmonth << " месяце" << std::endl
        << "Минимальная прибыль была в " << minmonth << " месяце";

    int N;
    std::cout << "Введите количество элементов в массиве ";
    std::cin >> N;
    int* arr = new int[N];
    int sumnegative = 0;
    int proz = 1;
    int prozchot = 1;
    int max{}, min{};
    int first, last;
    int deapsum = 0;
    for (int i = 0; i < N; i++)
    {
        arr[i] = Random(-10, 10);
        std::cout << arr[i]<<" ";
        if (arr[i] < 0)
        {
            sumnegative += arr[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (int i = min; i <= max; i++)
    {
        proz = proz * arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            prozchot = prozchot * arr[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < 0)
            first = i;
    }
    for (int i = N; i > 0; i--)
    {
        if (arr[i] < 0)
            last = i;
    }
    for (int i = deapsum; i < N; i++)
    {
        deapsum += arr[i];
    }
    std::cout << std::endl;
    std::cout << "Сумма отрицательных чисел " << sumnegative << std::endl;
    std::cout << "Произведение в диапозоне " << proz << std::endl;
    std::cout << "Произведение чисел с четными индексами " << prozchot << std::endl;
    std::cout << "Сумма чисел между первым и последним отрицательным числом " << deapsum;
    delete[]arr;

	return 0;
}
void RandomArr(int left, int right, int* arr, int size, int chislo)
{ 
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = left + rand()% right;
        std::cout << arr[i]<<" ";
        if (i < chislo)
        {
            sum = sum + i;
        }
    }
    std::cout << sum;
}
int Random(int left, int right)
{
    return left + rand() % (right - left + 1);
}



