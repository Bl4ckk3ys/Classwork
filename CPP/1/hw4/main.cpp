#include "QuadraticEquasion.h"


int main() {
    double a, b, c;
    std::cout << "Введите коэффициенты a, b и c квадратного уравнения: ";
    std::cin >> a >> b >> c;

    QuadraticEquation equation(a, b, c);
    std::vector<std::complex<double>> roots = equation.solve();

    std::cout << "Корни квадратного уравнения: " << std::endl;
    for (const auto& root : roots) {
        std::cout << "Корень: " << root << std::endl;
    }

    return 0;
}