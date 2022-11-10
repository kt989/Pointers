#include "include_files.h"
#include "Change_Arrays.h"
#include "Change_Arrays.cpp"
#include "Create_Clean_arrays.h"
#include "Create_Clean_arrays.cpp"


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2



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

