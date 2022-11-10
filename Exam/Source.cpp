#include <iostream>
#include <time.h>
using namespace std;

void FillRand(int** arr, int rows, int cols);
void Print(int** arr, int rows, int cols);
void Delete_arr(int** arr, int rows);

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int rows, cols;
	cout << "¬ведите количество строк массива: "; cin >> rows;
	cout << "¬ведите количество элементов в строке массива: "; cin >> cols;
	int** arr = new int*[rows];
	for (int i = 0; i < rows;i++)
	{
		*(arr + i) = new int [cols] {};
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	Delete_arr(arr, rows);
}

void FillRand(int** arr, int rows, int cols)
{

	
	for (int i = 0; i < rows; i++)
	{
		for (int j=0; j < cols; j++)
		{
		    **(arr+j) = rand() % 100;
		}
	}
}
void Print(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j=0; j < cols; j++)
		{
			cout<<**(arr+j) << "\t";
		}
		cout << endl;
	}
}

void Delete_arr(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}