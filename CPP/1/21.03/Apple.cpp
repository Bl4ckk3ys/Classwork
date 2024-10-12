#include "Apple.h"

Apple::Apple(){
    _width = 2 + rand()%10;
    _height = 2 + rand()%10;
    _weight = 30 + rand() %170;
    _status = true;
    _colour = static_cast<Colour>(rand()%3);
}

Apple::Apple(double width, double height, double weight, bool status, Colour colour){
    _width = width;
    _height = height;
    _weight = weight;
    _status = true;
    _colour = colour;
}

void Apple::GetInfo() const{
    if(_status == false){
        std::cout<< "Apple doesn't exist."<<std::endl;
        return ;
    } 
    std::cout<< "Width: " << _width << std::endl;
    std::cout<< "Height: " << _height << std::endl;
    std::cout<< "Weight: " << _weight << std::endl;
    std::cout<< "Status: " << _status << std::endl;
    std::cout<< "Colour: ";
    switch(_colour){
        case 0: std::cout << "red" << std::endl;break;
        case 1: std::cout << "green" << std::endl;break;
        case 2: std::cout << "yellow" << std::endl;break;
    }
}

void Apple::Bite(){
    if(!_status)return;
    _weight -= 20;
    _height -= 2;
    _width -= 2;
    if(_weight<=0 || _height<=0 || _width<=0)_status = false;
}

void Apple::Throw(){
    _status = false;
}

double Apple::GetWeight()const{
    return _weight;
}

bool Apple::GetStatus() const{
    return _status;
}