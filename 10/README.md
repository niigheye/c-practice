<h1 style="font-size:15;">Formulation of the problem</h1>

- development of a program that implements the algorithm for calculating the inverse matrix using the Gauss-Jordan method;
- use of developed functions to solve systems of linear equations.

<h1 style="font-size:15;">Algorithm development</h1>

**List of functions:


void FillMatrix(double **matrix, int matrixValue) - fills the matrix to a two-dimensional array of type double, and also fills the right side of the matrix so that this part becomes one

double** matrix – a two-dimensional array consisting of a regular matrix of size matrixValue and an identity matrix of the same size

matrixValue – a variable to indicate the dimension of the array, which will be entered from the keyboard

void PrintMatrix(double **matrix, int matrixValue) - prints the matrix array, consisting of a regular matrix of size matrixValue, which will be entered from the keyboard and an identity matrix of the same size

void InputMatrix(double **matrix, int matrixValue) — input matrix values matrix size matrixValue

void InputMatrix(double *matrix, int matrixValue) – input of matrix values from one column for subsequent calculation

double Determinant(double** matrix, int matrixValue) - accepts a two-dimensional array of type double and returns the determinant of a matrix whose size is matrixValue (the function does not take into account the values of the matrix on the right, the identity matrix)

double determinantVal = 0.0 — the value of the determinant that will be returned

void ZeroColumn(double **matrix, int matrixValue, int column) - the function brings the column column to the form when all elements of the column, except the element with index column , are equal to zero, the element itself becomes equal to 1

void MatrixInvert(double **matrix, int matrixValue) – the function takes a matrix matrix with dimension matrixValue and turns the identity matrix into the inverse of the original one

void Multiply(double **matrix, int matrixValue, double *multMatrix, double *Answer) - the function multiplies a matrix of size matrixValue by a matrix of size matrixValuex1 and writes the result to the Answer matrix

void PrintMatrix(double *Answer, int matrixValue) – prints a one-dimensional Answer matrix of size matrixValuex1
