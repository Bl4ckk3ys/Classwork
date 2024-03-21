#include <iostream>
#include "gauss.h"


int main()
{
    double** a, * y, * x;
    int n;
    std::cout << "Введите количество уравнений: ";
    std::cin >> n;
    a = new double* [n];
    y = new double[n];
    for (int i = 0; i < n; i++){
    a[i] = new double[n];
    for (int j = 0; j < n; j++){
      std::cout << "a[" << i << "][" << j << "]= ";
      std::cin >> a[i][j];
    }
  }
    for (int i = 0; i < n; i++){
        std::cout << "y[" << i << "]= ";
        std::cin >> y[i];
    }
    Print(a, y, n);
    x = gauss(a, y, n);
    for (int i = 0; i < n; i++)
        std::cout << "x[" << i << "]=" << x[i] << std::endl;

    for (int i = 0; i < n; i++){
        
    }



  for (int i = 0; i < n; i++)
    delete[] a[i];
    delete[] a;
    delete[] x;
    delete[] y;

    return 0;
}