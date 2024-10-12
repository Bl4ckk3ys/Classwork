#pragma once
#include <random>
#include <iostream>
enum Colour{red, yellow, green};

class Apple{
    private:
        double _width, _height, _weight;
        bool _status;
        Colour _colour;
    public:        
        Apple();
        Apple(double width, double height, double weight, bool status, Colour colour);
        void GetInfo() const;
        void Bite();
        void Throw();
        double GetWeight() const;
        bool GetStatus() const;
};