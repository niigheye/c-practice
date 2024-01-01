#include "header.h"

int Menu()
{
	std::cout << "Available features:\n";
	std::cout << "1.Add words\n2.Delete words\n3.Translate from russian to english\n4.Translate from english to russian\n5.Show dictionary\n6.Put dictionary in file\n7.Exit";
	std::cout << "\nEnter a number:";
	int n;
	std::cin >> n;
	return n;
}

void Filter(Dictionary* mas, int cur_len) {
	bool isSorted;
	for (int i = 0; i < cur_len - 1; i++)
	{
		isSorted = true;
		for (int j = 0; j < cur_len - i - 1; j++)
		{
			if (std::strcmp(mas[j].eng, mas[j + 1].eng) > 0)
			{
				std::swap(mas[j], mas[j + 1]);
				isSorted = false;
			}
		}
		if (isSorted == true) {
			break;
		}
	}
}

int SearchIndex(Dictionary* mas, char* word, int cur_len)
{
	int i = 0;

	while ((std::strcmp(mas[i].rus,word)!=0) && (std::strcmp(mas[i].eng, word) != 0) && (i < cur_len - 1))
	{
		i++;
	}

	if (i == cur_len - 1)
	{
		std::cout << "\nCan't find the word!!";
		return -1;
	}

	return i;
}

int SearchIndex(Dictionary mas[], char* word, int cur_len, char *lang)
{
	int i = 0;

	if (lang == "eng")
	{
		while (strcmp(mas[i].eng, word) && (i < cur_len - 1))
		{
			i++;
		}
	}
	else if (lang == "rus")
	{
		while ((strcmp(mas[i].rus, word)) && (i < cur_len - 1))
		{
			i++;
		}
	}
	else
	{
		std::cout << "Error during SearchIndex";
	}

	return i;
}

void AddWords(Dictionary mas[], int &cur_len, const int max_len)
{
	char eng1[31], rus1[31], state = 'y';

	while ((state == 'y') && (cur_len < max_len))
	{
		std::cout << "\nEnter english word:";
		std::cin >> eng1;
		std::cout << "\nEnter russian word:";
		std::cin >> rus1;

		mas[cur_len].eng = new char[strlen(eng1) + 1];

		strcpy(mas[cur_len].eng, eng1);
		mas[cur_len].rus = new char[strlen(rus1) + 1];

		strcpy(mas[cur_len].rus, rus1);
		cur_len++;
		std::cout << "\nDo you want to continue? (y/n)";
		std::cin >> state;
	}
	Filter(mas, cur_len);
	if (cur_len == max_len)
	{
		std::cout << "Dictionary is full!!\n\n";
	}

	return;
}


void DeleteWord(Dictionary* mas, int& cur_len)
{
	
	bool flag = false;
	char* word = new char[31];
	std::cout << "Which word do you want to delete?: ";
	std::cin >> word;
	int i;
	for (i = 0; i < cur_len; i++)
	{
		if (std::strcmp(mas[i].eng, word) == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		delete[] mas[i].eng;
		delete[] mas[i].rus;
		for (i; i < cur_len - 1; i++)
		{
			mas[i].eng = mas[i + 1].eng;
			mas[i].rus = mas[i + 1].rus;
		}
		cur_len--;
	}
	else{
		std::cout << "\nCan't find the word\n\n";
	}
		

}


void PrintDictionary(Dictionary mas[], int cur_len)
{
	
	std::cout << "\nDictionary:\n";

	for (int i = 0; i < cur_len; i++)
	{
		std::cout << "\n"<< mas[i].eng << " - " << mas[i].rus << "\n";
				  
	}

	std::cout << "\n\n";
	return;
}

void Translate(Dictionary mas[], int cur_len, const int type)
{

	char word[31];
	int i;
	std::cout << "\nEnter the word you want to translate:";
	std::cin >> word;
	if (type == 0)
	{
		i = SearchIndex(mas, word, cur_len, "rus");
		std::cout << "\nTranslated word:" << mas[i].eng << "\n";
	}
	else
	{
		i = SearchIndex(mas, word, cur_len, "eng");
		std::cout << "\nTranslated word:" << mas[i].rus << "\n";
	}

	return;
}

void DictionaryToFile(Dictionary mas[], int cur_len)
{
	std::fstream file("output.txt");

	if (!file.is_open())
	{
		std::cout << "Can't find file!!!";
		return;
	}

	for (int i = 0; i < cur_len; i++)
	{
		file << mas[i].eng << " - " << mas[i].rus << "\n";
	}
	file.close();
	return;
}

void Fill(Dictionary *mas, int &cur_len)
{
	std::ifstream file("output.txt");
	while (!file.eof())
	{
		char word[31];
		file >> word;

		mas[cur_len].eng = new char[strlen(word) + 1];
		std::copy(word, word + strlen(word) + 1, mas[cur_len].eng);

		file >> word;

		file >> word;

		mas[cur_len].rus = new char[strlen(word) + 1];
		std::copy(word, word + strlen(word) + 1, mas[cur_len].rus);
		++cur_len;
	}
	file.close();
}
