#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#include <stdexcept>

template<typename T>
class Array{
private:
    T* array;
    unsigned int length;
public:
    Array(): array(nullptr), length(0) {}

    Array(unsigned int n): array(new T[n]()), length(n) {}

    Array(const Array& other): array(nullptr), length(0) {
        *this = other;
    }

    Array& operator=(const Array& other) { 
        if (this != &other) {
            if (array) {
                delete[] array;
            }
            length = other.length;
            array = new T[length];
            for (unsigned int i = 0; i < other.length; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    } 

    ~Array() {
        if (array) {
            delete[] array;
        }
    } 

    T& operator[](unsigned int index) { 
        if (index >= length) {
            throw std::out_of_range("Index is out of range");
        }
        return array[index];
    }

    unsigned int size() const { 
        return length;
    }
};


#endif