#include "Monom.h"
#include <iostream>

Monom::Monom(double coef, size_t size, uint16_t* array){
    _coef = coef;
    _size = size;
    _array = array;
    _next = nullptr;
}

void Monom::Print(){
    std::cout<<_coef;
    for(size_t i = 0; i < _size; i++){
        std::cout<< "X" << i+1 << _array[i];
    }
}

Monom::Monom(const Monom& monom){
    _size = monom._size;
    _coef = monom._coef;
    _next = monom._next;
    _array = new uint16_t[_size];
    for(size_t i = 0; i < _size; i++){
        _array[i] = monom._array[i];
    }
}

Monom& Monom::operator=(const Monom& monom){
    if(this == &monom){
        return *this;
    }
    delete [] _array;
    _array = new uint16_t[monom._size];
    _size = monom._size;
    _coef = monom._coef;
    _next = monom._next;
    for(size_t i = 0; i<_size; i++){
        _array[i] = monom._array[i];
    }
    return *this;
}

Monom Monom::operator+(const Monom& monom)const{
    Monom copy(*this);
    if(_size != monom._size) throw "Invalid size. ";
    for(size_t i = 0; i < _size; i++){
        if(copy._array[i]!=monom._array[i]) throw "Your resault is Polynom. ";
        copy._coef += monom._coef;
        return copy;
    }
}

Monom Monom::operator*(const Monom& monom)const{
    size_t mSize = std::max(this->_size, monom._size);
    uint16_t* arr = new uint16_t[mSize];
    size_t minSize = std::min(this->_size, monom._size);
    for(size_t i = 0; i < minSize; i++){
        arr[i] = _array[i] + monom._array[i];
    }
    if(this->_size > monom._size){
        for(size_t i = minSize; i < mSize; i++){
            arr[i] = _array[i];
        }
    }  
    else(this->_size < monom._size){
        for(size_t i = minSize; i < mSize; i++){
            arr[i] -= monom._array[i];
        }
    }
    return Monom(_coef * monom._coef, mSize, _array);
}


Monom Monom::operator/(const Monom& monom)const{
    size_t mSize = std::max(this->_size, monom._size);
    uint16_t* arr = new uint16_t[mSize];
    size_t minSize = std::min(this->_size, monom._size);
    for(size_t i = 0; i < minSize; i++){
        arr[i] = _array[i] - monom._array[i];
    }
    if(this->_size > monom._size){
        for(size_t i = minSize; i < mSize; i++){
            arr[i] = -_array[i];
        }
    }  
    if(this->_size < monom._size){
        for(size_t i = minSize; i < mSize; i++){
            arr[i] = -monom._array[i];
        }
    }
    return Monom(_coef / monom._coef, mSize, _array);
}