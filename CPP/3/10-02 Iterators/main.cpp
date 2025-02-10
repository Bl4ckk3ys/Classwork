#include "IntArr.h"

int main(){
    IntArr intArr;
    for(Iterator i = intArr.begin(); i != intArr.end(); i++ ){
        std::cin >> *i;

    }
    for(auto it: intArr){
        std::cout<<it<<"\n";
    }

    return 0;
}