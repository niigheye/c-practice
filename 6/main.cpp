#include "header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int keyIndexs[40] = {}, keySize = 0, sourceSize = 0;
    unsigned char sourceIndexs[500] = {};
    int** matrix = createMatrix(256);

    ifstream keyInput, sourceInput;
    fstream encodeOut;
    ofstream decodeOut, outTable_stream;

    inputKeyCodes(keyInput, keyIndexs, keySize);
    encodeSourceCodes(sourceInput, encodeOut, keyIndexs, keySize, matrix);
    decodeFile(encodeOut, decodeOut, keyIndexs, keySize);
    outTable(outTable_stream, matrix, 256);
    destroyMatrix(matrix, 256);

    return 0;
}
