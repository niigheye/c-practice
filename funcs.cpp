#include "header.h"

void FillMatrix(double **matrix, int matrixValue)
{
	for (int row = 0; row < matrixValue + 1; row++)
	{
		matrix[row] = new double[matrixValue * 2];
	}
	for (int row = 0; row < matrixValue; row++)
	{
		for (int col = 0; col < matrixValue * 2; col++)
		{
			if (col == row + matrixValue)
			{
				matrix[row][col] = 1.0;
			}
			else
			{
				matrix[row][col] = 0.0;
			}
		}
	}
}

void PrintMatrix(double **matrix, int matrixValue)
{
	for (int row = 0; row < matrixValue; row++)
	{
		for (int col = 0; col < matrixValue * 2; col++)
		{
			if (col == matrixValue)
			{
				std::cout << std::setw(14) << "|";
			}
			if (matrix[row][col] == -0)
			{
				matrix[row][col] = 0;
			}
			std::cout << std::setw(14) << matrix[row][col];
		}
		std::cout << "\n";
	}
}

void InputMatrix(double **matrix, int matrixValue)
{
	for (int row = 0; row < matrixValue; row++)
	{
		for (int col = 0; col < matrixValue; col++)
		{
			std::cout << "\n row:" << row+1 << " col:" << col+1 << " Number:";
			std::cin >> matrix[row][col];
			std::cout << "\n";
		}
	}
}

void InputMatrix(double *matrix, int matrixValue)
{
	std::cout << "\nFill matrix to multiply with\n";
	for (int row = 0; row < matrixValue; row++)
	{
		std::cout << row + 1 << "row:";
		std::cin >> matrix[row];
		std::cout << "\n";
	}
}

double Determinant(double** matrix, int matrixValue) {
	if (matrixValue == 1) {
		return matrix[0][0];
	}

	if (matrixValue == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	double determinantVal = 0.0;
	for (int col = 0; col < matrixValue; ++col) {
		double** matrixNext = new double* [matrixValue - 1];
		for (int row = 0; row < matrixValue - 1; ++row) {
			matrixNext[row] = new double[matrixValue - 1];
		}

		for (int row = 1; row < matrixValue; ++row) {
			int col = 0;
			for (int k = 0; k < matrixValue; ++k) {
				if (k != col) {
					matrixNext[row - 1][col] = matrix[row][k];
					++col;
				}
			}
		}
		determinantVal += matrix[0][col] * Determinant(matrixNext, matrixValue - 1) * ((col % 2 == 0) ? 1 : -1);

		for (int row = 0; row < matrixValue - 1; ++row) {
			delete[] matrixNext[row];
		}
		delete[] matrixNext;
	}
	return determinantVal;
}

void ZeroColumn(double **matrix, int matrixValue, int column)
{
	int temp = 1;
	double koef;
	std::swap(matrix[column], matrix[0]);
	while (matrix[0][column] == 0)
	{
		std::swap(matrix[0], matrix[temp]);
		temp++;
	}

	double k = matrix[0][column];

	for (int row = 0; row < matrixValue; row++)
	{
		for (int col = 0; col < matrixValue * 2; col++)
		{
			if (row == 0)
			{

				matrix[row][col] /= k;
			}
			else if (column != matrixValue)
			{
				while (matrix[row][column] != 0)
				{
					koef = matrix[row][column];
					for (int col1 = 0; col1 < matrixValue * 2; col1++)
					{
					
						matrix[row][col1] -= matrix[0][col1] * koef;
					}
				}
			}
		}
	}
}

void MatrixInvert(double **matrix, int matrixValue)
{
	for (int col = 0; col < matrixValue; col++)
	{
		ZeroColumn(matrix, matrixValue, col);
		
	}
	std::swap(matrix[0], matrix[matrixValue]);
	for (int row = 1; row < matrixValue; row++)
	{

		std::swap(matrix[row], matrix[row - 1]);
	}

	std::swap(matrix[matrixValue], matrix[matrixValue - 1]);
}

void Multiply(double **matrix, int matrixValue, double *multMatrix, double *Answer)
{
	for (int row = 0; row < matrixValue; row++)
	{
		Answer[row] = 0;
		for (int col = 0; col < matrixValue; col++)
		{
			Answer[row] += matrix[row][col + matrixValue] * multMatrix[col];
		}
	}
}
void PrintMatrix(double *Answer, int matrixValue)
{
	for (int row = 0; row < matrixValue; row++)
	{
		std::cout << "\nx" << row + 1 << ":" << Answer[row];
	}
}
