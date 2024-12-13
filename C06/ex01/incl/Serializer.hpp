#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>
#include <iostream>

typedef struct Data_s{
    int x;
    int y;
    char c;
    bool b;

} Data;

class Serializer{
private:
    Serializer() = default;
    Serializer(const Serializer& other) = delete;
    Serializer& operator=(const Serializer& other) = delete;
    ~Serializer() = default;

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif