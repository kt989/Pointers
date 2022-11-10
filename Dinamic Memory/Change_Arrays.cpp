#include "Change_Arrays.h"

template <typename T> T* push_back(T arr[], int& n, T new_element)
{
	T* arr_buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		arr_buffer[i] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	arr[n] = new_element;
	n++;
	return arr;
}
template <typename T> T* push_front(T arr[], int& n, T new_element)
{
	T* arr_buffer = new T[n + 1];
	for (int i = 1; i <= n; i++)
	{
		arr_buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr_buffer[0] = new_element;
	arr = arr_buffer;
	n++;
	return arr;
}

template <typename T> T* insert(T arr[], int& n, T new_element, int numer_element)
{

	T* arr_buffer = new T[n + 1];
	for (int i = 0; i < numer_element; i++)
	{
		arr_buffer[i] = arr[i];
	}
	arr_buffer[numer_element] = new_element;
	numer_element++;
	for (int i = numer_element; i <= n; i++)
	{
		arr_buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = arr_buffer;
	n++;
	return arr;
}

template <typename T> T* pop_back(T arr[], int& n)
{
	T* arr_buffer = new T[n - 1];
	for (int i = 0; i < n - 1;i++)
	{
		arr_buffer[i] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	n--;
	return arr;
}

template <typename T>T* pop_front(T arr[], int& n)
{
	T* arr_buffer = new T[n - 1];
	for (int i = 1; i < n;i++)
	{
		arr_buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	n--;
	return arr;
}

template <typename T>T* erase(T arr[], int& n, int numer_element)
{
	T* arr_buffer = new T[n - 1];
	for (int i = 0; i < numer_element - 1;i++)
	{
		arr_buffer[i] = arr[i];
	}
	for (int i = numer_element; i < n;i++)
	{
		arr_buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	n--;
	return arr;
}

template <typename T> T** push_row_back(T** arr, int& rows, int cols)
{
	// 1) ������� ��������� ������
	T** buffer = new T * [rows + 1]{};

	//2) �������� ������ ����� �� ��������� ������� � ��������
	for (int i = 0; i < rows;i++) buffer[i] = arr[i];

	//3) ������� �������� ������:
	delete[] arr;

	//4) ��������� ����� ������� ������� ����������  ������� ������ �������
	arr = buffer;

	//5)������ � ������� ���������� ���� ����� ��� ���������� ������ � ����� �������
	arr[rows] = new T[cols]{};

	//6)����� ���������� ������ � ������ ���������� ����� ������������� �� 1:
	rows++;

	//7)���������� ��������� �� ������:
	return arr;

}

template <typename T> T** pop_row_back(T** arr, int& rows, int cols)
{
	//1)������� ��������� ������ �� ������:
	delete[] arr[rows - 1];

	//2)�������������� ������ ����������:
	T** buffer = new T * [--rows]{};

	//3)�������� �������� ������ � ���������:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	//4)������� �������� ������ ����������:
	delete[] arr;

	//5)���������� ������ �� ����� ������ �������:
	return buffer;

}

template <typename T> void push_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template <typename T> void pop_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template <typename T> T** push_row_front(T** arr, int& rows, int cols)
{
	T** buffer = new T * [rows + 1]{};
	buffer[0] = new T[cols]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}

template <typename T> T** pop_row_front(T** arr, int& rows, int cols)
{
	delete[] arr[0];
	T** buffer = new T * [rows - 1]{};
	for (int i = 1; i < rows;i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

template <typename T> T** push_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}

template <typename T> T** pop_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0;j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}