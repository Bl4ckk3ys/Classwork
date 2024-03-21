#pragma once
#include "Apple.h"

class Eater{
private:
    int _age;
    double _height, _weight;
public:
    Eater() = delete;
    Eater(int age,double height, double weight);
    void Eat(Apple& a);
};

