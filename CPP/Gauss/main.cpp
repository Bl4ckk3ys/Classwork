#include <iostream>
#include <cstdlib>
#include "gauss.h"


int main(){
  double** arr, ** arr1, * b, * b1, * x;
  int N;

  std::cout << "Введите количество уравнений: ";
  std::cin >> N;

  arr = new double* [N];
  arr1 = new double* [N];
  b = new double[N];
  b1 = new double[N];

  // for (int i = 0; i < N; i++){
  //   arr[i] = new double[N];
  //   arr1[i] = new double[N];
  //   for (int j = 0; j < N; j++){
  //     std::cout << "arr[" << i << "][" << j << "]= ";
  //     std::cin >> arr[i][j];
  //     arr1[i][j]==arr[i][j];
  //   }
  // }
  // for (int i = 0; i < N; i++){
  //   std::cout << "b[" << i << "]= ";
  //   std::cin >> b[i];
  //   b1[i] = b[i];
  // }

  for (int i = 0; i < N; i++){
    arr[i] = new double[N];
    arr1[i] = new double[N];
    b[i] = rand()%10;
    b1[i] = b[i];
    for (int j = 0; j < N; j++){
      arr[i][j] = rand()%10;
      arr1[i][j]==arr[i][j];
    }
  }

  Print(arr, b, N);
  x = gauss(arr, b, N);
  for (int i = 0; i < N; i++) std::cout << "x[" << i << "]=" << x[i] << std::endl;
  
  for(int k = 0;k<N;k++){
    double R = 0;
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          R += x[k]*arr1[i][j];
      }
    }
    std::cout << "Вектор невязки для уравнения №" << k << " = " << b1[k]-R << std::endl;
  }


  for (int i = 0; i < N; i++){
    delete[] arr[i];
    delete[] arr1[i];
  } 
    delete[] arr;
    delete[] arr1;
    delete[] x;
    delete[] b;
    delete[] b1;

    return 0;
}