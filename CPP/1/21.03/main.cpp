#include "Apple.h"
#include "Eater.h"

int main(){
    Apple a = Apple();
    a.GetInfo();
    a.Bite();
    std::cout << std::endl;
    a.GetInfo();

    Eater e = Eater(7,144,42);
    e.Eat(a);
    a.GetInfo();
}