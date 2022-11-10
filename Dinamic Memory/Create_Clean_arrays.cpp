#include "Create_Clean_arrays.h"

template <typename T>T** Allocate(const int rows, const int cols)
{
	//1) Выделяем память под массив указателей
	T** arr = new T * [rows];

	//2) Создаем строки двумерного массива
	for (int i = 0; i < rows;i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}



template <typename T> void FillRand(T arr[], int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = double(rand() % 10000) / 100;
	}
}


template <typename T> void Print(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}



template <typename T> void Clear(T** arr, const int rows)
{
	//1)Удаляем строки двумерного динамического массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	//2) Удаляем массив указателей:
	delete[] arr;
}

template <typename T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

