#pragma once
#include <iostream>


template<typename T>
class ArrayHandler
{
private:
    T* _array;
    size_t _size;//размер
    size_t _count; //счетчик
public:
    ArrayHandler(){
        _size = 10;
        _count = 0;
        _array = new T[_size];
    };
    void AppendElem(T elem){
        if (_count == _size){
            T* array = new T[_size * _size]; //для копирования ниже
            for(int i = 0; i < _size; i++){
                array[i] = _array[i];
            }
           
            delete [] _array;
            _size = _size * _size;//наперед увеличиваем
            _array = array;
        }
        
        _array[_count++] = elem; //каунт увеличится после использования

    };
    bool IsContains(const T& elem) const {
        for(size_t i = 0; i < _count; i++){
            if(elem == _array[i]){
                return true;
            }
        }
        return false;
    };
    T GetMax(){
        T max = _array[0];
        for(size_t i = 1; i < _count; i++)
        {
            if (_array[i] > max) {
                max = _array[i];
            }
        }
        return max;
    };

    T GetMin(){
        T min = _array[0];
        for(size_t i = 1; i < _count; i++)
        {
            if (_array[i] < min) {
                min = _array[i];
            }
        }
        return min;
    };
    ~ArrayHandler(){
        delete [] _array;
    };
};
