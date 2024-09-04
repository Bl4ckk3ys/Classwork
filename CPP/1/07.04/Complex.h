#pragma once
#include "Fraction.h"

class Complex{
    private:
        Fraction _re;
        Fraction _im;
    public:
        Complex();
        Complex(Fraction _re,Fraction _im);
        Complex(int32_t num_re, uint32_t denom_re, int32_t num_im, uint32_t denom_im);
        friend std::ostream& operator<<(std::ostream&os, const Complex& tmp){
            os << tmp._re;
            if (static_cast<double>(tmp._im) > 0) os << " + " << tmp._im << "i";
            else os << tmp._im << "i";
            return os;
        } 
        Complex operator+(const Complex& tmp)const{
            Fraction new_re = _re + tmp._re;
            Fraction new_im = _im + tmp._im;
            return(new_re, new_im);
        }
};