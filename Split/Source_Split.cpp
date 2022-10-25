#include <iostream>
#include <time.h>
using namespace std;

template <typename T> void FillRand(T arr[], const int n);
template <typename T> void Print (T arr[], const int n);
template <typename T> int EVEN_COUNT(T arr[], const int n);
template <typename T> int ODD_COUNT(T arr[], const int n);
//template <typename T> void FillRand_EVEN_ODD(T arr[], const int n, T brr[], int m, T crr[], int f);

void main()
	{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	const int n=10;
	int arr[n] = {};
	FillRand(arr, n);
	Print(arr, n);
	int n_even = EVEN_COUNT(arr, n);
	int n_odd = ODD_COUNT(arr, n);
	int* even = new int[n_even];
	int* odd = new int[n_odd];
	FillRand(even, n_even);
	//FillRand_EVEN_ODD(arr, n, even, n_even, odd, n_odd);// почему-то через функцию не работает: пишет, что even и odd identifier not found
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
	Print(even, n_even);
	Print(odd, n_odd);
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

/*template <typename T> void FillRand_EVEN_ODD(T arr[], const int n, T brr[], int m, T crr[], int f)
{
	int j = 0, k=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[j]=*(arr+i);
			j++;
		}
		else 
		{
			odd[k] = arr[i];
			k++;
		}
	}
}*/

