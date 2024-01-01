#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void inputKeyCodes(ifstream& fin, int* indexs, int& index);
void encodeSourceCodes(ifstream& fin, fstream& encodeOut, int* keys, int& keySize, int** matrix);

void decodeFile(fstream& encoded, ofstream& decoded, int* keyIndexs, int keySize);
void printMas(int* mas, int& size);
void outTable(ofstream& out, int** arr, int size);

int** createMatrix(int size);
void destroyMatrix(int** arr, int size);
