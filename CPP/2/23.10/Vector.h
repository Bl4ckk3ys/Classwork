#include <iostream>

template <class T>
class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector(size_t size, size_t startIndex);
    Vector(const Vector& tmp);
    Vector(Vector&& moved);//Конструктор перемещения
    size_t GetSize()const;
    size_t GetStartIndex()const;
    T& At(size_t pos);//реализуем чтобы не было выхода за границы массива и undefined поведение
    T& operator[](size_t pos);
    Vector& operator=(const Vector& tmp);
    Vector operator+(const T& tmp);
    Vector operator-(const T& tmp);
    Vector operator*(const T& tmp);
    Vector operator+(const Vector& tmp);
    Vector operator-(const Vector& tmp);
    T operator*(const Vector& tmp);
    //плюс ввод вывод
    ~Vector();
};