#include <iostream>
#include "header.h"

int main() {

    system("chcp 65001 > nul");
    double precisions[] = {0.01, 0.001, 0.0001, 0.00001, 0.000001}; // Точности
    double a, b; // Границы интегрирования
    long long bns[4] = {1, 1, 1, 1};
    double (*f[4])(double) = {f1, f2, f3, f4};
    std::cin>>a>>b;
    data data_req[4];
    create_request(data_req, a, b);
    std::cout << "Прямоугольник:" << std::endl;
    int n=2;
   for (auto eps: precisions) {

          for (int i = 0; i < 4; i++) {
               data_req[i].value = get_rectangle_result(f[i], a, b, eps, bns[i]);
               data_req[i].binary_divisions = bns[i];
           }
           std::cout << "Точность: " << std::fixed << std::setprecision(n) << eps << std::endl;
           PrintTab(data_req, 4);
           n+=1;

    }


    data data_tr[4];
    for (int i = 0; i < 4; ++i) {
        bns[i] = 1;
    }
    int k=2;
    create_request(data_tr, a, b);
    std::cout << "Трапеция" << std::endl;
    for (auto eps: precisions) {
        for (int i = 0; i < 4; i++) {
            data_tr[i].value = get_trapezoid_result(f[i], a, b, eps, bns[i]);
            data_tr[i].binary_divisions = bns[i];
        }
        std::cout << "Точность: " << std::fixed << std::setprecision(k) << eps << std::endl;
        PrintTab(data_tr, 4);
        k+=1;
    }
}

