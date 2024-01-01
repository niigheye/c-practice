#include "mprinter.h"
void showSplit(){
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
}
void showBorder(){
    cout << endl << "=======================================================================================================" << endl;
}

void showStatistik(int n,int m, int x, int prec){
    showBorder();
    cout << endl;
    cout  << setw(10)<< "Matrix " << n <<" x " << m<< endl << setw(6)<< "X: " << x << endl  << setw(14)<< "Precision: "  << prec << endl;
    showBorder();
}

void showMatrix(double ** arr, int row, int col,int precision , int setwm, bool isScientific){
    showBorder();
    const int MAX_ROW = 80;
    int count = floor(MAX_ROW / setwm);
    int row_count = ceil(col*1.0/count);
    //cout << "count " <<count << " row_count: " << row_count << " " << col/count << endl;
    for (int c = 0 ; c < row_count; c++){
        for(int i=0; i< row; i++){
            for (int j=c*count; j< (c + 1) * count; j++){
                if (j < col){
                    if (isScientific){
                        cout <<setw(setwm) << scientific << setprecision(precision) << arr[i][j] << " ";
                    }
                    else{
                        cout <<setw(setwm) << fixed << setprecision(precision) << arr[i][j] << " ";
                    }
                    //cout << setw(setwm)  << i << " | " << j << " ";
                }
            }
            if (i+1 != row){ cout << endl; }
            
        }
        if (c+1 != row_count){ showSplit(); }
        
    }
    showBorder();
}

void showStaticMatrix(int(&arr)[10][10], const int SIZE_MAS){
    showBorder();
    for(int i=0; i< SIZE_MAS; i++){
        cout << setw(30) << " ";
        for(int j=0 ;  j < SIZE_MAS; j++){
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
    showBorder();
}

//считаю адреса 
void showAsk(int(&arr)[10][10]){
    showBorder();
    cout<< setw(40) << arr<<"  "<<arr[0]<<"  "<<arr[2]<<endl;
    cout<< setw(40)<<arr[0][0]<<"  "<<**arr <<"  "<<*arr[0]<<endl;
    cout<< setw(40)<<*(*(arr+1))<<"  "<<*arr[1]<<endl;
    cout<< setw(40)<<*(arr[0]+1)<<"  " <<*(*arr+1)<<endl;
    cout<< setw(40)<<arr[0][20]<<"  "<<*(arr[0]+20)<<"  "<<*arr[2]<<endl;
    showBorder();
}

