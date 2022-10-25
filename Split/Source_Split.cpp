#include <iostream>
#include <time.h>
using namespace std;

template <typename T> void FillRand(T arr[], const int n);
template <typename T> void Print (T arr[], const int n);
template <typename T> int EVEN_COUNT(T arr[], const int n);
template <typename T> int ODD_COUNT(T arr[], const int n);


void main()
	{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	const int n=10;
	int arr[n] = {};
	FillRand(arr, n);
	cout << "Исходный массив: " << endl << endl;
	Print(arr, n);
	int n_even = EVEN_COUNT(arr, n);
	int n_odd = ODD_COUNT(arr, n);
	int* even = new int[n_even];
	int* odd = new int[n_odd];


	int j = 0, k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[j] = *(arr + i);
			j++;
		}
		else
		{
			odd[k] = arr[i];
			k++;
		}
	}
	cout << endl << "Четные элементы массива: " << endl << endl;
	Print(even, n_even);
	cout << endl << "Нечетные элементы массива: " << endl << endl;
	Print(odd, n_odd);
	delete[] even;
	delete[] odd;
	}

template <typename T> void FillRand(T arr[], const int n)
{
	for (int i = 0;i < n;i++)
	{
		arr[i] = rand() % 100;
	}
}

template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0;i < n;i++)
	{
		cout<<*(arr+i)<<"\t";
	}
	cout << endl;
}

template <typename T> int EVEN_COUNT(T arr[], const int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) count++;
		else continue;
	}
	return count;
}
template <typename T> int ODD_COUNT(T arr[], const int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(arr+i) % 2 != 0) count++;
		else continue;
	}
	return count;
}




