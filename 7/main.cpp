#include <iostream>
#include <conio.h> 
int main()
{
    int size = 2000;                          
    char* text = new char[size];    
    int current_index = 0;                  
    while (true)
    {
        char ch = _getch();                 
        if (ch == '.') break;                  
        if (current_index == size - 1)
        {
            size *= 2;
            char* mass = new char[size];
            for (int i = 0; i < current_index; i++)
            {
                mass[i] = text[i]; 
            }
            delete[] text;              
            text = mass;           
        }

        else if (ch == '\b')                // если введен символ backspace
        {
            if (current_index > 0)
            {
                text[current_index] = ' ';
                current_index--;                    
                _putch('\b');
                _putch(' ');
                _putch('\b');
                continue;
            }
        }
        else if (current_index < size - 1 and ((ch >= 'a') and (ch <= 'z') or ch == ' ')) // ввод только разрешенных символов
        {
            text[current_index] = ch;   
            _putch(ch);                         
        }

    }
    while (current_index and text[current_index - 1] == ' ') // избегаем пробелы перед точкой
    {
        current_index--;
    }
    text[current_index] = '\0';            // добавляем завершающий символ

    int sizeWord = 100;                              
    int count_WorSymbols = 0;                       
    char* dynamic_lastword = new char[sizeWord];    
    // Поиск последнего слова 
    for (int k = current_index - 1; k >= 0; k--)
    {
        if ((text[k] == ' ' or text[k] == '\t') and text[k] != '\0')
        {
            break;
        }
        else if (text[k] != ' ')
        {
            dynamic_lastword[count_WorSymbols] = text[k]; 
        }
    }
    _putch('\n');
    //сравнение с последним словом
    int word_start = 0
    int w = 0;          
    for (int i = 0; i < current_index; i++)     
        if (text[i] == ' ' or text[i] == '\t' or i == current_index - 1) 
        {
            if (i == current_index - 1)         
                i++;                            
            w = count_WorSymbols - 1;
            if (i - word_start == count_WorSymbols)
            {
                for (int t = word_start; t <= i; t++)
                {
                    if (text[t] != dynamic_lastword[w]) // посимвольное сравнение
                        break;
                    else word_start += 1;
                    w--;
                }
            }
            //удаляем букву посередине
            if (i - word_start > 1)             // если слово состоит более чем из одного символа
            {
                if ((i - word_start) % 2 != 0) {      //проверяем на четность длины слова
                    for (int j = word_start; j < i; j++) // печатаем слово без среднего символа
                    {
                        if (j != ((i - word_start) / 2 + word_start))
                            _putch(text[j]);
                    }
                }
                else {
                    for (int j = word_start; j < i; j++) // печатаем слово полностью в ином случае
                        _putch(text[j]);
                }
                _putch(' ');               // печатаем пробел после слова
            }
            else _putch(text[word_start]);
            word_start = i + 1;                 // устанавливаем начало следующего слова
        }   
    }
    delete[] text;                      // освобождаем память
    return 0;
}

