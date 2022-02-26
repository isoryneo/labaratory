#include "functions.h"
#include "math\math.h"



//������� ��� ��������� ������������� ���� �������� � ������
void initialization(double* arr_1, double* arr_2, int arr_size_1, int arr_size_2, double** matrix, int matrix_size) {
	
	for (int i = 0; i < arr_size_1; i++)
		arr_1[i] = i - i * rand() % 255 - 100;//���������� ���������� ����������

	for (int i = 0; i < arr_size_2; i++)
		arr_2[i] = i + rand() % 255 - 100;//���������� ���������� ����������

	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++) {
			matrix[i][j] = rand() % 255 - 100;//���������� ���������� ����������
		}
}
