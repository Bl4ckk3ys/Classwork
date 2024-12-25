#include <iostream>
#include "CorrectChecker.h"


int main(){ 
    std::string exp = "1+2-3+5"; 
    CorrectChecker c;
    c.FillVariable(exp);
    std::cout<<c.CheckVariable()<<"\n";
    std::cout<<c.CheckBrackets("(())))")<<"\n";
    std::cout<<c.CheckFormula(exp)<<"\n";
    

    //Formula f(exp);
    //f.Calculate();
    // std::cout<<f;
    return 0;
}