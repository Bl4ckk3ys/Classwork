template<typename T>
class Vector{
    private:
        T* _array;
        size_t _size;

    public:
        Vector() = delete;
        Vector(size_t size, T* array){
            _array = new T[size];
            for(int i = 0; i< _size;i++)
                _array[i]=0;
        }
        Vector(std::initializer_list<T> list){
            _size = list.size();
            _array = new T[_size];
            int i = 0;
            for(auto elem = list.begin(); elem != list.end(); elem++, i++){
                _array[i] = *elem;
            }    
        }
        ~Vector(){
            delete [] _array;
        }

        T& operator[](int i) const{
             return _array[i];
        }

       
// dz + * вычисление длины и нормализация
};