#pragma once
#include <iostream>
#include <cmath>
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    size_t _count;// счетчик для добавления элемента чтобы не уйти за границы массива
public:
    ArrayHandler(size_t size) { 
        _size = size;
        _count = 0;
        _array = new T{_size};
    }

    ArrayHandler() { 
        _size = 5;
        _count = 0;
        _array = new T{_size};
    }


    void AppendElem(T elem) {
        
        if(_count == _size){ 
            T* array;
            array = new T[_size]; 
            
            for (size_t i = 0; i < _size; i++){
                array[i] = _array[i];
            }
            delete [] _array;
            _size++;
            _array = new T{_size};
            for (size_t i = 0; i < _size; i++){
                _array[i] = array[i];
            }
            _array[_count] = elem;
            delete [] array;
        }
        else{
            _array[_count] = elem;
            _count++;
        }
    }
    void pprint(){
        for(int i = 0; i < _size; i++){
            std::cout << _array[i] << " "; 
        }
        std::cout << std::endl;
    }

    bool IsContains(T elem) {
        for(size_t i = 0; i < _size; i++){
            if (_array[i] == elem){
                std::cout<<"tuta"<< std::endl;
                return true;
            }
        }
        std::cout<<" ne tuta" << std::endl;
        return false;
        
    }

    T GetMax() {
        T max;
        max = _array[0];
        for (size_t i = 1; i < _size; i++){
            if (max < _array[i]){
                max = _array[i];
            }
        }
        std::cout << "max is " << max << std::endl;
        return max;
    }

    T GetMin() {
        T min;
        min = _array[0];
        for (size_t i = 1; i < _size; i++){
            if (min > _array[i]){
                min = _array[i];
            }
        }
        std::cout << "min is " << min << std::endl;
        return min;
        
    }
    ArrayHandler& operator=(const ArrayHandler& tmp){
        _size = tmp._size;
        _count = tmp._count;
        for (int i = 0; i < _size; i++){
            _array[i] = tmp._array[i];
        }
        return *this;
    }
    ~ArrayHandler() {
        delete [] _array;
    }

};