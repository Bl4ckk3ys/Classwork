#include <iostream>
#include "Fraction.h"

int main(){
    Fraction fract1;
    fract1.SetNum(1);
    fract1.SetDenom(2);
    fract1.PrintDouble();
    
    Fraction fract2();
    Fraction fract3 = Fraction();
    
    Fraction fract = Fraction(3,2);
    std::cout << fract;

    Fraction fract_copy = Fraction(fract);
    std::cout << fract_copy;
 
    Fraction* fract_pointer = new Fraction();
    delete fract_pointer;
}