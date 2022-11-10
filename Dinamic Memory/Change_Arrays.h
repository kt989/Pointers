#pragma once
#include"Change_Arrays.h"

template <typename T>T* push_back(T arr[], int& n, T new_element);
template <typename T>T* push_front(T arr[], int& n, T new_element);
template <typename T>T* insert(T arr[], int& n, T new_element, int numer_element);
template <typename T>T* pop_back(T arr[], int& n);
template <typename T>T* pop_front(T arr[], int& n);
template <typename T>T* erase(T arr[], int& n, int numer_element);

template <typename T> T** push_row_back(T** arr, int& rows, int cols);
template <typename T> T** pop_row_back(T** arr, int& rows, int cols);
template <typename T> void push_col_back(T** arr, int rows, int& cols);
template <typename T> void pop_col_back(T** arr, int rows, int& cols);
template <typename T> T** push_row_front(T** arr, int& rows, int cols);
template <typename T> T** pop_row_front(T** arr, int& rows, int cols);
template <typename T> T** push_col_front(T** arr, int rows, int& cols);
template <typename T> T** pop_col_front(T** arr, int rows, int& cols);