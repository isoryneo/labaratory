#include "functions.h"
#include "math\math.h"
#include <boost\program_options.hpp>

#pragma region BOOST
//для работы в консоле
using namespace boost::program_options;

void on_arr_size_1(int number)
{
	std::cout << "array_size_1: " << number << '\n';
}
void on_arr_size_2(int number)
{
	std::cout << "array_size_2: " << number << '\n';
}
void on_matr_size(int number)
{
	std::cout << "matrix_size: " << number << '\n';
}
#pragma endregion

void main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//стандартные значения размерностей векторов и матриц
	int arr_size_1 = 5, arr_size_2 = 10;
	int matrix_size = 4;
#pragma region BOOST	
	try//работа через командную строку
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Help screen")
			("array_size_1", value<int>()->notifier(on_arr_size_1), "array_size_1")//размер векторов
			("array_size_2", value<int>()->notifier(on_arr_size_2), "array_size_2")//размер векторов
			("matrix_size", value<int>()->notifier(on_matr_size), "Matrix_size");//размер матриц

		variables_map vm;
		//пишем в консоль чтобы изменить размеры
		//labaratory --array_size_1 7 --array_size_2 3
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_1")) {
			std::cout << "Array_size_1: " << vm["array_size_1"].as<int>() << '\n';
			arr_size_1 = vm["array_size_1"].as<int>();//записываем в наш размер значение из командной строки
		}
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_2")) {
			std::cout << "Array_size_2: " << vm["array_size_2"].as<int>() << '\n';
			arr_size_2 = vm["array_size_2"].as<int>();//записываем в наш размер значение из командной строки
		}
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("matrix_size")) {
			std::cout << "Matrix_size: " << vm["matrix_size"].as<int>() << '\n';
			matrix_size = vm["matrix_size"].as<int>();//записываем в наш размер значение из командной строки
		}
			}
	catch (const error& ex)
	{
		std::cerr << ex.what() << '\n';
	}
#pragma endregion
	//объявление динамических векторов и матриц 
	double* array_1 = new double[arr_size_1];
	double* array_2 = new double[arr_size_2];

	double** matrix = new double* [matrix_size];

	for (int i = 0; i < matrix_size; i++) matrix[i] = new double[matrix_size];
	

	//начальная инициализация
	initialization(array_1, array_2, arr_size_1, arr_size_2, matrix, matrix_size);
	printf("\nНачальный вектор 1: ");
	output_array(array_1, arr_size_1);
	printf("\nНачальный вектор 2: ");
	output_array(array_2, arr_size_2);
	printf("\nНачальная матрица: \n");
	output_matrix(matrix, matrix_size);
	
	invert(array_1, arr_size_2);
	printf("\nВектор после функции invert: \n");
	output_array(array_1, arr_size_2);

	invert(matrix, matrix_size);
	printf("\nМатрица после функции invert: \n");
	output_matrix(matrix, matrix_size);

	printf("\nВектор после функции U_U: \n");
	ydal(array_1, arr_size_1, 33);
	output_array(array_1, arr_size_1);

	printf("\nВектор после функции DIAG: \n");
	DIAG_minus(matrix, matrix_size, 22.122);
	output_matrix(matrix, matrix_size);
	
	cout << endl;
	system("pause");
}


