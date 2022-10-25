#include <iostream>
using namespace std;

void FillRand(int arr[], int n);
void Print(int arr[], int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	//������, ��� �������� ��� ���
	arr[n] = 123;
	//����� �������������� ������
	n++;
	Print(arr, n);
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