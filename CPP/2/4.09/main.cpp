#include <iostream>
#include <cstdlib>
#include <cstring>

class ArrayHandler{
private:
    int* _array;
    int _min;
    int _max;
    int _size;
    int _count;
public:
    ArrayHandler(int size = 10){
        _size = size;
        _array = new int[_size];
        _max = INT32_MIN;
        _min = INT32_MAX;
        _count = 0;
    };
    void Append(int new_elem){
        if(_count == _size){
            _size += 10;
            int* new_arr = new int[_size];
            std::memcpy(new_arr, _array, sizeof(int)*_size);
            delete [] _array;
            _array = new_arr;
        }
        _array[_count] = new_elem;
        _count++;
    };
    int getMin(){
        for(int i = 0;i<_count;i++)
            if (_min > _array[i]) _min = _array[i]; 
        return _min;
    };
    int getMax(){
         for(int i = 0;i<_count;i++)
            if (_max < _array[i]) _max = _array[i]; 
        return _max;
    };
    int getIndexElem(int elem){
        for(int i = 0;i<_count;i++){
            if (elem == _array[i]) return i;
        }
        return -1;
    };
    ~ArrayHandler(){
        delete [] _array;
    }
};


int  main(){
    ArrayHandler a = ArrayHandler();

    return 0;
}