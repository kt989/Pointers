//Pointers
#include <iostream>
using namespace std;

//#define POINTERS_BASICS


void main()
{
	setlocale(LC_ALL, "");
	
#ifdef POINTERS_BASICS

	int a = 2;
	int* pa = &a;
	cout << a << endl; //вывод значения переменной
	cout << &a << endl; //взятие адреса переменной а прямо при выводе
	cout << pa << endl; // выод адреса переменной а, записанный в указатель pa
	cout << *pa << endl;//разименовываем указатель pa и получаем значение,
	                    // которое хранится по адресу*/

#endif // POINTERS_BASICS
	
	
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n;i++)
	{
		cout << *(arr + i) << "\t";
	}


}