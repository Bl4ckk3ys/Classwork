#include "Vector.h"

int main(){
    double* array_for_vec2 = new double[10]{
        1,2,3,4,5,6,7,8,9,10
    };
    Vector<int> vec1 = Vector<int>(10);
    Vector<double> vec2 = Vector<double>(10,array_for_vec2);
}