#include "header.h"

int fact(int n){
    if (n < 1) return -1;
    long long s=1;
    for (int i=2; i <= n ; i++){
        s*=i;
    }
    return s;
}

double ** createMatrix(int row, int col){
    double ** arr = new double*[row];
    for (int i=0; i< row; i++){
        arr[i] = new double[col];
    }
    return arr;
}

void fillMatrix(double ** arr, int row, int col){
    int j;
    for (int i=0 ; i < row; i++){
        j = i;
        arr[i][i]=1;
        if (j + 1 <= col){
            arr[i][j+1] = 1/pow(fact(j+2),i+1);
        }
        if(j-1 >=0){
            //cout << "i | j = " << i << " | " << j << endl;
            arr[i][j-1] = pow(-1,i+1)/pow(fact(j),i+1);
        }
        for(int j = i+2; j < col; j++ ){
             arr[i][j] = arr[i][j-1]/pow(j+1,i+1);
        }
        for (int j =  i - 2; j >= 0; j--){
            //cout << arr[i][j+1] << " "<<pow(j+2,i+1) << endl;
            arr[i][j] = arr[i][j+1] * pow(j+2,i+1);
        }
    }
}


void destroyMatrix(double **arr, int row, int col){
    for (int i=0 ; i< row; i++){
        delete[] arr[i];
    }
    delete[] arr;  
}

void randomGenerate(int& row, int& col, int& prec){
    col = rand()%8 + 8;
    row = rand()%8 + 8;
    prec = rand() % 6 + 3;
}

void fillStaticMatrix(int(&arr)[10][10], const int SIZE_MAS){
    for(int i=0; i< SIZE_MAS; i++){
        for (int j= 0; j< SIZE_MAS ; j++){
            arr[i][j] = i * SIZE_MAS + j;
        }
    }
}
