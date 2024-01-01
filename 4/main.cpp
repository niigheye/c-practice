#include "header.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	const int N = 5;
	int s = 0, p = 0;
	int a[N], b[N], c[N], d[N];
	int* e = new int[5]; int* w = new int[5];
	int* arr = new int[50]; int* carr = new int[500];
	int* coarr = new int[50]; int* coparr = new int[500];
	srand((unsigned int)time(NULL)); //начальное число
rand();
for (int i = 0; i < N; i++)
	{
		a[i] = iRandom(1, 99);
		e[i] = iRandom(1, 99);
		b[i] = a[i]; c[i] = a[i]; d[i] = a[i];
		w[i] = e[i];

	}
	cout << "Количество элементов: 5. Заданный массив: ";
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << ". " << "Сортировка по возрастанию" << endl;
	cout << "Метод" << setw(22) << "Результат" << setw(20) << "Сравнений" << setw(15) << "Перестановок" << endl;
	cout << "сравнений(n)" << setw(8);
	sele(a, N, s);
	s++;
	cout << "сравнений(о)" << setw(8);
	sele(a, N, s);
	s++;
	cout << "пузырек(n)" << setw(10);
	bubble(c, N, p);
	p++;
	cout << "пузырек(о)" << setw(10);
	bubble(c, N, p);
	p++;
	cout << endl << endl;
	cout << "Количество элементов: 5. Заданный массив: ";
	for (int i = 0; i < N; i++)
		cout << b[i] << " ";
	cout << ". " << "Сортировка по убыванию" << endl;
	cout << "Метод" << setw(22) << "Результат" << setw(20) << "Сравнений" << setw(15) << "Перестановок" << endl;
	cout << "сравнений(n)" << setw(8);
	rsele(b, N);
	cout << "сравнений(о)" << setw(8);
	rsele(b, N);
	cout << "пузырек(n)" << setw(10);
	rbubble(d, N);
	cout << "пузырек(о)" << setw(10);
	rbubble(d, N);
	cout << endl << endl;

	for (int i = 0; i < 50; i++)
	{
		arr[i] = iRandom(1, 99);
		coarr[i] = arr[i];
	}
	for (int i = 0; i < 500; i++)
	{
		carr[i] = iRandom(1, 99);
		coparr[i] = carr[i];
	}
	int k = 5;
	cout << "Метод: сравнений(n). Cортировка по возрастанию" << endl;
	cout << "N" << setw(22) << "Cравнений" << setw(20) << "Перестановок" << endl;
	cout << k << setw(8)<<" ";
	sele(e, 5,s);
	delete e;
	s++;
	cout << k*10 << setw(9)<< " ";
	sele(arr, 50,s);
	delete arr;
	s++;
	cout << k*100 << setw(10)<< " ";
	sele(carr, 500,s);
	delete carr;
	cout << endl << endl;
	cout << "Метод: пузырек(n). Cортировка по возрастанию" << endl;
	cout << "N" << setw(22) << "Cравнений" << setw(20) << "Перестановок" << endl;
	cout << k << setw(7)<<" ";
	bubble(w, 5,p);
	delete w;
	p++;
	cout << k*10 << setw(9)<< " ";
	bubble(coarr, 50,p);
	delete coarr;
	cout << k*100 << setw(10)<< " ";
	bubble(coparr, 500,p);
	delete coparr;
}
