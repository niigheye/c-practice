int main()
{
	system("chcp 1251 >nul");
	const int max_len = 200;
	Dictionary *mas = new Dictionary[max_len];
	int cur_len = 0;
	Fill(mas, cur_len);
	Filter(mas, cur_len);
	while (true)
	{
		switch (Menu())
		{
		case (1):
			AddWords(mas, cur_len, max_len);
			break;
		case (2):
			DeleteWord(mas, cur_len);
			break;
		case (3):
			Translate(mas, cur_len, 0);
			break;
		case (4):
			Translate(mas, cur_len, 1);
			break;
		case (5):
			PrintDictionary(mas, cur_len);
			break;
		case (6):
			DictionaryToFile(mas, cur_len);
			break;
		case (7):
			return 0;
		}
	}
}

