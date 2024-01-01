#include"header.h"
#include<time.h>
#include<stdlib.h>
void sele(int a[], int N,int s)
{
	int min = 0, obmen = 0, j = 0, sr = 0, pere = 0;
	for (int(i) = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
		{
			sr++;
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		obmen = a[i];
		if (a[i]!= a[min])
		{
			pere++;
			a[i] = a[min];
			a[min] = obmen;
		}
	}
	if (s <= 1)
	{
		for (int i = 0; i < N; i++)
			std::cout << a[i] << " ";
		std::cout << std::setw(8) << sr << std::setw(12) << pere << std::endl;
	}
	if (s == 2)
		std::cout << std::setw(8) << sr << std::setw(16) << pere << std::endl;
	if (s == 3)
		std::cout << std::setw(8) << sr << std::setw(15) << pere << std::endl;
	if (s == 4)
		std::cout << std::setw(8) << sr << std::setw(14) << pere << std::endl;
}


void rsele(int a[], int N)
{
	int max = 0, obmen = 0, j = 0, sr = 0, pere = 0;
	for (int(i) = 0; i < N; i++)
	{
		max = i;
		for (int j = i + 1; j < N; j++)
		{
			sr++;
			if (a[j]>a[max])
			{
				max = j;
			}
		}
		obmen = a[i];
		if (a[i]!=a[max])
		{
			pere++;
			a[i] = a[max];
			a[max] = obmen;
		}
	}
	for (int i = 0; i < N; i++)
		std::cout << a[i] << " ";
	std::cout << std::setw(8) << sr << std::setw(12) << pere << std::endl;

}


int iRandom(int k, int n)
{
	return k + (n - k + 1) * rand() / RAND_MAX;
}

