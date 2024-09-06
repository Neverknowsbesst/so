#include <vector>
#include <iostream>

//calcular el promedio y la sumatoria de un vector
void promedio_sumatoria(const std::vector<int>& vec) {
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    double promedio = (double)sum / vec.size();
    std::cout << "Sumatoria: " << sum << "\n";
    std::cout << "Promedio: " << promedio << "\n";
}

// funcion f(x) = 5x^2 + 1/x
double funcion_f(double x) {
    return (5 * x * x) + (1 / x);
}
