#include <random>
#include <iostream>

template<typename T>
T Raznost(T* arr1, T* arr2, int size1, int size2){
    T min = arr1[0];
    T max = arr2[0];
    for(int i = 1; i < size1; i++){
        if(arr1[i] < min) min = arr1[i];
    }
    for(int i = 1; i < size2; i++){
        if(arr2[i] > nax) max = arr2[i];
    }
}

int main(){
    int size1 = 1 + rand()%21, size2 = 1 +rand()%21;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    
    int res = Raznost(arr1, arr2, size1, size2);
    std::cout << res << std::endl;
    return 0;
}