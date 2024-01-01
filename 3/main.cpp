#include <iostream>
#include <iomanip>
#include <cmath> //библиотека математических функций/формул
#include "iteraz.cpp"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double x = 0;
	double a, b, c, d;
	int k[4] = { 1,1,5,10 };
	double epsi[4] = { 0.000001,0.00000001,0.000001,0.000001 };
	cout << "Введите начальное приближение для простой итерации" << endl;
	cin >> a;
	cout << "Введите значения границ отрезка" << endl;
	cin >> b >> c;
	cout << "Введите начальное приближение для метода Ньютона" << endl;
	cin >> d;
	for (int i = 0; i < 4; i++) {
		if (i < 2) {
			cout << "Уравнение: x - cos(x) = 0." << " Погрешность:" << epsi[i] << "\n\n";
		}
		else
		{
			cout << "Уравнение: x - k*cos(x) = 0," << " k = " << k[i] << ", Погрешность:" << epsi[i] << "\n\n";
		}
		cout << "методы " << setw(30) << " x" << setw(30) << " N" << endl;
		iteraz(k[i], epsi[i], a);
		poldel(k[i], epsi[i], b, c);
		nuton(k[i], epsi[i], d);
	}
	return 0;
}
