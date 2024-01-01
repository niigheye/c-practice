#include <iostream>
#include <iomanip>
#include <cmath>
using  namespace std;

double ** createMatrix(int row, int col);
void fillMatrix(double ** arr, int row, int col);
void destroyMatrix(double **arr, int row, int col);
void randomGenerate(int& row, int& col, int& prec);
void fillStaticMatrix(int(&arr)[10][10], const int SIZE_MAS);
int * getPointers(int(&arr)[10][10], const int SIZE_MAS);

