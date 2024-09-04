#include <iostream>
#include <random>

class Array{
private:
    size_t _size;
    double* _arr;
public:
    Array(){
        _size = 100;
        _arr = new double[_size];
        for(size_t i = 0; i< _size;i++){
            _arr[i] = rand()%100;
        }
    }
    ~Array(){
        delete [] _arr;
    }

    double GetMax(){
        double max = _arr[0];
        for(size_t i = 1;i<_size;i++){
            if(_arr[i]>max) max = _arr[i];
        }
        return max;
    }
    double GetMin(){
        double min = _arr[0];
        for(size_t i = 1;i<_size;i++){
            if(_arr[i]<min) min = _arr[i];
        }
        return min;
    }
    double GetMid(){
        double sum = 0;
        for(size_t i = 0; i < _size;i++){
            sum += _arr[i];
        }
        return sum/_size;
    }
};
//Наследование (через ":")
//Композиция это когда объект одного класса существует совместно с объектом другого класса, при смерти одного объекта умирает и второй
class Aggregator{//Агрегация (грубо говоря композиция но второй объект не умирает, при смерти другого :) )
private:
    Array* _arr;
public:
    Aggregator(Array* arr){
        _arr = arr;
    }
    void Print(){
        std::cout << "Maximum: " << _arr->GetMax() << "\nMinimum: " << _arr->GetMin() << "\nMiddle: " << _arr->GetMid() << std::endl;
    }
};
int main(){
    Array A;
    Aggregator Ag = Aggregator(&A);
    Ag.Print();
    return 0;
}