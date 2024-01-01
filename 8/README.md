<h1 style="font-size:15;"> Formulation of the problem </h1>

Objectives:
- creation of two-dimensional dynamic arrays;
- matrix processing;
- demonstration of structured programming technology using the example of a program for sorting matrix rows;
- use of files to store source data;
- formatted output of matrices on the screen.
  
Task.
Create a square matrix A of size N*N (where N is entered from the keyboard) with elements A i,j = 1 / (j!)i. Depending on the size of the matrix and the width of the output field of the matrix element, ensure a user-friendly display of the matrix on the screen. Output a matrix of size N*M to the screen as a function in order to use it in subsequent laboratory work for printing two-dimensional arrays.
The matrix must be passed to the functions being developed through parameters.
Without changing the code of the matrix output function, print the matrix in “scientific” format and in fixed-point format with a precision of 8 decimal places.

<h1 style="font-size:15;"> Algorithm development </h1>

List of header.h functions:

double ** createMatrix(int row, int col);
Creates a matrix of dimensions row x col;

void fillMatrix(double ** arr, int row, int col);
Fills the matrix (row x col) following the recursive formula
Input data:
• double** arr – reference to the matrix
• int row – number of rows
• int col – number of columns

void destroyMatrix(double** arr, int row, int col);
Clears a two-dimensional dynamic array (row x col) arr from memory
Input data:
• double** arr – dynamic array
• int row – row length
• int col – number of columns


void randomGenerate(int& row, int& col, int& prec);
Randomly generates row, col and prec
Input data:
• int prec - precision
• int row – row length
• int col – number of columns

void fillStaticMatrix(int(&arr)[10][10], const int SIZE_MAS);
Fills a static array (arr[i][j] = 10 * i + j)
Input data:
• int(&arr)[10][10] – two-dimensional array
• const int SIZE_MAS - array size


List of mprinter.h functions:

void showMatrix(double ** arr, int row, int col, int precision, int setwm, bool isScientific);
Displays a dynamic two-dimensional array on the screen using the passed link with the required indentation and precision
Input data:
• double** arr – array reference
• int row – number of rows
• int col – number of columns
• int precision – precision
• int setwm – indent
• bool isScientific – scientific data output flag





void showStaticMatrix(int(&arr)[10][10], const int SIZE_MAS);
Prints a static two-dimensional array to the screen
Input data:
• int(&arr)[10][10 - static two-dimensional array 10 by 10
• const int SIZE_MAS – array size


void showStatistik(int n,int m, int x, int prec);
Displays statistics
Input data:
• int n – number of lines
• int m – number of columns
• int x – x from the filling formula
• int prec – accuracy
void showAsk(int(&arr)[10][10]);
Prints questions on an array
Input data:
• int(&arr)[10][10] – two-dimensional array
