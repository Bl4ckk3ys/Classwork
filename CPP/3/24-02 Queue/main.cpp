#include "ArrayQueue.h"
int main(){
    ArrayQueue<int> arr(10);
    arr.push(10);
    arr.push(51);
    std::cout<< arr.pop() << "\n" << arr.pop() << "\n";
    try{
        std::cout<< arr.pop() << "\n";
    }
    catch(const char* error){
        std::cout << error << "\n";
    }
    return 0;
}