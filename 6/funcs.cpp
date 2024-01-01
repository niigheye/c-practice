#include "header.h"

void printMas(int* mas, int& size){
    for (int i=0; i< size; i++){
        cout << mas[i] << " ";
    }
    cout << endl;
}

void inputKeyCodes(ifstream& fin, int* keyIndexs, int& index){
    string line = " ";

    fin.open("../key.txt", ios::binary);
    unsigned char ch;
    while (fin >> noskipws >> ch) {
        // cout << ch << " " <<int(ch) << endl;
        if (int(ch) == 32){
            keyIndexs[index] %= 256;
            index++;
            // cout << "i found space" << endl;
            continue;
        }
        else{
            keyIndexs[index] += int(ch);
            // cout << "i found symbol to index:   " <<index << endl;
        }
    }
    // for(int j=0; j< sizeof(line); j++){
    // }
    fin.close();
}


void encodeSourceCodes(ifstream& fin, fstream& encodeOut, int* keys, int& keySize, int ** matrix){
    unsigned char ch;
    fin.open("../source.txt", ios::binary);
    encodeOut.open("../encoded.txt", ios::binary | ios::out);

    int z=0;

    while (fin >> noskipws >> ch) {
        cout << ch << " ";
        cout << (int)ch << " " << keys[z%keySize] << " " << (((int)(ch) + (keys[z%keySize])) % 256) << endl;
        encodeOut << (unsigned char)(((int)(ch) + (keys[z%keySize])) % 256);
        matrix[(int)(ch)] [(((int)(ch) + (keys[z%keySize])) % 256)] ++;
        //cout << indexs[z] << endl;
        z++;

    }
    fin.close();
    encodeOut.close();

}

void decodeFile(fstream& encoded, ofstream& decoded, int* keyIndexs, int keySize){
    encoded.open("../encoded.txt", ios::in | ios::binary);
    decoded.open("../decoded.txt", ios::binary);
    unsigned char ch;
    int z = 0;
    while (encoded >> noskipws >> ch) {
        cout << (int) ch << " " ;
        if ((int)ch - keyIndexs[z%keySize] < 0){
            cout << ((int)ch - keyIndexs[z%keySize] + 256) << endl;
            decoded << (unsigned char)((int)ch - keyIndexs[z%keySize] + 256);
        }
        else{
            cout <<((int)ch - keyIndexs[z%keySize]) << endl;
            decoded << (unsigned char)((int)ch - keyIndexs[z%keySize]);
        }

        z++;
    }
    encoded.close();
    decoded.close();
}

void outTable(ofstream& out, int ** arr ,int size){
    short SPACE = 5;
    out.open("../outTable.txt", ios::binary);
    out << "     ";
    bool outLine[256];
    bool outCol[256];
    bool flagLine, flagCol;

    for (int i=0; i < size; i++){
        flagLine = false;
        flagCol = false;
        for(int j=0; j< size; j++){
            if (arr[i][j] > 0){
                flagLine = true;
            }
            if (arr[j][i] > 0){
                flagCol = true;
            }
        }
        outLine[i]=false;
        outCol[i] = false;
        if (flagLine){
            outLine[i] = true;
            // cout << "in line: " << i << endl;
        }
        if(flagCol){
            outCol[i] = true;
            // cout << "in col: " << i << endl;
        }
    }

    //   s o u r c e
    // c
    // o
    // d
    // e
    // d
    int flag = 0;
    for (int i=0; i< size; i++){
        if (outCol[i] == 1) {
            out << setw(SPACE) << i;
        }
    }
     out << endl;
    for (int i=0; i< size; i++){
        flag = 0;
        if (outLine[i] == 1) {
            out << setw(SPACE) << i;
            flag = 1;
        }
        for (int j=0; j < size; j++){
            if(outCol[j] == 1){
                if (outLine[i] == 1){
                    out <<setw(SPACE)<< arr[i][j];
                }

            }
        }
        if (flag == 1){
            out << endl;
        }

    }

    out.close();

}

int** createMatrix(int size){
    int **matrix=new int*[size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new int[size];
    }
    for (int i=0; i < size; i++){
        for(int j=0; j< size; j++){
            matrix[i][j] = 0;
        }
    }
    return matrix;

}

void destroyMatrix(int ** arr, int size){
    for (int i=0; i< size; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
