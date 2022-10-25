#include <iostream>
#include <time.h>
using namespace std;

void FillRand(int arr[], int n);
void Print(int arr[], int n);
void push_back(int arr[], int n, int new_element);
void push_front(int arr[], int n, int new_element);
void insert (int arr[], int n, int new_element, int numer_element);
void pop_back(int arr[], int n);
void pop_front(int arr[], int n);
void erase(int arr[], int n, int numer_element);

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	//������, ��� �������� ��� ���
	//arr[n] = 123;
	//����� �������������� ������
	//n++;
	int new_element;
	cout << endl<<"������� ��������, ������� ��������� �������� � ����� �������: "; cin >> new_element;
	push_back(arr, n, new_element);
	cout << endl << "������� ��������, ������� ��������� �������� � ������ �������: "; cin >> new_element;
	push_front(arr, n, new_element);
	int numer_element;
	cout << endl << "������� ��������, ������� ��������� �������� � ������: "; cin >> new_element;
	cout << endl << "������� ����� ��������, ����� �������� ��������� �������� ����� ������� � ������: "; cin >> numer_element;
	insert (arr, n, new_element, numer_element);
	pop_back(arr, n);
	pop_front(arr, n);
	cout << endl << "������� ����� ��������, ������� ��������� �������: "; cin >> numer_element;
	erase(arr, n, numer_element);
	delete[] arr;


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

void push_back(int arr[], int n, int new_element)
{
	int m = n+1;
	int* arr_buffer = new int[m];
	for (int i = 0; i < n; i++)
	{
		arr_buffer[i] = arr[i];
	}
	arr_buffer[n] = new_element;
	cout << endl<<"������� �������� � ����� �������: " << endl << endl;
	Print(arr_buffer, m);
	delete[] arr_buffer;
}
void push_front(int arr[], int n, int new_element)
{
	int m = n + 1;
	int* arr_buffer = new int[m];
	for (int i = 1; i <= n; i++)
	{
		arr_buffer[i] = arr[i-1];
	}
	arr_buffer[0] = new_element;
	cout << endl << "������� �������� � ������ �������: " << endl << endl;
	Print(arr_buffer, m);
	delete[] arr_buffer;
}

void insert(int arr[], int n, int new_element, int numer_element)
{
	int m = n + 1;
	int* arr_buffer = new int[m];
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
	cout << endl << "������� �������� � ������: " << endl << endl;
	Print(arr_buffer, m);
	delete[] arr_buffer;
}

void pop_back(int arr[], int n)
{
	int m = n-1;
	int* arr_buffer = new int[m];
	for (int i = 0; i < m;i++)
	{
		arr_buffer[i] = arr[i];
	}
	cout << endl << "������� ������ � ����� �������: " << endl << endl;
	Print(arr_buffer, m);
	delete[] arr_buffer;
}

void pop_front(int arr[], int n)
{
	int m = n - 1;
	int* arr_buffer = new int[m];
	for (int i = 1; i < n;i++)
	{
		arr_buffer[i-1] = arr[i];
	}
	cout << endl << "������� ������ � ������ �������: " << endl << endl;
	Print(arr_buffer, m);
	delete[] arr_buffer;
}

void erase(int arr[], int n, int numer_element)
{
	int m = n - 1;
	int* arr_buffer = new int[m];
	for (int i = 0; i < numer_element-1;i++)
	{
		arr_buffer[i] = arr[i];
	}
	for (int i = numer_element; i < n;i++)
	{
		arr_buffer[i-1] = arr[i];
	}
	cout << endl << "������� ������ � ������ �������: " << endl << endl;
	Print(arr_buffer, m);
	delete[] arr_buffer;
}