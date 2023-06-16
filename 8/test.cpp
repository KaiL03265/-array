#include <iostream>


void RandomArr(int left, int right, int *arr, int size, int chislo);
int Random(int left, int right);

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	//���������� ������������ � ����������� �������� � �������
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
    std::cout<< "������������ ����� �������: " << max << "  ����������� ����� �������: " << min;

    // � ������� ��������� ����� ����� ������� ������ ����� ������������
    int left, right, chislo;
    std::cout << "������� ������� ���������: ";
    std::cin >> left >> right;
    std::cout << "������� ���� ��������: ";
    std::cin >> chislo;
    const int size = 10;
    int arr[size];
    RandomArr(left, right, arr, size, chislo);

    //���������� �������� � ������� ������� �� ������
    int arr[12];
    int left, right;
    int maxmonth, minmonth;
    for (int i = 0; i < 12; i++)
    {
        std::cout << "������� ������� �� " << i+1 << " ����� ";
        std::cin >> arr[i];
    }
    std::cout << "������� ������� ��������� ";
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
    std::cout << "������������ ������� ���� � " << maxmonth << " ������" << std::endl
        << "����������� ������� ���� � " << minmonth << " ������";

    int N;
    std::cout << "������� ���������� ��������� � ������� ";
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
    std::cout << "����� ������������� ����� " << sumnegative << std::endl;
    std::cout << "������������ � ��������� " << proz << std::endl;
    std::cout << "������������ ����� � ������� ��������� " << prozchot << std::endl;
    std::cout << "����� ����� ����� ������ � ��������� ������������� ������ " << deapsum;
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



