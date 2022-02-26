#include "pch.h"
#include "..\labaratory\math\math.h"


TEST(Test, Test_invert_function) {
	double* arr = new double[3]{ -1, 0, -224 };
	int n = 3;//размер начального массива
	double* result = new double[3]{ 1, 0, 224 };
	invert(arr, n);

	for (int i = 0; i < 3; i++)
		EXPECT_EQ(result[i], arr[i]);

	delete[] arr;
	delete[] result;
}

TEST(Test, Test_matrix_invert_function) {	
	double** matrix = new double* [2];
	double** result = new double* [2];
	for (int i = 0; i < 2; i++) {
		matrix[i] = new double[2];
		result[i] = new double[2];
	}
	matrix[0][0] = 1;
	matrix[0][1] = -5;
	matrix[1][0] = 0;
	matrix[1][1] = 17;

	result[0][0] = -1;
	result[0][1] = 5;
	result[1][0] = 0;
	result[1][1] = -17;

	invert(matrix, 2);

	EXPECT_EQ(**result, **matrix);

	for (int i = 0; i < 2; ++i) {
		delete[] matrix[i];
		delete[] result[i];
	}
	delete[] matrix;
	delete[] result;
}

TEST(Test, Test_ydal_function) {
	double* array = new double[10]{ -1, 0, -224 ,-21, 30, -224 ,-11, 30, -8 ,17};
	int n = 10;//размер начального массива
	int U = 17;
	double* result = new double[10]{ -1, 0, -224 ,-21, 30, -224 ,-11, 30, -8 };
	ydal(array, n, U);

	for (int i = 0; i < 10; i++)
		EXPECT_EQ(result[i], array[i]);

	delete[] array;
	delete[] result;
}

TEST(Test, Test_DIAG_minus_function) {
	double** matrix = new double* [2];
	double** result = new double* [2];
	for (int i = 0; i < 2; i++) {
		matrix[i] = new double[2];
		result[i] = new double[2];
	}
	double U = 19;

	matrix[0][0] = 11;
	matrix[0][1] = -5;
	matrix[1][0] = 20;
	matrix[1][1] = 17;

	result[0][0] = -19;
	result[0][1] = -5;
	result[1][0] = 20;
	result[1][1] = -19;

	DIAG_minus(matrix, 2, U);

	EXPECT_EQ(**result, **matrix);

	for (int i = 0; i < 2; ++i) {
		delete[] matrix[i];
		delete[] result[i];
	}
	delete[] matrix;
	delete[] result;
}
*/