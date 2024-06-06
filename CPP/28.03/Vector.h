#pragma once
#include <iostream>
#include <cmath>
#include "Matrix.h"

template<typename T>
class Vector{
private:
    T* _array;
    double* normal_array;
    size_t _size;
    double _lenght;

public:
    Vector(){
        _size = 10;
        normal_array = new double[_size];
        _array = new T[_size];
    }
    Vector(size_t size, T* array): _size(size), _array(new T[size]){
        normal_array = new double[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
        _lenght = find_lenght();
    }
    Vector(size_t size): _size(size), _array(new T[size]){
        normal_array = new double[_size];
        for (int i = 0; i < size; i++){
            _array[i] = 0;
        }
        _lenght = find_lenght();
    }
    Vector(std::initializer_list<T> list){
        normal_array = new double[_size];
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); elem++, i++){
            _array[i] = *elem;
        }
        _lenght = find_lenght();
    }

    Vector(const Vector& vec){
        normal_array = new double[_size];
        _lenght = vec._lenght;
        _size = vec._size;
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = vec._array[i];
        }
    }

    void normal(){
        for (int i = 0; i < _size; i++){
            normal_array[i] = _array[i] / _lenght;
        }
    }

    double* GetNormalVector(){
        normal();
        return normal_array;
    }

    void print_normal(){
        for (int i = 0; i < _size; i++){
            std::cout<<normal_array[i]<<std::endl;
        }
    }

    double find_lenght(){
        double number = 0;
        for (int i = 0; i < _size; i++){
            number += _array[i] * _array[i];
        }
        return sqrt(number);
    }

    const T& operator[](int i) const {
        return _array[i];
    }

    T& operator[](int i){
        return _array[i];
    }


    friend std::ostream& operator<<(std::ostream& os,  const Vector& vec){
        for (int i = 0; i < vec._size; i++){
            os << vec._array[i];
            if (i + 1 !=  vec._size)
                os << ", ";
        }
        return os;
    }

    Vector operator+(const Vector& vec) const {
        if (_size != vec._size){
            std::cout<<"error +"<<std::endl;
            throw;
        }
        Vector vec1(_size);
        for (int i = 0; i < _size; i++){
            vec1[i] = _array[i] + vec._array[i];
        }
        return vec1;
    }

    Vector operator-(const Vector& vec) const {
        if (_size != vec._size){
            std::cout<<"error -"<<std::endl;
            throw;
        }
        Vector vec1 = vec1(_size);
        for (int i = 0; i < _size; i++){
            vec1[i] = _array[i] - vec._array[i];
        }
        return vec1;
    }

    auto operator*(const Vector& vec) const {
        if (_size != vec._size){
            std::cout<<"error *"<<std::endl;
            exit(1);
        }
        auto number = 0;
        for (int i = 0; i < _size; i++){
            number += _array[i] * vec._array[i];
        }
        return number;
    }


    Vector& operator=(const Vector& vec){
        if (vec._size > _size){
            delete [] _array;
            _array = new T[vec._size];
        }
        _lenght = vec._lenght;
        _size = vec._size;
        for (int i = 0; i < _size; i++){
            _array[i] = vec._array[i];
            normal_array[i] = vec.normal_array[i];
        }
        return *this;
    }

    void PrintLenght(){
        std::cout<<_lenght<<std::endl;
    }

    size_t GetSize(){
        return _size;
    }

    Vector vectors_multiplicate(const Vector& vec) const {
        size_t new_size = _size;
        T* new_array = new T[_size];
        new_array[0] = _array[1] * vec._array[2] - _array[2] * vec._array[1];
        new_array[1] = _array[0] * vec._array[2] - _array[2] * vec._array[0];
        new_array[2] = _array[0] * vec._array[1] - _array[1] * vec._array[0];
        Vector new_vec = Vector(_size, new_array);
        return new_vec;
    }

    ~Vector(){
        delete [] _array;
        delete [] normal_array;
    }

};