#include "header.h"
void bubble(int a[], int N, int s) {
	int mest, sr = 0, pere = 0;
	bool f;
	for (int i = 0; i < N - 1; i++)
	{
		f = 0;
		for (int j = 0; j < N - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				mest = a[j];
				a[j] = a[j + 1];
				a[j + 1] = mest;
				pere++;
				f = 1;

			}
			sr++;
		}
		if (f == 0) break;
	}
	if (s <= 1)
	{
		for (int i = 0; i < N; i++)
			std::cout << a[i] << " ";
		std::cout << std::setw(8) << sr << std::setw(12) << pere << std::endl;
	}
	if (s==2)
		std::cout << std::setw(8) << sr << std::setw(16) << pere << std::endl;
	if (s == 3)
		std::cout << std::setw(8) << sr << std::setw(15) << pere << std::endl;

}

void rbubble(int a[], int N) {
	int mest, sr = 0, pere = 0;
	bool f = 0;
	for (int i = 0; i < N - 1; i++)
	{
		f = 0;
		for (int j = 0; j < N - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				mest = a[j];
				a[j] = a[j + 1];
				a[j + 1] = mest;
				pere++;
				f = 1;
			}
			sr++;
		}
		if (f == 0) break;
	}
	for (int i = 0; i < N; i++)
		std::cout << a[i] << " ";
	std::cout << std::setw(8) << sr << std::setw(12) << pere << std::endl;

}


