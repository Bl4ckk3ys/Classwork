#include <cstddef>
template <typename T>
class Stack
{
private:
    T* _array;
    size_t _size;
    size_t _top;
    bool _isEmpty = true;
    void Expand(){
        _size*=2;
        
    };    
public:
    Stack(size_t size=10){
        _array = new T[size];
        _size = size;
        _top = 0;
    }
    bool IsEmpty()const{
        return _isEmpty;
    }
    bool IsFull()const{
        return (_size-1 == _top) && !_isEmpty;
    }
    void Push(T elem){
        if(IsFull()) Expand();
        if(IsEmpty()) _isEmpty = false;
        else _top++;
        _array[_top] = elem;
    }
    T Pop(){
        if (_isEmpty) throw "Stack is empty.\n";
        if (_top == 0){
            _isEmpty = true;
            return _array[_top];
        } 
        return _array[_top--];
    }
    T Check(){
        return _array[_top];
    }
    ~Stack();
};