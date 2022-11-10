#pragma once
#include "include_files.h"

template <typename T>T** Allocate(const int rows, const int cols);
template <typename T> void FillRand(T arr[], int n, int minRand = 0, int maxRand = 100);
template <typename T> void Print(T arr[], int n);
template <typename T> void Print(T** arr, const int rows, const int cols);
template <typename T> void Clear(T** arr, const int rows);