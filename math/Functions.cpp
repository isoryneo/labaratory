#include "math.h"
//замена всех чисел < 0 самим 0
void invert(double* a, int n)
{
	for (int i = 0; i < n; i++) {
		a[i] *= -1;		
	}
}
//перегрузка функции, чтобы работала и с квадратными матрицами
void invert(double** a, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] *= -1;
		}
	}
}
//определение функции дл€ удалени€ элемента == U
void ydal(double* x, int& n,double U)
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == U) {
			for (int j = i; j < n - 1; j++)
			{
				x[j] = x[j + 1];
				k = 1;
			}
			n = n - 1;
		}
	}
	if (k == 0) cout << "\n Ёлемента " << U <<"  в векторе не было.";
}
//определение функции дл€ замены всех элементов на диагонале матрицы на заданный элемент с измененным знаком
void DIAG_minus(double** Y, int n, double U)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Y[i][j] = -U;
			}
		}
	}
}