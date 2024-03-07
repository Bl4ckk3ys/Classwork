#include "Complex.h"

Complex::Complex(){
    _re = Fraction();
    _im = Fraction();
}

Complex::Complex(Fraction re, Fraction im){
    _re = Fraction(re);
    _im = Fraction(im);
}

Complex::Complex(int32_t num_re, uint32_t denom_re, int32_t num_im, uint32_t denom_im){
    _re = Fraction(num_re,denom_re);
    _im = Fraction(num_im, denom_im);
}