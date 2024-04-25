#include <iostream>

class A{

};

class B : public A{

};

class C : public B{

};

void foo(const A& a){
    //some code
}

//Композиция
class Engine{

};
//Пример КОМПОЗИЦИИ (Car не может существовать без Engine)
//HAS - A
class Car{
private: 
    Engine _engine;
public:
    Car() : _engine(){

    }
};

//Агрегация (Person может существовать без Pasport) 
class Pasport{

};

class Person{
private:
    Pasport* _pasport;
public:
    Person(){

    }
    Person(Pasport* pasport):_pasport(pasport){

    }
    void LoosePasport(){
        _pasport = nullptr;
    }
};

//Конкретизация аспектов наследования
/*
class Cat{
private:
    std::string _name;
public:
    Cat(const std::string& name): _name(name){

    }
    const std::string& GetName() const{
        return _name;
    }
    std::string Voice() const{
        return "Meow";
    }
};

class Dog{
private:
    std::string _name;
public:
    Dog(const std::string& name): _name(name){

    }
    const std::string& GetName() const{
        return _name;
    }
    std::string Voice() const{
        return "Woof";
    }
};
enum AnimalType{ // Перечисление
    CAT, DOG
};
class Animal{
private:
    std::string _name;

public:

}
*/



class Animal{
private:
    std::string _name;
public:
    Animal(const std::string& name): _name(name){

    }
    const std::string& GetName() const{
        return _name;
    }
    std::string Voice() const{
        return "Base voice";
    }
};

class Cat : public Animal{
public:
    Cat(const std::string& name) : Animal(name){

    }
    std::string Voice() const{
        return "Meow";
    }
};

class Dog : public Animal{
public:
    Dog(const std::string& name) : Animal(name){

    }
     std::string Voice() const{
        return "Woof";
    }    
};

void Process(const Animal& obj){
    std::cout << obj.GetName() << " say " << obj.Voice() << std::endl;
}

int main(){
    Cat cat = Cat("SISYA");
    Dog dog = Dog("BOB");
    Process(cat);
    Process(dog);

//=========================================
    Pasport pasport = Pasport();
    Person p = Person(&pasport);
    p.LoosePasport();


    A a = A();
    B b = B();
    A ab = B(); //связь is - a
    foo(a);foo(b);foo(ab);
    //B ba = A(); // Так не работает

    A* a_elems = new A[6] {a, b, ab, B(), A(), C()};
    A** a_elems1 = new A*[3] {&a,&b};
    std::cout << "Hello world" << std::endl;
    return 0;
}