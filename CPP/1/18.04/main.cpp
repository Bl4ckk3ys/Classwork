#include <iostream>

class A{
protected:
    int _y;
private:
    int _x;
    void Fun2(){
        std::cout<<"Class A, Fun2" << std::endl;
    }
public:
    int _z;
    A(){
        std::cout<<"Default constructor A" << std::endl;
    }
    A(int x){
        _x = x;
        std::cout<<"X constructor A" << std::endl;
    }
    void Fun1(){
        std::cout<<"Class A, Fun1" << std::endl;
    }
};

class B : public A{
public:
    B(){
        _y = 10;
        std::cout<<"Default constructor B" << std::endl;
    }
    B(int x) : A(x){
        _y = x;
        std::cout<<"X constructor B" << std::endl;
    }
};
int main(){
    
    B b = B(10);
    return 0;
}