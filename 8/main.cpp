#include "header.h"
#include "mprinter.h"

int main(int, char**){
    const int SIZE_MAS = 10;
    int size_row = 3, size_col= 3, myprec= 3,  matrixStatic[SIZE_MAS][SIZE_MAS], x= 1 ;
    randomGenerate(size_row, size_col, myprec);
    double **matrix = createMatrix(size_row,size_col);
    fillMatrix(matrix, size_row,size_col);
    fillStaticMatrix(matrixStatic, SIZE_MAS);
    showStatistik(size_row, size_col, x, myprec);
    showMatrix(matrix,size_row,size_col, myprec, 15, 0);
    showStaticMatrix(matrixStatic, SIZE_MAS);
    showAsk(matrixStatic);
    destroyMatrix(matrix,size_row,size_col);
    return 0; }

