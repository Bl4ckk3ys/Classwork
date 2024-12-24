#pragma once
#include <iostream>
#include <iomanip>
#include <optional>
#include <cstring>

template<typename T1, typename T2>
class Table{
private:
    size_t _tableSize;
    std::optional<T1>* _col1;
    std::optional<T2>* _col2;
    size_t _count;
    std::string _titleCol1;
    std::string _titleCol2;
    void Expand(){
        _tableSize *= 2;

        std::optional<T1> tmp1 = new std::optional<T1>[_tableSize];
        std::memcpy(tmp1, _col1, _count*sizeof(std::optional<T1>));
        delete[] _col1;
        _col1 = tmp1;

        std::optional<T2> tmp2 = new std::optional<T2>[_tableSize];
        std::memcpy(tmp2, _col2, _count*sizeof(std::optional<T2>));
        delete[] _col2;
        _col2 = tmp2;
    }
public:
    /// @brief "Класс принимает размер, название первого и второго столбика."
    /// @param size 
    /// @param _titleCol1 
    /// @param _titleCol2 
    Table(std::string titleCol1 = "Col1", std::string titleCol2 = "Col2",size_t size = 20){
        _titleCol1 = titleCol1;
        _titleCol2 = titleCol2;
        _tableSize = size;
        _col1 = new std::optional<T1>[size];
        _col2 = new std::optional<T2>[size];
        _count = 0;
    }
    void AppendRow(std::optional<T1> t1, std::optional<T2> t2){
        if(_count == _tableSize) //дописать!
        _col1[_count] = t1;
        _col2[_count] = t2;
        _count++;
    }

    void Print(){
        for(size_t i = 0; i < _tableSize; i++) 
            std::cout<< _col1[i] << " " << _col2[i] << "\n";
    }
    
    size_t GetSize(){
        return _tableSize;
    }
    size_t GetCount(){
        return _count;
    }
    std::optional<T1>* GetCol1(){
        return _col1;
    }
    std::optional<T2>* GetCol2(){
        return _col2;
    }
    std::optional<T2> operator[](T1 var){
        for(size_t i=0;i<_count;i++){
            if(var==_col1[i]) 
                return _col2[i];
        }
        return std::string::npos;
    }
     friend std::ostream& operator<<(std::ostream& os, const Table& t){
        os<<"|"<<std::setw(5)<<t._titleCol1<<" | "<<std::setw(5)<<t._titleCol2<<"|"<<std::endl;
        for (size_t i=0;i<15;i++){
            std::cout<<"-";
        }
        std::cout<<std::endl;
        
        for(size_t i=0; i<t._count;i++){
            if(t._col1[i]==std::nullopt){
                os<<std::setw(5)<<"no";
            }
            else
            os<<std::setw(5)<<t._col1[i].value();
            os<<"|";
            if(t._col2[i]==std::nullopt){
                os<<std::setw(5)<<"no";
            }
            else
            os<<std::setw(5)<<t._col2[i].value();
            std::cout<<std::endl;

        }
         for (size_t i=0;i<15;i++){
            std::cout<<"-";
        }
        return os;
    }
};