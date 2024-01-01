#include "header.h"

double f1(double x) {
    return x;
}

double f2(double x) {
    return sin(22 * x);
}

double f3(double x) {
    return x * x * x * x;
}

double f4(double x) {
    return atan(x);
}

void create_request(data *d, double a, double b) {
    d[0].name = "y = x";
    d[1].name = "y = sin(22*x) ";
    d[2].name = "y = x^4 ";
    d[3].name = "y = arctang(x)";
    d[0].full_value = (b * b - a * a) / 2.0;
    d[1].full_value = (cos(22.0 * a) - cos(22.0 * b)) / 22.0;
    d[2].full_value = (b * b * b * b * b - a * a * a * a * a) / 5.0;
    d[3].full_value = b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0;
}

void PrintTab(data i_prn[], int k) {
    const char SIDE_SYBMOL = '|';
    const char HORIZONTAL_SYBMOL = '-';
    const char CONNECTOR_SYBMOL = '+';

    const int m = 4;                // число столбцов таблицы
    int wn[m] = {20, 18, 18, 10};   // ширина столбцов таблицы
    char *title[m] = {(char *) "Function", (char *) "Integral", (char *) "IntSum", (char *) "N "};
    int size[m];
    for (int i = 0; i < m; i++) {
        size[i] = (int) strlen(title[i]);
    }

    // шапка таблицы
    std::cout << CONNECTOR_SYBMOL << std::setfill(HORIZONTAL_SYBMOL);
    for (int j = 0; j < m - 1; j++)
        std::cout << std::setw(wn[j]) << CONNECTOR_SYBMOL;
    std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << std::endl;

    std::cout << SIDE_SYBMOL;
    for (int j = 0; j < m; j++)
        std::cout << std::setw((wn[j] - size[j]) / 2) << std::setfill(' ') << ' ' << title[j]
             << std::setw((wn[j] - size[j]) / 2) << SIDE_SYBMOL;
    std::cout << std::endl;

    // заполнение таблицы
    int z=0;
    for (int i = 0; i < k; i++) {
        std::cout << CONNECTOR_SYBMOL << std::fixed;
        for (int j = 0; j < m - 1; j++)

            std::cout << std::setfill(HORIZONTAL_SYBMOL) << std::setw(wn[j]) << CONNECTOR_SYBMOL;
        std:: cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL <<std:: setfill(' ') << std::endl;
    if (z==0) {
        std::cout << SIDE_SYBMOL << std::setw((int) (wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << ' ' << i_prn[i].name
                  << std::setw((int) (wn[0] - strlen(i_prn[i].name)) / 2) << SIDE_SYBMOL;
        z++;
    }
    else{
        std::cout << SIDE_SYBMOL << std::setw((int) (wn[0] - strlen(i_prn[i].name)) / 2)  << ' ' << i_prn[i].name
                  << std::setw((int) (wn[0] - strlen(i_prn[i].name)) / 2) << SIDE_SYBMOL;
    }
        std::cout << std::setw(wn[1] - 1) << std::setprecision(10) << i_prn[i].full_value << SIDE_SYBMOL
             << std::setw(wn[2] - 1) << i_prn[i].value << std::setprecision(6) << SIDE_SYBMOL
             << std::setw(wn[3] - 1) << i_prn[i].binary_divisions << SIDE_SYBMOL << std::endl;
    }

    // низ таблицы
    std::cout << CONNECTOR_SYBMOL << std::setfill(HORIZONTAL_SYBMOL);
    for (int j = 0; j < m - 1; j++)
        std::cout << std::setw(wn[j]) << CONNECTOR_SYBMOL;
    std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << std::setfill(' ') << std::endl;
}

double get_trapezoid_result(double (*f)(double), double a, double b, double eps,  long long &bn) {
    double dx = (double) (b - a) / bn;
    double oldSum = 10e7, newSum = 10e8;
    while (fabs(newSum - oldSum) > eps) {
        newSum = oldSum;
        oldSum = 0;
        bn *= 2;
        dx = (b - a) / bn;
        for (int step = 0; step < bn; ++step) {
            double x1 = a + step * dx;
            double x2 = a + (step + 1) * dx;
            oldSum += (x2 - x1) * (f(x1) + f(x2)) * 0.5;
        }
    }
    bn = bn / 2;
    return oldSum;
}


double get_rectangle_result(double (*f)(double), double a, double b, double eps, long long &bn) {
    double dx, newSum, oldSum, x;
    oldSum = 10e7;
    newSum = 10e8;
    while (fabs(newSum - oldSum) > eps) {
        newSum = oldSum;
        x = a;
        dx = (double) (b - a) / bn;
        oldSum = 0;
        for (int i = 0; i < bn; i++) {
            oldSum += f(x + dx / 2);
            x += dx;
        }
        oldSum *= dx;
        bn *= 2;
    }
    bn = bn / 2;
    return oldSum;
}

