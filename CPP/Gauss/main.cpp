#include <iostream>
#include <cstdlib>
#include "gauss.h"


int main(){
  double** arr, * b, * x;
  int N;

  std::cout << "Введите количество уравнений: ";
  std::cin >> N;

  arr = new double* [N];
  b = new double[N];

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
    b[i] = rand()%10;
    for (int j = 0; j < N; j++) arr[i][j] = rand()%10;
  }

  Print(arr, b, N);
  x = gauss(arr, b, N);
  
  for (int i = 0; i < N; i++) std::cout << "x[" << i << "] = " << x[i] << std::endl;
  
  for(int k = 0;k < N;k++){
    double R = 0;
        for(int j = 0; j < N; j++){
          R += x[j]*arr[k][j];   
    }
    std::cout << "Вектор невязки для уравнения №" << k << " = " << b[k]-R << std::endl;
  }


  for (int i = 0; i < N; i++) delete[] arr[i];
    
    delete[] arr;
    delete[] x;
    delete[] b;

    return 0;
}