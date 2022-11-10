#include <iostream>
#include <time.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

template <typename T>T** Allocate(const int rows, const int cols);
template <typename T> void FillRand(T arr[], int n, int minRand = 0, int maxRand=100);
template <typename T> void Print(T arr[], int n);

template <typename T>T* push_back(T arr[], int& n, T new_element);
template <typename T>T* push_front(T arr[], int& n, T new_element);
template <typename T>T* insert (T arr[], int& n, T new_element, int numer_element);
template <typename T>T* pop_back(T arr[], int& n);
template <typename T>T* pop_front(T arr[], int& n);
template <typename T>T* erase(T arr[], int& n, int numer_element);

template <typename T> void Print(T** arr, const int rows, const int cols);
template <typename T> T** push_row_back(T** arr, int& rows, int cols);
template <typename T> T** pop_row_back(T** arr, int& rows, int cols);
template <typename T> void push_col_back(T** arr, int rows, int& cols);
template <typename T> void pop_col_back(T** arr, int rows, int& cols);
template <typename T> T** push_row_front(T** arr, int& rows, int cols);
template <typename T> T** pop_row_front(T** arr, int& rows, int cols);
template <typename T> T** push_col_front(T** arr, int rows, int& cols);
template <typename T> T** pop_col_front(T** arr, int rows, int& cols);


template <typename T> void Clear(T** arr, const int rows);

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	//Прежде, чем написать вот так
	//arr[n] = 123;
	//нужно переопределить память
	//n++;
	int new_element;
	cout << endl<<"Введите значение, которое требуется добавить в конец массива: "; cin >> new_element;
	arr=push_back(arr, n, new_element);
	cout << endl << "Элемент добавлен в конец массива: " << endl << endl;
	Print(arr, n);

	cout << endl << "Введите значение, которое требуется добавить в начало массива: "; cin >> new_element;
	arr=push_front(arr, n, new_element);
	cout << endl << "Элемент добавлен в начало массива: " << endl << endl;
	Print(arr, n);
	

	int numer_element;
	cout << endl << "Введите значение, которое требуется добавить в массив: "; cin >> new_element;
	cout << endl << "Введите номер элемента, после которого требуется добавить новый элемент в массив: "; cin >> numer_element;
	arr=insert (arr, n, new_element, numer_element);
	cout << endl << "Элемент добавлен в массив: " << endl << endl;
	Print(arr, n);

	arr=pop_back(arr, n);
	cout << endl << "Элемент удален с конца массива: " << endl << endl;
	Print(arr, n);

	arr=pop_front(arr, n);
	cout << endl << "Элемент удален с начала массива: " << endl << endl;
	Print(arr, n);

	cout << endl << "Введите номер элемента, который требуется удалить: "; cin >> numer_element;
	arr=erase(arr, n, numer_element);
	cout << endl << "Элемент удален из массива: " << endl << endl;
	Print(arr, n);
	
#endif

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "\nВведите количество элементов строки: "; cin >> cols;


	///////////////////////////////////////////////////////////////
	//////////Объявление двумерного динамического массива /////////
	///////////////////////////////////////////////////////////////
	
	typedef float DataType;
	DataType** arr = Allocate<DataType>(rows, cols);
	

	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "push_row_back:\n";
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows-1], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "pop_row_back:\n";
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "push_col_back: \n";
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	cout << "pop_col_back: \n";
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "push_row_front: \n";
	arr=push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "pop_row_front: \n";
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "push_col_front: \n";
	arr = push_col_front(arr, rows, cols);
	for (int i = 0;i < rows;i++) arr[i][0] = rand() % 1000;
	Print(arr, rows, cols);

	cout << "pop_col_front: \n";
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
	///////////////////////////////////////////////////////////////
    //////////Удаление двумерного динамического массива ///////////
    ///////////////////////////////////////////////////////////////

	
#endif // DYNAMIC_MEMORY_2

}

template <typename T>T** Allocate(const int rows, const int cols)
{
	//1) Выделяем память под массив указателей
	T** arr = new T* [rows];

	//2) Создаем строки двумерного массива
	for (int i = 0; i < rows;i++)
	{
		arr[i] = new T [cols] {};
	}
	return arr;
}



template <typename T> void FillRand(T arr[], int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = double(rand() % 10000)/100;
	}
}


template <typename T> void Print(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}

template <typename T> T* push_back(T arr[], int& n, T new_element)
{
	T* arr_buffer = new T[n+1]{};
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
	
	T* arr_buffer = new T[n+1];
	for (int i = 0; i < numer_element; i++)
	{
		arr_buffer[i] = arr[i];
	}
	arr_buffer[numer_element] = new_element;
	numer_element++;
	for (int i = numer_element; i <=n ; i++)
	{
		arr_buffer[i] = arr[i-1];
	}
	delete[] arr;
	arr = arr_buffer;
	n++;
	return arr;
}

template <typename T> T* pop_back(T arr[], int& n)
{
	T* arr_buffer = new T[n-1];
	for (int i = 0; i < n-1;i++)
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
	T* arr_buffer = new T[n-1];
	for (int i = 1; i < n;i++)
	{
		arr_buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	n--;
	return arr;
}

template <typename T>T* erase(T arr[], int& n, int numer_element)
{
	T* arr_buffer = new T[n-1];
	for (int i = 0; i < numer_element-1;i++)
	{
		arr_buffer[i] = arr[i];
	}
	for (int i = numer_element; i < n;i++)
	{
		arr_buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	n--;
	return arr;
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
			cout << arr[i][j]<< "\t";
		}
		cout << endl;
	}
}

template <typename T> T** push_row_back(T** arr, int& rows, int cols)
{
	// 1) Создаем буфферный массив
	T** buffer = new T* [rows+1]{};
	
	//2) Копируем адреса строк из исходного массива в буферный
	for (int i = 0; i < rows;i++) buffer[i] = arr[i];
	
	//3) Удаляем исходный массив:
	delete[] arr;
	
	//4) Подменяем адрес старого массива указателей  адресом нового массива
	arr=buffer;

	//5)Теперь в массиве указателей есть место для добавления строки в конец массива
	arr[rows] = new T[cols] {};

	//6)После добавления строки в массив количество строк увеличивается на 1:
	rows++;

	//7)Возвращаем указатель на массив:
	return arr;

}

template <typename T> T** pop_row_back(T** arr, int& rows, int cols)
{
	//1)Удаляем последнюю строку из памяти:
	delete[] arr[rows - 1];

	//2)Переопределяем массив указателей:
	T** buffer = new T* [--rows]{};

	//3)Копируем исходный массив в буфферный:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	//4)Удаляем исходный массив указателей:
	delete[] arr;

	//5)Возвращаем массив на место вызова функции:
	return buffer;

}

template <typename T> void push_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols+1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++ ;
}

template <typename T> void pop_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols-1]{};
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template <typename T> T** push_row_front(T** arr, int& rows, int cols)
{
	T** buffer = new T* [rows + 1]{};
	buffer[0] = new T [cols] {};
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
	T** buffer = new T* [rows - 1]{};
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