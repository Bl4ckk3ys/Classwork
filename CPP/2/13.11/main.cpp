#include <iostream>
#include "CorrectChecker.h"


int main(){  
    // CorrectChecker c;
    // c.FillVariable(exp);
    // std::cout<<c.CheckVariable()<<"\n";
    // std::cout<<c.CheckBrackets()<<"\n";
    // std::cout<<c.CheckFormula()<<"\n";
    std::string exp = "1+2-3+5";

    Formula f(exp);
    f.Calculate();
    // std::cout<<f;
    return 0;
}