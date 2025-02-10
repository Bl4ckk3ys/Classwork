#include <iostream>
#include <iterator>

struct Iterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = int;
    using pointer = int*;
    using reference = int&;
    Iterator(pointer ptr):_ptr(ptr){};
    reference operator*()const{return *_ptr;};
    pointer operator->(){return _ptr;};
    Iterator operator++(int){
        Iterator tmp(*this);
        ++(*this);
        return tmp;
    };
    Iterator& operator++(){
        _ptr++;
        return *this;
    }
    friend bool operator==(const Iterator& a, const Iterator& b){
        return a._ptr == b._ptr;
    }
    friend bool operator!=(const Iterator& a, const Iterator& b){
        return a._ptr != b._ptr;
    }
    private:
        pointer _ptr;
};

class IntArr{
private:
    int _data[3] = {1, 4, 6};
public:
    Iterator begin(){return Iterator(&_data[0]);};
    Iterator end(){return Iterator(&_data[3]);};


};