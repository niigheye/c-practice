#pragma once
#include <iostream>
#include <iomanip>

void FillMatrix(double **matrix, int matrixValue);
void PrintMatrix(double **matrix, int matrixValue);
void InputMatrix(double **matrix, int matrixValue);
void MatrixInvert(double **matrix, int matrixValue);
void InputMatrix(double *matrix, int matrixValue);
void Multiply(double **matrix, int matrixValue, double *multMatrix, double *Answer);
void PrintMatrix(double *Answer, int matrixValue);
double Determinant(double** matrix, int size);
