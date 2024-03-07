//Это файл-хиддер
#pragma once
#include <iostream>
#include <cstdint>
class Fraction{
private:

    int32_t _num; //Поля класса
    uint32_t _denom;

public:
    Fraction(); //Конструктор по умолчанию
    Fraction(int32_t num, uint32_t denom); //Конструктор с параметрами

    Fraction(const Fraction& fraction);//Копирование класса

    //Геттеры
    void SetNum(int32_t newNum);
    void SetDenom(uint32_t newDenom);

    //Сеттеры
    inline int32_t GetNum(){
        return _num;
    }
    inline uint32_t GetDenom(){
        return _denom;
    }

    bool IsValid = true;

    void Print();//Метод, сигнатура тут, сам код в Fraction.cpp
    inline void PrintDouble(){
        std::cout << static_cast<double>(_num)/_denom << std::endl;
    }

    //Перегрузка операции вывода в консоль
    friend std::ostream& operator<<(std::ostream& os, const Fraction& tmp){ //принимает ссылку на поток вывода, конст ссылку на наш класс 
        os << tmp._num << "/" << tmp._denom << std::endl;
    }

    bool operator> (const Fraction& tmp) const{
        int32_t new_num1 = _num * tmp._denom;
        int32_t new_num2 = tmp._num * _denom;
        return new_num1 > new_num2;
    }

    bool operator< (const Fraction& tmp) const{
        int32_t new_num1 = _num * tmp._denom;
        int32_t new_num2 = tmp._num * _denom;
        return new_num1 < new_num2;
    }

    bool operator== (const Fraction& tmp) const{
        int32_t new_num1 = _num * tmp._denom;
        int32_t new_num2 = tmp._num * _denom;
        return new_num1 == new_num2;
    }
    
    //ДЗ определить конструктор следующего вида: 
    Fraction(double realFract); //грубо говоря 0.5 -> 1/2

    //ДЗ2 сокращение дроби (через конструктор, а не сетр гетр)
    void Reduce();// 10/20 -> 1/2
};