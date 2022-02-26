#include <iostream>

using namespace std;

//вывод вектора в консоль
void output_array(double* array_numb, int array_size);
//вывод матрицы в консоль
void output_matrix(double** matrix_int_data, int matrix_size);
void invert(double* a, int n);
void invert(double** a, int n);
void ydal(double* x, int& n, double U);
//определение функции для замены всех элементов на диагонале матрицы на заданный элемент
void DIAG_minus(double** Y, int n, double U);