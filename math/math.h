#include <iostream>

using namespace std;

//����� ������� � �������
void output_array(double* array_numb, int array_size);
//����� ������� � �������
void output_matrix(double** matrix_int_data, int matrix_size);
void invert(double* a, int n);
void invert(double** a, int n);
void ydal(double* x, int& n, double U);
//����������� ������� ��� ������ ���� ��������� �� ��������� ������� �� �������� �������
void DIAG_minus(double** Y, int n, double U);