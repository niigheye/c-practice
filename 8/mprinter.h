#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void showMatrix(double ** arr, int row, int col, int precision, int setwm, bool isScientific);
void showStaticMatrix(int(&arr)[10][10], const int SIZE_MAS);
void showStatistik(int n,int m, int x, int prec);
void showAsk(int(&arr)[10][10]);
