#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class A{
private:
    T* array;
public:
    A(): array(new T[]()) {} //creates an empty array
    A(unsigned int n): array(new T[n]()) {} //creates an array of n elements initialized by default
    A(const A& other):A() { *this = other; }
    A& operator=(const A& other) { if (this != &other) } //how should I do this?
    T& operator[](T elem) { return array[elem]; } //not sure if what I did here is correct
    size_t size() const { return sizeof(*array)/sizeof(array[0]); } //is this correct? *array?
};


#endif