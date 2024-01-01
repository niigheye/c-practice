#include "header.h"

int main()
{
	system("chcp 1251");
	int matrixValue;
	std::cout << "Enter Matrix size:";
	std::cin >> matrixValue;
	double **matrix = new double *[matrixValue];

	FillMatrix(matrix, matrixValue);
	InputMatrix(matrix, matrixValue);

	if (Determinant(matrix, matrixValue) == 0.0)
	{
		std::cout << "\nMatrix can't be inverted!!\n";
		return -1;
	}

	std::cout << "\nInverted:\n";
	MatrixInvert(matrix, matrixValue);
	PrintMatrix(matrix, matrixValue);

	std::cout << "\nMultiply with 1-column matrix:";
	double *multMatrix = new double[matrixValue];
	double *Answer = new double[matrixValue];
	InputMatrix(multMatrix, matrixValue);
	Multiply(matrix, matrixValue, multMatrix, Answer);

	PrintMatrix(Answer, matrixValue);

	return 0;
}

