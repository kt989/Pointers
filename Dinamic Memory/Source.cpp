#include <iostream>
#include <time.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int arr[], int n);
void Print(int arr[], int n);

int* push_back(int arr[], int& n, int new_element);
int* push_front(int arr[], int& n, int new_element);
int* insert (int arr[], int& n, int new_element, int numer_element);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int numer_element);

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

	//1) Выделяем память под массив указателей
	int** arr = new int* [rows];

	//2) Создаем строки двумерного массива
	for (int i = 0; i < rows;i++)
	{
		arr[i] = new int [cols] {};
	}

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

	///////////////////////////////////////////////////////////////
    //////////Удаление двумерного динамического массива ///////////
    ///////////////////////////////////////////////////////////////

	//1)Удаляем строки двумерного динамического массива


#endif // DYNAMIC_MEMORY_2

}

void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
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