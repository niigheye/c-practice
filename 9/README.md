<h1 style="font-size:15;">Formulation of the problem</h1>

The English-Russian dictionary is built as an array of Dictionary structures. The structure contains an English word and its corresponding Russian word. The maximum dictionary size is 100 pairs of words.
Develop a program that:
• provides the formation of a dictionary (adding and deleting entries);
• writes a dictionary, sorted by English word meanings, to a file;
• provides viewing of the dictionary;
• translates words from English into Russian, using the binary search method in a sorted array to search for a word in the dictionary;
• translates words from Russian into English, using the brute force method to search for words in the dictionary;
The program must provide dialogue using a menu.
The initial number of words in the dictionary is 10.
To avoid problems associated with entering the Cyrillic alphabet, enter Russian words in Latin letters, for example: kot (cat), sobaka (dog), etc.


<h1 style="font-size:15;">Algorithm development</h1>

**List of functions:

int Menu() - a function for user interaction, returns an integer value n entered by the user for further actions, function calls

void Filter(Dictionary* mas, int cur_len) - sorts an array of structures using the bubble method after it is filled from the file, as well as after adding each pair of words
Dictionary mas[] - array of Dictionary structures, dictionary
int cur_len – current length of the array
bool isSorted - required to optimize sorting

int SearchIndex(Dictionary mas[], char word[31], int cur_len, char *lang) - finds the word word in the Dictionary array and returns its index, and if lang = eng, then the search occurs among English words, and if lang = rus search occurs among Russian words
Dictionary mas[] - array of Dictionary structures, dictionary
char* word – the word that the function searches for in the array
int cur_len – current length of the array
char* lang – language among whose words the function searches

void AddWords(Dictionary mas[], int &cur_len, const int max_len) - the function adds a structure to mas consisting of English and Russian words, respectively, filters the array after that and checks for fullness.
Dictionary mas[] - array of Dictionary structures, dictionary
int cur_len – current length of the array, use the link to change its value for later use
const int max_len – the maximum length of the array, we use it to avoid going beyond the array boundaries
char eng1[31] – the English word that the function adds to the array, entered from the keyboard
char rus1[31] – the Russian word that the function adds to the array, entered from the keyboard
char state – by default “y”, entered from the keyboard after adding a pair of words, with “y” it continues working (and adds another pair).

void DeleteWord(Dictionary mas[], int &cur_len) - function deletes a two-word structure from the Dictionary mas structure array
Dictionary mas[] - array of Dictionary structures, dictionary
int cur_len – current length of the array, use the link to change its value for later use
char* word = new char[31] – the word, the structure with which we must remove from the array, is entered from the keyboard

void PrintDictionary(Dictionary mas[], int cur_len) - prints an array of mas Dictionary structures to the console
Dictionary mas[] - array of Dictionary structures, dictionary
int cur_len – current length of the array

void Translate(Dictionary mas[], int cur_len, const int type) - the function translates the word.
Dictionary mas[] - array of Dictionary structures, dictionary
int cur_len – current length of the array
char word[31] – the word that the program will translate
int I – index of the structure from the mas array in which this word is located
const int type - an integer, with a value of 1 it searches for a word as English and translates it into Russian, and with a value of 0 it searches for a word as Russian and translates it into English accordingly.

void DictionaryToFile(Dictionary mas[], int cur_len) – the function outputs the dictionary to the file “output.txt”.

void Fill(Dictionary *mas, int &cur_len) - the function structures the data in the output.txt file into an array mas of Dictionary structures
