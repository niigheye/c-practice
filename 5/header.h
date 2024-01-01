#include "iostream"
#include <iomanip>
#include <cmath>
#include <cstring>


double f1(double x);

double f2(double x);

double f3(double x);

double f4(double x);

struct data {
    const char *name;
    double value;
    double full_value;
    long long binary_divisions;
};

void create_request(data *d, double a, double b);

void PrintTab(data d[], int k);

double get_trapezoid_result(double (*f)(double), double a, double b, double eps, long long &bn);

double get_rectangle_result(double (*f)(double), double a, double b, double eps, long long &bn);

