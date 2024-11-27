#pragma once
#include <iostream>

template<typename T1, typename T2>
class Table{
private:
    size_t _tableSize;
    T1* _col1;
    T2* _col2;
    size_t _count;
    std::string _titleCol1;
    std::string _titleCol2;
public:
    /// @brief "Класс принимает размер, название первого и второго столбика."
    /// @param size 
    /// @param _titleCol1 
    /// @param _titleCol2 
    Table(size_t size = 20, std::string titleCol1 = "Col1", std::string titleCol2 = "Col2"){
        _titleCol1 = titleCol1;
        _titleCol2 = titleCol2;
        _tableSize = size;
        _col1 = new T1[size];
        _col2 = new T2[size];
        _count = 0;
    }
    void AppendRow(T1 t1, T2 t2){
        _col1[_count] = t1;
        _col2[_count] = t2;
        _count++;
    }

    void Print(){
        for(size_t i = 0; i < _tableSize; i++) 
            std::cout<< _col1[i] << " " << _col2[i] << "\n";
    }
};