#include <iostream>
template<class T>
class ArrayQueue{
private:
    T* _arr;
    size_t _indexFirst = 0;
    size_t _indexLast = -1;
    size_t _size;
public:
    ArrayQueue(size_t size = 100){
        _size = size;
        T* _arr = new T[_size];
    };

    void push(const T& el){
        if(_size > _indexLast){
            _arr[++_indexLast] = el;
        }
        else{
            throw "Container is full.";
        }
    };
    T pop(){
        // if(!empty())throw "Stack is empty.";
        if(_indexFirst == _indexLast){
            size_t tmp = _indexFirst;
            _indexFirst = 0;
            _indexLast = -1;
            return _arr[_indexFirst];
        };
        return _arr[_indexFirst++];
    };
    T& front(){
        return _arr[_indexFirst];
    };
    T& back(){
        return _arr[_indexLast];
    };
    size_t getSize(){
        return _indexLast - _indexFirst;
    };
    // bool empty(){ //НЕ ДОПИСАНО
    //     if(_indexLast )
    // };
};


//dz реализовать все те же функции что есть и на cppreference