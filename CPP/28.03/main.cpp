#include "matrix.h"
#include <random>
#include <time.h>


int main(){
    srand(time(NULL));
    // matrix matr1 = matrix<double>(4, 4, 1);
    // matr1.print_matrix();
    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 4; j++){
    //         if (j % 2){
    //             matr1[i][j] = i;
    //         }
    //         else if (i % 2){
    //             matr1[i][j] = j + i;
    //         }
    //         else{
    //             matr1[i][j] = j - i;
    //         }
    //     }
    // }
    // matr1[3][3] = 9;
    // matr1.print_matrix();
    // matrix matr2 = matr1.reverse_matrix();
    // matr2.print_matrix();
    // matrix<double> matr3 = matr1 * matr2;
    // matrix<double> matr4 = matr3 / matr1;
    // matr3.print_matrix();
    // matr4.print_matrix();
    // matrix<double> matr1 = matrix<double>(4, 4, 1);
    // matrix matr2 = matrix<int>(4, 4, 1);
    // matrix<double> matr3 = matr1 * matr1.reverse_matrix(); 
    // matrix<double> matr4 = matr1 / matr1;
    // std::cout<<matr3<<std::endl<<matr4<<std::endl;
    Vector<int> vec1 = {1, 2, 4};
    Vector<int> vec2 = {2, 4, 6};
    Vector vec3 = vec1.vectors_multiplicate(vec2);
    std::cout<<vec3<<std::endl;
    return 0;
}