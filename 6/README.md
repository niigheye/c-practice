<h1 style="font-size:15;">Formulation of the problem </h1>

Encode and decode text (character array) using Caesar code with a variable shift according to the ASCII code table. The shift value for each position in the source text is the sum (mod. 256) of the character codes of the word in the code pad located in the notepad at the same position. If the code notebook has fewer words than the number of characters in the source text, then when the words in it are exhausted, go to the first word and continue. (Based on the code notebook, it is advisable to first generate an integer array of keys according to a given rule, which is then used during coding. These actions should be formalized as a separate function.)
Investigate the repeatability of characters in encoded text (how many codes of the same source character are received) depending on the code pad and the length of the source text. Present the research results in the form of a table (think about the format of the table). Exploration and display of the results table should be performed in dialog mode, sequentially calculating and displaying the results for the requested symbol. Store statistical data in the int stat[256] array. For greater reliability of statistical results, use text files of about 1 KB in size as source text and code pad.

<h1 style="font-size:15;">Algorithm development </h1>

*Input data

• source.txt – text file
• key.txt – code pad
Output
• encoded.txt – encrypted text
• decoded.txt – decrypted text

*Program stages

• Using a code pad, get an array of keys
• Encrypt text
• Display statistics on a symbol
• Decipher the text

*List of functions

Functions for working with files

void inputKeyCodes(ifstream& fin, int* indexes, int& index)
Creating an Array of Encoding Keys
Input data
• ifstream& fin – input file
Output
• int* indexes – array of keys for words
• int& index – number of characters in the file

void encodeSourceCodes(ifstream& fin, fstream& encodeOut, int* keys, int& keySize, int ** matrix)
Encodes characters from the source.txt file and writes them to encode.txt, and also maintains character statistics.
Input data
• ifstream& fin - source.txt file
• fstream& encodeOut – encoded.txt file
• int* keys – array of keys
• int& keySize – size of the key array
• int ** matrix – statistics matrix

void decodeFile(fstream& encoded, ofstream& decoded, int* keyIndexs, int keySize)
decodes text from encode.txt to decode.txt
Input data
• fstream& encoded – input file encoded.txt
• ofstream& decoded - output file decoded.txt
• int* keyIndexs – array of keys
• int keySize – size of the key array
Functions for working with a matrix

void printMas(int* mas, int& size)
Prints an array of characters to the screen
Input data
• int* mas – array of characters
• int& size - size of the mas array

void outTable(ofstream& out, int** arr ,int size)
Displays the matrix on the screen
Input data:
• ofstream& out – output file outTabe.txt
• int** arr – matrix
• int size – matrix size
int** createMatrix(int N)
Returns a null matrix of size N
Input data:
• int N – matrix size
Output:
• int** matrix – zero matrix
•
void destroyMatrix(int ** arr, int size)
Removes matrix
int ** arr – matrix
int size – matrix size
