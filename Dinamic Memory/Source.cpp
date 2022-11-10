#include <iostream>
#include <time.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

int** Allocate(const int rows, const int cols);
void FillRand(int arr[], int n, int minRand = 0, int maxRand=100);
void Print(int arr[], int n);

int* push_back(int arr[], int& n, int new_element);
int* push_front(int arr[], int& n, int new_element);
int* insert (int arr[], int& n, int new_element, int numer_element);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int numer_element);

void Print(int** arr, const int rows, const int cols);
int** push_row_back(int** arr, int& rows, int cols);
int** pop_row_back(int** arr, int& rows, int cols);
void push_col_back(int** arr, int rows, int& cols);
void pop_col_back(int** arr, int rows, int& cols);
int** push_row_front(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, int cols);
int** push_col_front(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);


void Clear(int** arr, const int rows);

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
	int** arr = Allocate(rows, cols);
	

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

int** Allocate(const int rows, const int cols)
{
	//1) Выделяем память под массив указателей
	int** arr = new int* [rows];

	//2) Создаем строки двумерного массива
	for (int i = 0; i < rows;i++)
	{
		arr[i] = new int [cols] {};
	}
	return arr;
}



void FillRand(int arr[], int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand-minRand)+minRand;
	}
}


void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}

int* push_back(int arr[], int& n, int new_element)
{
	int* arr_buffer = new int[n+1]{};
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
int* push_front(int arr[], int& n, int new_element)
{
	int* arr_buffer = new int[n + 1];
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

int* insert(int arr[], int& n, int new_element, int numer_element)
{
	
	int* arr_buffer = new int[n+1];
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

int* pop_back(int arr[], int& n)
{
	int* arr_buffer = new int[n-1];
	for (int i = 0; i < n-1;i++)
	{
		arr_buffer[i] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	n--;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	int* arr_buffer = new int[n-1];
	for (int i = 1; i < n;i++)
	{
		arr_buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = arr_buffer;
	n--;
	return arr;
}

int* erase(int arr[], int& n, int numer_element)
{
	int* arr_buffer = new int[n-1];
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

void Clear(int** arr, const int rows)
{
	//1)Удаляем строки двумерного динамического массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	//2) Удаляем массив указателей:
	delete[] arr;
}

void Print(int** arr, const int rows, const int cols)
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

int** push_row_back(int** arr, int& rows, int cols)
{
	// 1) Создаем буфферный массив
	int** buffer = new int* [rows+1]{};
	
	//2) Копируем адреса строк из исходного массива в буферный
	for (int i = 0; i < rows;i++) buffer[i] = arr[i];
	
	//3) Удаляем исходный массив:
	delete[] arr;
	
	//4) Подменяем адрес старого массива указателей  адресом нового массива
	arr=buffer;

	//5)Теперь в массиве указателей есть место для добавления строки в конец массива
	arr[rows] = new int[cols] {};

	//6)После добавления строки в массив количество строк увеличивается на 1:
	rows++;

	//7)Возвращаем указатель на массив:
	return arr;

}

int** pop_row_back(int** arr, int& rows, int cols)
{
	//1)Удаляем последнюю строку из памяти:
	delete[] arr[rows - 1];

	//2)Переопределяем массив указателей:
	int** buffer = new int* [--rows]{};

	//3)Копируем исходный массив в буфферный:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	//4)Удаляем исходный массив указателей:
	delete[] arr;

	//5)Возвращаем массив на место вызова функции:
	return buffer;

}

void push_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols+1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++ ;
}

void pop_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1]{};
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

int** push_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows + 1]{};
	buffer[0] = new int [cols] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}

int** pop_row_front(int** arr, int& rows, int cols)
{
	delete[] arr[0];
	int** buffer = new int* [rows - 1]{};
	for (int i = 1; i < rows;i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

int** push_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
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

int** pop_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
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