#include <iostream>
#include <complex>
#include <vector>


class QuadraticEquation {
private:
    double _a, _b, _c;
public:
    QuadraticEquation(double a, double b, double c) : _a(a), _b(b), _c(c) {}

    std::vector<std::complex<double>> solve() {
        std::vector<std::complex<double>> roots;
        std::complex<double> D = std::pow(_b, 2) - 4 * _a * _c;
        std::complex<double> x1 = (-_b + std::sqrt(D)) / (2 * _a);
        std::complex<double> x2 = (-_b - std::sqrt(D)) / (2 * _a);
        roots.push_back(x1);
        roots.push_back(x2);
        return roots;
    }


};