#include <iostream>
using namespace std;

void strCmp(Dictionary mas[], char * word );
void strCpy(Dictionary mas[], char * word);
int strLen(char * word);
int Main();
void Filter(Dictionary* mas, int cur_len);
int SearchIndex(Dictionary* mas, char* word, int cur_len);
int SearchIndex(Dictionary mas[], char* word, int cur_len, char *lang);
void AddWords(Dictionary mas[], int &cur_len, const int max_len);
void DeleteWord(Dictionary* mas, int& cur_len);
void PrintDictionary(Dictionary mas[], int cur_len);
void Translate(Dictionary mas[], int cur_len, const int type);
void DictionaryToFile(Dictionary mas[], int cur_len);
void Fill(Dictionary *mas, int &cur_len);
