#include "Vector.h"

template<typename T>
class Matrix{
    private:
        Vector<T>* _vectors;
        size_t _size;
    public:
        Matrix() = delete;
        Matrix(size_t rows, size_t cols){
            _size = size;
            _vectors = new Vector<T>[rows];
            for(size_t i = 0; i< _size; i++){
                _vectors = Vector<T>(cols);
            }
        }

        ~Matrix{
            delete [] _vectors;
        }

        const Vector<T>& operator[](int index) const{
            return _vectors[index];
        }

        Vector<T>& operator[](int index){
            return _vectors[index];
        }

        friend std:: ostream& operator<<(std::ostream& os, const Matrix& matr){
            for(size_t i = 0; i < matr._size;i++){
                os << matr._vectors[i] << std::endl;
            }
            return os;
        }
};

// dz +,*,/,- ,нахождение обратной матрицы, транспонирование, определитель, рандомное заполнение 0-9
// задача со *, векторное тпроизведение векторов