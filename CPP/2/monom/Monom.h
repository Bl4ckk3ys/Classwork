#include <iostream>

class Monom{
private:
    double _coef;
    size_t _size;
    uint16_t* _array;
    Monom* _next;
public:
    Monom(double coef, size_t size, uint16_t* array);

    Monom* GetNext(){
        return _next;
    }

    void Print();
    Monom(const Monom& monom);
    
    Monom&operator=(const Monom& monom);
    Monom operator+(const Monom& monom)const;
    Monom operator*(const Monom& monom)const;
    Monom operator/(const Monom& monom)const;
    ~Monom(){
        delete _array;
    }
};