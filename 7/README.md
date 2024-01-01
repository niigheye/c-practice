<h1 style="font-size: 15;"> Formulation of the problem </h1>
Words of the text from small Latin letters are written in at least one
space; the text ends with a period. WITHOUT USING THE STRING construct:
a) write a program for entering such text from the keyboard;
b) print all words different from the last word, before printing (if the word is of odd length) by removing its middle letter.

<h1 style="font-size: 15;"> Algorithm development </h1>
A dynamic character array is used to store text.
We go through all the words in a loop. We check if the word:
• Written in small Latin letters.
• Differs from the last word (if not, delete it).
• Has a certain number of letters (if odd, remove the middle letter).
If all conditions are met, then we print this word.


**Description of input, output and auxiliary data:

Input data:
char *text – dynamic array of characters

Output:
Words that satisfy the conditions of the problem

**Description of elements:

int size - maximum size of the character array

char* text - character array

int current_index - index of the current character in the array

char ch - the character to be read from the keyboard

int sizeWord - default size of the last word

int count_WorSymbols - length of the last word

char* dynamic_lastword - last word

int word_start - start of the last word

int w - index of the last word for
