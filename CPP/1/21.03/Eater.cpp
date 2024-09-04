#include "Eater.h"

Eater::Eater(int age,double height, double weight){
    _age = age;
    _height = height;
    _weight = weight;
}

void Eater::Eat(Apple& a){
    double weight = a.GetWeight();
    _weight += weight * 0.001;
    a.Throw();
}